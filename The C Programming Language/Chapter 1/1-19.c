#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim);
void reverse(char s[]);

int main()
{
	char line[MAXLINE];

	while (getline(line, MAXLINE) > 0) {
		reverse(line);
		printf("%s", line);
	}

	return 0;
}

void reverse(char s[]) {
	int temp, i, j;
	i = j = 0;
	while (s[j] != '\0')
		++j;
	if (s[--j] == '\n')
		--j;
	while (j > i) {
		temp = s[i];
		s[i++] = s[j];
		s[j--] = temp;
	}
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