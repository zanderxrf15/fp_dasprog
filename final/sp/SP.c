#include <stdio.h>
#include <math.h>

int main(){
int n, input, output;
scanf("%d", &n);

    for (int i=1; i<=n; i++){
            scanf ("%d", &input);
            if (input%2==0){
                printf ("%d\n", (2*input)-1);
            }
            else {
                printf ("%d\n", (2*input)+1);
            }
    }
}
