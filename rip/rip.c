#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int	count_required_replacements(const char *s, int s_len) {
	int		count = s_len, i = 0;
	bool	is_enclosed = false;

	while (s[i]) {
		!is_enclosed ? is_enclosed = s[i] == '(' : false;
		if (is_enclosed && s[i] == ')') {
			is_enclosed = false;
			count -= 2;
		}
		if (s[i] == ' ')
			count--;
		i++;
	}
	return (count);
}

void	print_options(char *s, int index, int replacements_count, int end) {
	char	temp;

	if (index > end) return;

	if (count_required_replacements(s, end) == 0) return ((void)puts(s));

	print_options(s, (index + 1), replacements_count, end);

	if (replacements_count == 0) return;

	temp = s[index];
	s[index] = ' ';
	print_options(s, (index + 1), (replacements_count - 1), end);
	s[index] = temp;
}

int main(int argc, char **argv) {
	int		required_replacements_count;
	int		s_len;

	if (argc != 2) return (EXIT_SUCCESS);

	s_len = (int)strlen(argv[1]);
	required_replacements_count = count_required_replacements(argv[1], s_len);

	if (required_replacements_count == 0) return (EXIT_SUCCESS);

	print_options(argv[1], 0, required_replacements_count, s_len);
	return (EXIT_SUCCESS);
}
