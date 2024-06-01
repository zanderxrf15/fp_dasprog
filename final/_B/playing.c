#include <stdio.h>
#include <string.h>

char word[100000];
int counts;
int countsSubstring(char * s){
    int counts=0 ; int left=0 ;int right =0; int len = strlen(s);

    for(int i=0;i<=len ;i++){
        right = left = i;
        while((left >= 0) && (right < len) && (s[left] == s[right])){
                counts +=1;left--; right++;
                  }

        left =i; right=i+1;
         while( (left >= 0) && (right <= len) && (s[left] == s[right])){
                 counts +=1;left--; right++;
                }
    }
  return counts ;
}

int main ()
{
    scanf ("%s", word);
    counts = countsSubstring (word);
    printf ("%d", counts);

}
