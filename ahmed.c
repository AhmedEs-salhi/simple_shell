#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char **split_string(char *str)
{
	char *token, **fullToken = NULL;
	int cpt = 0;

	token = strtok(str, " \t\n");
	while(token != NULL)
	{
		cpt++;
		fullToken = realloc(fullToken, cpt * sizeof(char *));
		if (fullToken == NULL)
		{
			perror("realloc problem\n");
			exit(EXIT_FAILURE);
		}
		fullToken[cpt - 1] = token;
		token = strtok(NULL, " \t\n");
	}

	for (cpt = 0; fullToken[cpt]; cpt++)
		printf("%s\n", fullToken[cpt]);

	return (fullToken);
}

int main(int arc, char **arv)
{
	(void)arv;
	(void)arc;

	char *buffer = NULL;
	size_t bufferSize = 0;
	char **array;
	int nchar;
	write(1, "$ ", 2);
	nchar = getline(&buffer, &bufferSize, stdin);
	if (nchar == -1)
	{
		perror("getline problem\n");
		exit(EXIT_FAILURE);
	}
	buffer[nchar - 1] = '\0';
	array = split_string(buffer);

	return 0;
}
