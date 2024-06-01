#include <stdio.h>

struct data{
    char name[101];
    char e;
    char n;
    int latitude;
    int longitude;

};

int num;
void check(int *num){
    if(*num==1){
        *num=0;
    }
    else{
        for(int i=2;i<=*num/2;i++){
            if(*num % i==0){
                *num=0;
            }
        }
    }
}
int main()
{

    int a,b;
    int c;
    char look[1001];
    scanf("%d %d",&a,&b);
    struct data x[a];

    for(int i=0;i<a;i++){
        scanf("%s %d%c %d%c",x[i].name,&x[i].latitude,&x[i].n,&x[i].longitude,&x[i].e);
    }
    for(int i=0;i<b;i++){
        scanf("%s",look);
        for(int j=0;j<a;j++){
            if(strcmp(look,x[j].name)==0){
            check(&x[j].latitude);
            check(&x[j].longitude);
                if(x[j].latitude != 0 && x[j].longitude != 0){
                    printf("%s aman! Bangunlah Kesatria!\n",x[j].name);
                    c=1;
                    break;
                }
          else{
                    printf("%s tidak aman! Ini pasti ulah Gorgom!\n",x[j].name);
                    c=1;
                    break;
                }
            }
            else{
                c=0;
            }
        }
        if(c==0){
            printf("Tempat apa itu? Kotaro tidak tahu!\n");
        }
    }
}
