#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1001

int main() {
	int n;
	int summ = 0;
	int i = 0;
	char a, s[N];
	scanf("%d", &n);
	FILE* input;
	FILE* output;
	clock_t start, end;
	start = clock();
	input = fopen("input.txt", "r");
	while (!feof(input)) {
		fscanf(input, "%c", &a);
		if (a == '1') {
			summ += 1;
		}
		if (a == '\n') {
			if (summ == n) {
				s[i] = '1';
			}
			summ = 0;
			i++;
		}
	}
	if (summ == n) {
		s[i] = '1';
	}
	fclose(input);
	output = fopen("output.txt", "w");
	for (int j = 0; j <= N; j++) {
		if (s[j] == '1') {
			fprintf(output, "%d ", j + 1);
		}
	}
	fprintf(output, "\n");
	end = clock();
	fprintf(output, "time %.5f ms.\n", difftime(end, start) / (CLOCKS_PER_SEC));
	fclose(output);
	return 0;
}