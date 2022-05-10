#include <string.h>
#include <ctype.h>
#include "main.h"

/**
 * find_word_count - finds how many words are in the current line
 *
 * @line: the line to search for words
 *
 * Return: number of words in line
 */
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
		if (is_typed_char(line[i]) == 0)
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

/**
 * get_next_word - moves pointer to next word in string
 *
 * @str: string to move to next word
 *
 * Return: pointer to next word in string
 */
char *get_next_word(char *str)
{
	int pending = 0;
	int i = 0;

	while (*(str + i) != '\0')
	{
		if (is_typed_char(str[i]) == 0)
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}

/**
 * curr_word_size - finds the size of the current word
 *
 * @line: the string to find the size of the word
 *
 * Return: length in characters of word.
 */
int curr_word_size(char *line)
{
	int wLen = 0, pending = 1, i = 0;

	while (*(line + i))
	{
		if (is_typed_char(line[i]) == 0)
		{
			pending = 1;
		}
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_typed_char(line[i]) == 0)
			break;
		i++;
	}
	return (wLen);
}
/**
 * is_typed_char - determains if the character is typed or special
 *
 * @c: the char to determain.
 *
 * Return: 1 for typed char, 0 for special char
 */
int is_typed_char(int c)
{
	if (c < 33 || c > 126)
		return (0);

	return (1);
}

/**
 * find_tokens - splits the current line into individual tokens
 *
 * @line: the line to find the tokens of
 *
 * Return: void, stores tokens in global variable.
 */
void find_tokens(char *line)
{
	int wordCount, tokenNum = 0, currWordSize = 0;
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
		if (is_typed_char(*line) == 0)
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
