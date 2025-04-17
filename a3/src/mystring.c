/**
 * -------------------------------------
 * @file  mystring.c
 * file description
 * -------------------------------------
 * @author Giuseppe Akbari, 169057752, akba7752@mylaurier.ca
 *
 * @version 2025-01-25
 *
 * -------------------------------------
 */
#include "mystring.h"

/**
 * Count the number words of given simple string. A word starts with an English charactor end with a charactor of space, tab, comma, or period.
 *
 * @param s - char pointer to a string
 * @return - return the number of words.
 */
int str_words(char *s) {

	int count;
	count = 0;

	int where;
	where = 0;

	char *p = s;

	while (*p) {

		if ((where == 0)
				&& ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'))) {
			count++;

		} else if ((where != 0) && (*(p - 1) == ' ')
				&& ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'))) {

			count++;

		}
		where++;
		p++;

	}
	return count;
}

/**
 * Change every upper case English letter to its lower case of string passed by s
 *
 * @param s - char pointer to a string
 * @return - return the number of actual flips.
 */
int str_lower(char *s) {
	int count;
	count = 0;

	char *p = s;

	while (*p) {
		if (*p >= 'A' && *p <= 'Z') {
			count++;
			*p += 32;
		}
		p++;
	}

	return count;
}

/**
 * Remove unnecessary space characters in a simple string passed by `s`
 *
 * @param s - char pointer to a string
 */
void str_trim(char *s) {
	char *p = s;
	char *dp = s;

	while (*p) {
		if (*p != ' ' || (p > s && *(p - 1) != ' ')) {
			*dp = *p;
			dp++;
		}
		p++;
	}
	if (*(p - 1) != ' ') {
		*dp = '\n';
	} else {
		*(dp - 1) = '\0';
	}

	return;
}
