#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void	print_board(int *board, int size) {
	for (int i = 0; i < size; ++i)
		printf("%d ", board[i]);

	printf("\n");

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (i == board[j]) printf("♛ ");
			else printf("\033[1;30m□ \033[0m");
		}
		printf("\n");
	}
	printf("\n");
}

bool	is_pos_valid(int *board, int col) {
	for (int i = 0; i < col; ++i) {
		if (board[i] == board[col])
			return (false);
		if (board[i] == (board[col] - (col - i)))
			return (false);
		if (board[i] == (board[col] + (col - i)))
			return (false);
	}
	return (true);
}

void	solve(int *board, int size, int col) {
	if (col >= size)
		return (print_board(board, size));

	for (int i = 0; i < size; ++i) {
		board[col] = i;
		if (is_pos_valid(board, col))
			solve(board, size, (col + 1));
	}
}

int main(int argc, char **argv) {
	int	n;

	if (argc != 2) return (EXIT_SUCCESS);

	n = atoi(argv[1]);

	if (n == 0) return (EXIT_FAILURE);

	int board[n];

	return (solve(board, n, 0), EXIT_SUCCESS);
}
