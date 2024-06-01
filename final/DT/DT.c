#include <stdio.h>

int amountSwap;
void swap(int *xp, int *yp) {
   int temp = *xp;
   *xp = *yp;
   *yp = temp;
}

void bubblesort(int arr[], int N) {
   int i, j, swapped;
   for (i = 0; i < N-1; i++) {
      swapped = 0;
      for (j = 0; j < N-i-1; j++) {
         if (arr[j] > arr[j+1]) {
            swap(&arr[j], &arr[j+1]);
            amountSwap++;
            swapped = 1;
         }
      }
      if (swapped == 0)
         break;
   }
}

int main()
{
int run=1;
while(run){
    int N;
    amountSwap=0;
    scanf("%d",&N);
    int numberGroups[N+1];

    if(N==0){
        break;
    }
    for(int i=0;i<N;i++){
        scanf("%d",&numberGroups[i]);
    }
    bubblesort(numberGroups,N);
    printf("Minimal lakukan %d pertukaran\n", amountSwap);
        for(int i=0;i<N;i++){
            if(numberGroups[i]%2==0){
                printf("Yeay\n");
            }
            if(numberGroups[i]%5==0){
                printf("Lulus\n");
            }
            if(numberGroups[i]%10==0){
                printf("Dasprog\n");
            }
            if(numberGroups[i] % 2 != 0 && numberGroups[i] % 5 != 0 && numberGroups[i] % 10 != 0){
                printf("%d ", numberGroups[i]);
            }
            printf("\n");
        }
}
}
