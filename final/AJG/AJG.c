#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

bool prime[1000001];
void SieveOfEratosthenes(int n)
{
    memset(prime, false, sizeof(prime));
    prime[1]=true;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == false) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = true;
        }
    }

}

int main ()
{
    int Q, N, CODE [100001];
    SieveOfEratosthenes(100001);
    scanf ("%d", &Q);
    for (int i=1; i<=Q; i++){
        scanf ("%d", &N);
        int numbers=0;
        for (int j=1; j<=N; j++){
            scanf ("%d", &CODE[j]);
            if (prime[CODE[j]]==false){
                    printf("%d ", CODE[j]);
                    numbers=1;
                }
        }
        if (numbers==0){
                printf ("Unable to send Fever Slot Buckle.\n");
        }
        else {
                printf ("");
        }
    }
}
