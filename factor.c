#define _POSIX_C_SOURCE 200809L 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>


int factorize_func(char *buffer)
{
	uint32_t num_convert,  i;
	

	num_convert = atoi(buffer);


	for (i = 2; i < num_convert; i++)
	{
		if (num_convert % i == 0)
		{
			printf("%d=%d*%d\n",num_convert,num_convert/i,i);
			break;
		}
	}

return (0);
}
/**
 * main - main 
 *
 * Return: void
 */

int main(int argc, char *argv[])
{
	FILE *file_name;
	size_t count;
	ssize_t line;
	char *buffer = NULL;


	if (argc != 2)
	{
		fprintf(stderr, "Usage: factor <filename>\n");
		exit(EXIT_FAILURE);
	}
	file_name = fopen(argv[1], "r");
	if (file_name == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while((line = getline(&buffer, &count, file_name)) != -1)
	{
		factorize_func(buffer);
	}
return (0);
}