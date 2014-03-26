#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim);
void copy(char to[], char from[]);

int main()
{
	int c, len, max = 0;
	char longest[MAXLINE], line[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0) {
		printf("%d, %s", len, line);

		if (len > max) {
			max = len;
			copy(longest, line);
		}

		if (max > 0) 
			printf("%s", longest);
	}

	return 0;
}

int getline(char s[], int lim) {
	int c, i, j;
	for (i = j = 0; (c= getchar()) != EOF && c != '\n'; i++) {
		if (i < lim - 2) {
			s[j++] = c;
		}
	}

	if (c == '\n') {
		s[j++] = '\n';
		++i;
	}

	s[j] = '\0';

	return i;

}

void copy(char to[], char from[]) {
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}