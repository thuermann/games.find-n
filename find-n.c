/*
 * $Id: find-n.c,v 1.3 2017/10/18 06:47:56 urs Exp $
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

static void usage(const char *name)
{
	fprintf(stderr, "Usage: %s number\n", name);
}

static void find(unsigned long long n);
static int check(unsigned long long m, unsigned long long n);

int main(int argc, char **argv)
{
	const unsigned long long maxn = ULLONG_MAX / 2 + 1;
	unsigned long long n;

	if (argc != 2) {
		usage(argv[0]);
		exit(1);
	}

	n = strtoull(argv[1], NULL, 0);
	if (n > maxn) {
		fprintf(stderr, "Maximum number allowed is %llu\n", maxn);
		exit(1);
	}

	find(n);

	return 0;
}

static void find(unsigned long long n)
{
	unsigned long long a, b, m = 1;
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

static int check(unsigned long long m, unsigned long long n)
{
	int c = m == n ? 0 : (m < n ? -1 : 1);

	printf("%20llu %+d\n", m, c);

	return c;
}
