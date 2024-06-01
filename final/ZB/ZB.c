#include <stdio.h>
#include <math.h>

int GCF(int num1 , int num2){
    if(num2==0){
        return num1;
    }
    return GCF(num2,num1%num2) ;
}

long long powmod(int P,  int Q , int mod){
    if(Q==0){
        return 1 ;
    }
    long long x = powmod(P,Q/2,mod);
    x = (x*x)%mod;
    if(Q&1){
        x = (P*x)%mod;
    }
    return x;
}

int main(){
    int N , K ;
    int i;
    scanf("%d %d", &N, &K);
    int output = 0;
    int mod = 1000000007;
    for(i = 0 ; i < N ; ++i){
        output = (output + powmod(K,GCF(i,N),mod))%mod;
    }
    output = (output*powmod(N,mod-2,mod))%mod;
     printf("%d", output);
}
