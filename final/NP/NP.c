#include <stdio.h>
#include <math.h>

int main() {
	unsigned long long T;
	scanf("%d", &T);

	int B[T], M[T];
	int A[T], N[T];

	for (int i=0; i<T; i++) {
	  scanf("%d %d %d %d", &A[i], &B[i], &N[i], &M[i]);
	}

	for (int i=0; i<T; i++) {
		unsigned long long amount = 0;

		for (int j = 0; j < N[i] - 1; j++) {
            unsigned long long temp = pow(A[i], j) * pow(j, B[i]);
		    amount += temp;
		}

		int T = amount % M[i];
		printf("%d\n", T);
	}
}
