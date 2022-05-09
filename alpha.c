#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

char **tokens = NULL;

int find_word_count(char *line)
{
	int i = 0;
	int lastChar = 0;
	int wc = 0;
	if (line == NULL)
	{
		return (wc);
	}
	while (line[i] != '\0')
	{
		if (isalpha(line[i]) == 0 && isdigit(line[i]) == 0)
		{
			if (lastChar == 1)
				wc++;
			lastChar = 0;
		}
		else
			lastChar = 1;
		i++;
	}
	if (lastChar == 1)
		wc++;
	return (wc);
}

char *get_next_word(char *str)
{
	int pending = 0;
	int i = 0;
	while (*(str + i) != '\0')
	{
		if (isalpha(str[i]) == 0 && isdigit(str[i]) == 0)
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
int curr_word_size(char *line)
{
	int wLen = 0, pending = 1, i = 0;
	while (*(line + i))
	{
		if (isalpha(line[i]) == 0 && isdigit(line[i]) == 0)
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && isalpha(line[i]) == 0 && isdigit(line[i]) == 0)
			break;
		i++;
	}
	return (wLen);
}

void find_tokens(char *line)
{
	int wordCount;
	int tokenNum = 0;
	int currWordSize = 0;
	int n = 0;

	if (line == NULL || !*line)
		return;
	wordCount = find_word_count(line);
	if (wordCount == 0)
		return;
	tokens = malloc((wordCount + 1) * sizeof(char *));
	if (tokens == NULL)
		return;

	for (; tokenNum < wordCount; tokenNum++)
	{
		currWordSize = curr_word_size(line);
		if (isalpha(*line) == 0 && isdigit(*line) == 0)
		{
			line = get_next_word(line);
		}
		tokens[tokenNum] = malloc((currWordSize + 1) * sizeof(char));
		if (tokens[tokenNum] == NULL)
		{
			while (tokenNum >= 0)
			{
				tokenNum--;
				free(tokens[tokenNum]);
			}
			free(tokens);
			return;
		}
		n = 0;
		while (n < currWordSize)
		{
			tokens[tokenNum][n] = *(line + n);
			n++;
		}
		tokens[tokenNum][n] = '\0';
		line = get_next_word(line);
	}
	tokens[tokenNum] = NULL;
}

void free_tokens()
{
	int i = 0;

	if (tokens == NULL)
		return;

	while(tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
	tokens = NULL;
}

void print_tokens()
{
	int i = 0;

	if (tokens == NULL)
		return;

	for (; tokens[i]; i++)
		printf("token[%d] = %s\n", i, tokens[i]);
}

int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;
	char *line = NULL;
	size_t len = 0;
	int wc = 0;
	int lineCount = 0;
	if (argc != 2)
	{
		fprintf(stderr, "usage: a.out [test file]\n");
		return (EXIT_FAILURE);
	}
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (EXIT_FAILURE);
	exit_code = 1;
	while (getline(&line, &len, script_fd) != -1)
	{
		if (line[0] != '\n')
			line = strtok(line, "\n");
		find_tokens(line);
		lineCount++;
		print_tokens();
		free_tokens();
	}
	free(line);
	line = NULL;
	len = 0;
	fclose(script_fd);
	return (exit_code);
}
