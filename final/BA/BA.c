#include <stdio.h>

struct operand
{
    int operation;
    char t[50];
    int x;
};

int main() {
    int N, Q;
    scanf("%d", &N);

    int input[N];

    for (int i=0; i< N; i++) {
        scanf("%d", &input[i]);
    }

    scanf("%d", &Q);
    struct operand compute[Q];

    for (int i=0; i< Q; i++) {
        scanf("%d", &compute[i].operation);
        if (compute[i].operation==1) {
            scanf("%s", &compute[i].t);
            scanf("%d", &compute[i].x);
        }
    }

    for (int j=0; j< Q; j++) {
        if (compute[j].operation == 2) {
            for (int i=0; i< N; i++) {
                printf("%d ", input[i]);
            }
            printf("\n");
        } else {
            if (strcmp("XOR", compute[j].t) == 0) {
                for (int i=0; i< N; i++) {
                    input[i] ^= compute[j].x;
                }
            }
            if (strcmp("OR", compute[j].t) == 0) {
                for (int i=0; i< N; i++) {
                    input[i] |= compute[j].x;
                }
            }
            if (strcmp("AND", compute[j].t) == 0) {
                for (int i=0; i< N; i++) {
                    input[i] &= compute[j].x;
                }
            }

        }
    }
}
