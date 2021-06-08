#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int ac, char **av) {
	int sum = 0;
	int min = atoi(av[1]);
	int max = atoi(av[2]);
	for (int i = min; i <= max; i++) {
		sum += (i / 2);
		printf("SUM + %d = %d\n", i / 2, sum);
	}
	printf("SUM: %d\n", sum);
	return (0);
}