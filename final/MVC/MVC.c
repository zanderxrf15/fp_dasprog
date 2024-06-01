#include <stdio.h>
#include <string.h>

char NUM[100];

void swap(char *xp, char *yp) {
   int temp = *xp;
   *xp = *yp;
   *yp = temp;
}

void bubbleSort(char arr[], int DIGITS) {
   int i, j, swapped;
   for (i = 0; i < DIGITS-1; i++) {
      swapped = 0;
      for (j = 0; j < DIGITS-i-1; j++) {
         if (arr[j] < arr[j+1]) {
            swap(&arr[j], &arr[j+1]);
            swapped = 1;
         }
      }
      if (swapped == 0)
         break;
   }
}

int main()
{
    int DIGITS;

    scanf("%s", NUM);
    scanf("%d", &DIGITS);

    char output[DIGITS],temp[DIGITS];
    for (int i = 0; i < DIGITS; i++){
        temp[i] = '0';
        output[i] = '0';
    }

    for (int i = 0; i < strlen(NUM) - DIGITS+ 1 ; i++){
        int offset = i;
        for (int j = 0; j < DIGITS; j++){
            temp[j] = NUM[j + offset];
        }
        bubbleSort(temp,DIGITS);
        if (strcmp(temp,output) > 0){
        strcpy(output,temp);
        }
    }

    for (int i = 0; i < DIGITS; i++){
        printf("%c",output[i]);
    }
}
