#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int ac, char **av)
{
	(void)ac;
	char buffer[] = "I,am,ahmed,essalhi";
	const char s[] = " ";
	char *str;

	int i = 0;
	
	//printf("$ ");

	str = strtok(buffer, ",");
	printf("[ ");	
	while(str != NULL)
	{
		printf("%s, ", str);
		str = strtok(NULL, ",");
	}
	printf("]\n");

	return 0;
}
