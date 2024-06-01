#include <stdio.h>
#include <string.h>
#include <math.h>

char map[1001][1001];
int measurement=0, longest=0;
int p, q;

void MazeRunner(int x, int y)
{
    map[x][y]='+';
    measurement++;
    int id=0;
    static int row[] = {-1, 0, 0, 1};
    static int column[] = {0, -1, 1, 0};

    for (int k = 0; k < 4; k++)
    {
        if(map[x+row[k]][y+column[k]]=='.')
        {
            MazeRunner(x+row[k], y+column[k]);
            id=1;
        }
    }
    map[x][y]='.';
    measurement--;
    if (measurement >= longest){
        longest = measurement;
        if(id==0){
        q=y;
        p=x;
    }
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int k=0;k<T;k++){
        int a, b;
        scanf("%d %d",&a, &b);

        for (int i = 0; i<b ; i++){
            scanf("%s", map[i]);
        }
        for(int i = 0; i < b; i++){
            for(int j=0; j < a; j++){
                if(map[i][j]=='.'){
                MazeRunner(i, j);
                break;
                }
            }
        }
        measurement=0;
        longest=0;
        MazeRunner(p,q);
        printf("Panjang tali adalah %d.\n", longest);
        longest=0;
    }
}
