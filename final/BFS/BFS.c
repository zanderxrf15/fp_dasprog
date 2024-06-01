#include <stdio.h>
#include <math.h>

const int dimension = 32;

void flipright(int numbers, int bits[]) {
    if (numbers > 0) {
        int loc = dimension - numbers;
        bits[loc] ^= 1;
    }
}

void solve(unsigned int numbers, int bits[])
{
    int loc = 0;
	for(unsigned int i = 2147483648; i > 0; i = i/2) {
		if(numbers & i)
			bits[loc] = 1;
		else
			bits[loc] = 0;
		loc++;
	}
}

int calculate(int bits1[], int bits2[]) {
    int flip = 0;
    int math = 0;
    for (int i=0; i<dimension; i++) {
        if (bits1[i] != bits2[i]) {
            if (flip == 0) {
                math++;
                flip = 1;
            }
        } else {
            flip = 0;
        }
    }
    return math;
}

int main ()
{
    int ii[dimension], jj[dimension];
    int T, A;

    scanf("%d %d", &T, &A);

    int It[T], Bt[T];

    for (int j=0;j<T;j++) {
        scanf("%d %d", &It[j], &Bt[j]);
    }

    for (int i=0; i<T; i++) {
        solve(A, ii);
        flipright(It[i], i);
        solve(Bt[i], jj);
        printf("%d\n", calculate(ii, jj));
        A = Bt[i];
    }
}
