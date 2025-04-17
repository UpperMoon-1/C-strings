/**
 * -------------------------------------
 * @file  myword.c
 * file description
 * -------------------------------------
 * @author Giuseppe Akbari, 169057752, akba7752@mylaurier.ca
 *
 * @version 2025-01-25
 *
 * -------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "myword.h"

#define MAX_LINE_LEN 1000
#define MAX_WORDS 1000

/*
 * Load word data from file, and insert words a directory represented by char array.
 *
 * @param  FILE *fp -   file pointer to an opened text file
 * @param *dictionary - char pointer to a char array where dictionary words are stored.
 *                      It's up to your design on how to store words in the char array.
 * @return - the number of words added into the dictionary.
 */
int create_dictionary(FILE *fp, char *dictionnary) {
	char line[1000];
	char delimiters[] = ".,\n\t\r";
	char *token;
	int count;
	count = 0;
	while (fgets(line, 1000, fp) != NULL) {
		//count++;
		//str_words(token);
		str_lower(line);
		str_trim(line);
		token = (char*) strtok(line, delimiters);
		while (token != NULL) {
			count++;
			if (*dictionnary == '\0')
				strcat(dictionnary, ",");
			strcat(dictionnary, token);
			strcat(dictionnary, ",");
			token = (char*) strtok(NULL, delimiters);
		}

	}
	fclose(fp);

	return count;
}

/*
 * Determine if a given word is contained in the given dictionary.
 *
 * @param *dictionary -  char pointer to a char array of given dictionary.
 * @param *word  -  pointer to a given word.
 *
 * @return - TRUE if the word is in the dictionary, FALSE otherwise.
 */
BOOLEAN contain_word(char *dictionary, char *word) {
	BOOLEAN con = FALSE;
	if (word == NULL || *word == '\0') {
		return con;
	} else {
		char temp[20] = { 0 };
		strcat(temp, ",");
		strcat(temp, word);
		strcat(temp, ",");
		if (strstr(dictionary, temp) != NULL) {
			con = TRUE;
		} else {
			con = FALSE;
		}
	}
	return con;

}

/*
 * Process text data from a file for word statistic information of line count, word count, keyword count, and frequency of keyword.
 *
 * @param *fp -  FILE pointer of input text data file. .
 * @param *words  -  WORD array for keywords and their frequencies.
 * @param *dictionary  -  stop-word/common-word dictionary.
 *
 * @return - WORDSTATS value of processed word stats information.
 */
WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary) {
	WORDSTATS ws = { 0 };
	char line[1000];
	char *word_token;
	char delimiters[] = " .,\n\t\r";
	while (fgets(line, MAX_LINE_LEN, fp) != NULL) {	//going through all the lines
		ws.line_count++;
		str_lower(line);
		//str_trim(line);
		word_token = (char*) strtok(line, delimiters);//get the first word of the line
		while (word_token != NULL) {
			ws.word_count++;
			if (contain_word(dictionary, word_token) != FALSE) {
				int j = 0;
				while (j < ws.keyword_count
						&& strcmp(word_token, words[j].word) != 0) {
					j++;
				}
				if (j < ws.keyword_count) {
					words[j].count++;
					ws.word_count++;
				} else {
					strcpy(words[j].word, word_token);
					words[j].count = 1;
					ws.keyword_count++;
				}
			}
			word_token = (char*) strtok(NULL, delimiters);
		}

	}
	fclose(fp);
	return ws;

}

