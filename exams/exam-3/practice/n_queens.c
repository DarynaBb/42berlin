#include <stdio.h>
#include <stdlib.h>

void print_solution(int *board, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", board[i]);
		if (i < n - 1)
			printf(" ");
	}
	printf("\n");
}

int is_safe(int *board, int col, int row)
{
	for (int i = 0; i < col; i++)
	{
		if (board[i] == row)
			return 0;
		if (board[i] - i == row - col)
			return 0;
		if (board[i] + i == row+col)
			return 0;
	}
	return 1;
}

void backtrack(int *board, int col, int n)
{
	if (col == n)
	{
		print_solution(board, n);
		return;
	}
	for (int row = 0; row < n; row++)
	{
		if (is_safe(board, col, row))
		{
			board[col] = row;
			backtrack(board, col+1, n);
		}
	}
}

void solve(int n)
{
	int board[n];
	for (int i = 0; i < n; i++)
		board[i] = -1;
	backtrack(board, 0, n);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	int n = atoi(argv[1]);
	if (n == 0)
		return 0;
	solve(n);
	return 0;
}

