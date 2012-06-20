/*
 * $Id: find-n.c,v 1.1 2012/06/20 10:25:16 urs Exp $
 */

#include <stdlib.h>
#include <stdio.h>

static void usage(const char *name)
{
	fprintf(stderr, "Usage: %s number\n", name);
}

static void find(int n);
static int check(int m, int n);

int main(int argc, char **argv)
{
	int n;

	if (argc != 2) {
		usage(argv[0]);
		exit(1);
	}

	n = atoi(argv[1]);

	find(n);

	return 0;
}

static void find(int n)
{
	int a, b, m = 1;
	int c;

	while ((c = check(m, n)) < 0)
		m *= 2;

	if (c == 0)
		return;

	a = m / 2, b = m;

	while (m = (a + b) / 2, (c = check(m, n)) != 0)
		if (c < 0)
			a = m;
		else
			b = m;
}

static int check(int m, int n)
{
	int c = m == n ? 0 : (m < n ? -1 : 1);

	printf("%10d %+d\n", m, c);

	return c;
}
