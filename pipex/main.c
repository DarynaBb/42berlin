#include "pipex.h"

// int	open_input_file(char *filename)
// {
// 	int infile = open(filename, O_RDONLY);
// 	if (infile < 0)
// 	{
// 		perror("Warning: Cannot open input file (using empty input)");
// 		return (open("/dev/null", O_RDONLY));
// 	}
// 	return infile;
// }
int	open_input_file(char *filename)
{
	int infile = open(filename, O_RDONLY);
	if (infile < 0)
	{
		perror("Warning: Cannot open input file (using empty input)");
		infile = open("/dev/null", O_RDONLY);  // Використовуємо порожній вхід
		if (infile < 0)
			handle_error("Error: Cannot open /dev/null");
	}
	return infile;
}

int	open_output_file(char *filename)
{
	int outputfile = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outputfile < 0)
		handle_error("Error opening output file");
	return outputfile;
}

void	child_process(int n_process, int infile, int outfile, char **argv, char **envp, int *fd)
{
	if (n_process == 1)
	{
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
	}
	close(fd[0]);
	close(fd[1]);
	if (n_process == 1)
		execute_command(argv[2], envp);

	else
		execute_command(argv[3], envp);
}

void	parent_process(int *fd, pid_t pid1, pid_t pid2, int infile, int outfile, int *exit_status)
{
	int	status1;
	int	status2;

	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	close(infile);
	close(outfile);
	if (WIFEXITED(status2))
		*exit_status = WEXITSTATUS(status2);
	else
		*exit_status = 1;
}

int main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;
	int		exit_status = 0;

	validate_args(argc);
	if (pipe(fd) < 0)
		handle_error("Pipe");
	infile = open_input_file(argv[1]);
	outfile = open_output_file(argv[4]);
	pid1 = fork();
	if (pid1 < 0) handle_error("Failed to fork");
	if (pid1 == 0)
		child_process(1, infile, outfile, argv, envp, fd);
	pid2 = fork();
	if (pid2 < 0)
		handle_error("Failed to fork");
	if (pid2 == 0)
		child_process(2, infile, outfile, argv, envp, fd);
	parent_process(fd, pid1, pid2, infile, outfile, &exit_status);
	return exit_status;
}

// int     pipefd[2];
//     pid_t   pid1, pid2;
//     int     in_file, out_file;

//     // Validate arguments first
//     validate_args(argc, argv); // If validation fails, exit with error

//     // Open the input and output files
//     in_file = open(argv[1], O_RDONLY);
//     if (in_file < 0)
//     {
//         perror("Input file");
//         return (1);
//     }

//     out_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (out_file < 0)
//     {
//         perror("Output file");
//         return (1);
//     }

//     // Create the pipe
//     if (pipe(pipefd) == -1)
//     {
//         perror("Pipe");
//         return (1);
//     }

//     // Fork the first child to execute cmd1
//     pid1 = fork();
//     if (pid1 == 0)
//     {
//         // Child 1 (cmd1)
//         dup2(in_file, STDIN_FILENO);  // Redirect stdin to input file
//         dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to pipe

//         close(pipefd[0]); // Close read end of the pipe
//         close(pipefd[1]); // Close write end of the pipe

//         execute_command(argv[2], envp); // Execute cmd1
//     }

//     // Fork the second child to execute cmd2
//     pid2 = fork();
//     if (pid2 == 0)
//     {
//         // Child 2 (cmd2)
//         dup2(pipefd[0], STDIN_FILENO);  // Redirect stdin to pipe
//         dup2(out_file, STDOUT_FILENO);   // Redirect stdout to output file

//         close(pipefd[0]); // Close read end of the pipe
//         close(pipefd[1]); // Close write end of the pipe

//         execute_command(argv[3], envp); // Execute cmd2
//     }

//     // Parent process
//     close(pipefd[0]); // Close both ends of the pipe in the parent
//     close(pipefd[1]);

//     waitpid(pid1, NULL, 0); // Wait for the first child
//     waitpid(pid2, NULL, 0); // Wait for the second child

//     close(in_file); // Close input file
//     close(out_file); // Close output file

//     return (0);
// }