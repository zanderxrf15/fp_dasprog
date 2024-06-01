#include <stdio.h>

int main()
{
    long long saldo, biaya;
    int n, poin=0;
    char isBerguna[1000];

    scanf("%lld %d", &saldo, &n);

    for(int i=0; i<n; i++)
    {
        scanf("%s %lld", isBerguna, &biaya);

        if(strcmp(isBerguna,"Iya")==0)
        {
            saldo -= biaya;
            if(biaya>500000000)
            {
                poin += 50;
            }
            else if(biaya>10000000)
            {
                poin += 35;
            }
            else if(biaya>500000)
            {
                poin += 20;
            }
            else if(biaya>100000)
            {
                poin += 5;
            }
            else
            {
                poin += 1;
            }
        }
        else if(strcmp(isBerguna, "Tidak")==0)
        {
            saldo -= biaya;
            if(biaya>500000000)
            {
                poin -= 50;
            }
            else if(biaya>10000000)
            {
                poin -= 35;
            }
            else if(biaya>500000)
            {
                poin -= 20;
            }
            else if(biaya>100000)
            {
                poin -= 5;
            }
            else
            {
                poin -= 1;
            }
        }
    }
    if(saldo<=0 || poin<0)
    {
        printf("Ujana tidak berakhir bahagia.\n");
    }
    else if(poin>0)
    {
        printf("Ujana berakhir bahagia.\n");
    }
    else if(poin==0)
    {
        printf("Ujana berakhir b aja.\n");
    }
}
