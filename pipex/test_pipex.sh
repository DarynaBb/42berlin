#!/bin/bash

# Function to create an infile with numbers from 0 to 100 (each on a new line)
infile() {
	seq 0 100 > infile.in
	echo "✅ Created 'infile.in' with numbers 0 to 100."
}

# Function to create a file `no_access` with no permissions (chmod 000)
no_access() {
	touch no_access
	chmod 000 no_access
	echo "✅ Created 'no_access' with no permissions."
}

clean() {
	rm -f *.in *.out no_access
}

# Function to run pipex and compare output with the shell's behavior
run() {
	INFILE="infile.in"
	OUTFILE="outfile.out"
	STD_OUTFILE="std_outfile.out"

	infile

	# Parse -i and -o options
	while [[ "$1" == -* ]]; do
		case "$1" in
			-i) shift; INFILE="$1";;
			-o) shift; OUTFILE="$1"; STD_OUTFILE="$1";;
			*) echo "❌ Unknown option: $1"; return 1;;
		esac
		shift
	done

	if [ $# -lt 1 ]; then
		echo "❌ Usage: $0 run [-i infile] [-o outfile] \"cmd1\" \"cmd2\""
		return 1
	fi

	# Construct command for pipex
	echo "▶ Running: ./pipex $INFILE \"$1\" \"$2\" $OUTFILE"
	./pipex "$INFILE" "$@" "$OUTFILE"
	PIPEX_EXIT_STATUS=$?

	# Construct equivalent shell command
	echo "▶ Running: < $INFILE $1 | $2 > $STD_OUTFILE"
	< "$INFILE" $1 | $2 > "$STD_OUTFILE"
	SHELL_EXIT_STATUS=$?

	# Compare results
	if [[ -f "$OUTFILE" && -f "$STD_OUTFILE" ]]; then
		chmod 644 "$OUTFILE"
		chmod 644 "$STD_OUTFILE"
		if diff "$OUTFILE" "$STD_OUTFILE" > /dev/null; then
			echo "✅ Output matches!"
		else
			echo "❌ Output differs!"
			diff "$OUTFILE" "$STD_OUTFILE"
		fi
	fi

	# Compare exit statuses
	if [ "$PIPEX_EXIT_STATUS" -eq "$SHELL_EXIT_STATUS" ]; then
		echo "✅ Exit status matches! (Status: $PIPEX_EXIT_STATUS)"
	else
		echo "❌ Exit status differs! (pipex: $PIPEX_EXIT_STATUS, shell: $SHELL_EXIT_STATUS)"
	fi

	clean
}

# Function to run the bonus version of pipex
run_bonus() {
	INFILE="infile.in"
	OUTFILE="outfile.out"
	STD_OUTFILE="std_outfile.out"

	infile  # Ensure infile exists

	# Parse -i and -o options
	while [[ "$1" == -* ]]; do
		case "$1" in
			-i) shift; INFILE="$1";;
			-o) shift; OUTFILE="$1"; STD_OUTFILE="$1";;
			*) echo "❌ Unknown option: $1"; return 1;;
		esac
		shift
	done

	# Ensure at least two commands are provided
	if [ $# -lt 2 ]; then
		echo "❌ Usage: $0 run_bonus [-i infile] [-o outfile] \"cmd1\" \"cmd2\" [\"cmd3\" ...]"
		return 1
	fi

	# Construct command for pipex_bonus
	echo -n "▶ Running: ./pipex_bonus \"$INFILE\""
	PIPEX_CMD=( "./pipex_bonus" "$INFILE" )  # Store command in an array
	for cmd in "$@"; do
		PIPEX_CMD+=( "$cmd" )  # Each command is a separate argument
		echo -n " \"$cmd\""
	done
	PIPEX_CMD+=( "$OUTFILE" )
	echo " \"$OUTFILE\""

	# Run pipex_bonus correctly
	"${PIPEX_CMD[@]}"
	PIPEX_EXIT_STATUS=$?

	# Construct equivalent shell command
	echo -n "▶ Running: < \"$INFILE\" $1"
	SHELL_CMD="< \"$INFILE\" $1"  # Start with the first command after input redirection
	shift  # Remove first command from list

	for cmd in "$@"; do
		SHELL_CMD+=" | $cmd"  # Append remaining commands with pipes
		echo -n " | $cmd"
	done
	SHELL_CMD+=" > \"$STD_OUTFILE\""
	echo " > \"$STD_OUTFILE\""

	eval "$SHELL_CMD"
	SHELL_EXIT_STATUS=$?

	# Compare results only if files exist
	if [[ -f "$OUTFILE" && -f "$STD_OUTFILE" ]]; then
		chmod 644 "$OUTFILE"
		chmod 644 "$STD_OUTFILE"
		if diff "$OUTFILE" "$STD_OUTFILE" > /dev/null; then
			echo "✅ Output matches!"
		else
			echo "❌ Output differs!"
			diff "$OUTFILE" "$STD_OUTFILE"
		fi
	fi

	# Compare exit statuses
	if [ "$PIPEX_EXIT_STATUS" -eq "$SHELL_EXIT_STATUS" ]; then
		echo "✅ Exit status matches! (Status: $PIPEX_EXIT_STATUS)"
	else
		echo "❌ Exit status differs! (pipex: $PIPEX_EXIT_STATUS, shell: $SHELL_EXIT_STATUS)"
	fi

	clean
}

# Main script logic
case "$1" in
	infile) infile ;;
	no_access) no_access ;;
	run) shift; run "$@" ;;
	run_bonus) shift; run_bonus "$@" ;;
	*)
		echo "Usage: $0 {infile|no_access|run|run_bonus} [commands...]"
		exit 1
		;;
esac