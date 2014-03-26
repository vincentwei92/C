#include <stdio.h>
#define MAXCOL	25
#define TABINC	8

void printl(char line[], int pos);
int findblnk(char line[], int pos);
int newpos(char line[], int pos);

int main()
{
	int c, pos = 0;
	char line[MAXCOL];

	while ((c = getchar()) != EOF) {
		line[pos] = c;
		if (c == '\t') {
			while (pos < MAXCOL && pos % TABINC != 0) {
				line[pos++] = ' ';				
			}
			if (pos >= MAXCOL) {
				printl(line, pos);
				pos = 0;
			}
		} else if (c == '\n') {
			printl(line, pos);
			pos = 0;
		} else if (++pos >= MAXCOL) {
			pos = findblnk(line, pos);
			printl(line, pos);
			pos = newpos(line, pos);
		}
	}

	return 0;
}

void printl(char line[], int pos) {
	int i;
	for (i = 0; i < pos; i++) {
		putchar(line[i]);
	}
	if (pos > 0) 
		putchar('\n');
}

int findblnk(char line[], int pos) {
	while (pos > 0 && line[pos] != ' ') 
		--pos;
	if (pos == 0) {
		return MAXCOL;
	} else {
		return ++pos;
	}
}

int newpos(char line[], int pos) {
	int i, j;
	if (pos <= 0 || pos >= MAXCOL) 
		return 0;
	else {
		i = 0;
		for (j = pos; j < MAXCOL; j++) {
			line[i] = line[j];
			++i;
		}
		return i;
	}
} 