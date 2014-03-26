#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim);
int remov(char s[]);

int main()
{
	char line[MAXLINE];              /* current input line */

	while (getline(line, MAXLINE) > 0) {
		if (remov(line) > 0) 
			printf("%s", line);
	}
	
	return 0;
}

/* remove trailing blanks and tabs from characters strings s */

int remov(char s[]) {
	int i = 0;

	while (s[i] != '\n') 		/* find newline characters  */
		++i;
	--i;						/* back off from '\n'	    */

	while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
		--i;

	if (i >= 0) {
		s[++i] = '\n';
		s[++i] = '\0';
	}

	return i;
}

int getline(char s[], int lim) {
	int c, i, j;
	for (i = j = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < lim - 2)
			s[j++] = c;
	} 

	if (c == '\n') {
		s[j++] = c;
		++i;
	}

	s[j] = '\0';

	return i;
}