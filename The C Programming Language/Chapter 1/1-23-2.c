/*
 * Author : weiwenbo
 * Email  : weshpolo@live.com
 * Date	  : 2014/1/24
 */
#include <stdio.h>
#define OPEN	0
#define CLOSE	1

int main()
{
	int c, s_quotes = CLOSE, d_quotes = CLOSE, coment = CLOSE, lastc;

	while ((c = getchar()) != EOF) {
		if (coment == OPEN) {
		    if (c == '/' && lastc == '*') {
				coment = CLOSE;
				lastc = EOF;
				continue;
		    }
		} else if (c == '/') {
			if (lastc == '/') {
				putchar('/');
			}															
		} else if (c == '*') {
			if (s_quotes == CLOSE && d_quotes == CLOSE && lastc == '/')
				coment = OPEN;
			else
				putchar(c);
		} else {
			if (lastc == '/')
				putchar('/');
			putchar(c);

			if (c == '\\') {
				if (lastc == '\\') {
					lastc = EOF;
					continue;
				}
			} else if (c == '\'' && d_quotes == CLOSE && lastc != '\\') {
				s_quotes = !s_quotes;
			} else if (c == '\"' && s_quotes == CLOSE && lastc != '\\') {
				d_quotes = !d_quotes;
			}
		}
		lastc = c;
	}
	return 0;
}