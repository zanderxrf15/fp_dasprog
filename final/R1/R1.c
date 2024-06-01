#include <stdio.h>
#include <string.h>
#include <math.h>

typedef long long int ll;
typedef unsigned long long int ull;

int main() {
    int N;
    scanf("%d", &N);
    char name[N][100];
    int players = 0;
    int maxNumbers;
    for (int i=0; i<N; i++) {
        scanf("%s", name[i]);
        int M;
        scanf("%d", &M);
        int row[M];
        int maxRuns = -1000;
        int max = 0;
        for (int j=0; j<M; j++) {
            scanf("%d", &row[j]);
            max += row[j];
            if (maxRuns < max) {
                maxRuns = max;
            }
            if (max < 0) {
                max = 0;
            }
        }
        if (i == 0) maxNumbers = maxRuns;
        if (maxNumbers < maxRuns) {
            maxNumbers = maxRuns;
            players = i;
        }
    }
    printf("%s\n",name[players]);
}
