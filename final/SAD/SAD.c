#include <stdio.h>

int combinationNumber(int N) {
    if (N% 11 == 0)
    {
        return 1;
    }
    if (N % 15 == 0)
    {
        return 1;
    }

    int combo1 = 11;
    int match = 0;
    while (combo1 <= N && match != 1)
    {
        int combo2 = 15;
        while (combo1 + combo2 <= N && match != 1)
        {
            if (combo1 + combo2 == N)
            {
                match = 1;
				break;
            }
            combo2 += 15;
        }
		if (match == 1) break;
        combo1 += 11;
    }
    return match;
}

int main() {
    int total;
    scanf("%d", &total);

    int entry[total];
    for (int i=0; i < total; i++)
    {
        int input;
        scanf("%d", &entry[i]);
    }
    for (int i=0; i < total; i++)
    {
        if (combinationNumber(entry[i]) == 1){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
