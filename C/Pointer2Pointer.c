#include<stdio.h>

void printGraph(char **text, int lines);
main()
{
	char* text[] = {
		"abc", "def", "hijk" 
	};
	printGraph(text, 3);
	return 0;
}

void printGraph(char **t, int lines)
{
	int i = 0;
	while(i < lines)
	{
		printf("%s\n", *t);
		i++;
		t++;
	}
}
