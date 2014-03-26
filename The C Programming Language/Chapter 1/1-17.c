#include <stdio.h>
#define MAXLINE 1000
#define MINLINE 5

int getline(char s[], int lim);

int main() 
{
	int len;
	char line[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0) {
		if (len > MINLINE)
			printf("%s\n", line);
	}
	return 0;
}

int getline(char s[], int lim) {
	int c, i, j;

	for (i = j = 0; (c = getchar()) != EOF && c != '\n'; i++) {
		if (i < lim-2) {
			s[j++] = c;
		}
	}

	if (c == '\n') {
		s[j++] = c;
		++i;
	}

	s[j] = '\0';
	return i;
}