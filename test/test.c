#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	run()
{
	// char *f = "one_line_no_nl.txt";
	// char *f = "1char.txt";
	// char *f = "only_nl.txt";
	// char *f = "41_with_nl";
	// char *f = "multiple_nl.txt";
	// char *f = "variable_nls.txt";
	// char *f = "limits2.txt";
	// char *f = "giant_line.txt";
	char *f = "read_error.txt";
	
	int fd = open(f, O_RDONLY);

	char *str = get_next_line(fd);
	// printf(">%s<, len=%zu\n", str, ft_strlen(str));
	printf("%s", str); 
	if (str)
		free(str);
	str = get_next_line(fd);
	printf("%s", str);
	if (str)
		free(str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// if (str)
	// 	free(str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// if (str)
	// 	free(str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// if (str)
	// 	free(str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);


	// str = get_next_line(fd);
	// printf("%s", str);

	// printf(">%s<, len=%zu\n", str, ft_strlen(str));
	close(fd);
}

int	main(void)
{
	run();
	return (0);
}