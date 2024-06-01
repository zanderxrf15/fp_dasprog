#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int id,amount,earn=0;
char op[100];
const int foodShelves = 1000000;
const char OP_ADD[100] = "ADD";
const char OP_INFO[100] = "INFO";
const char OP_REMOVE[100] = "REMOVE";
const char OP_ORDER[100] = "ORDER";
const char OP_DISC[100] = "DISC";
const char OP_CLOSE[100] = "CLOSE";

struct Food
{
    int id;
    char name[100];
    int price, stock;
    int discount;
};

struct Food **product;

void printFood(struct Food *product) {
    printf("%d %s %d %d\n", product->id, product->name, product->price, product->stock);
}

void Remove() {
    scanf("%d", &id);
    if (product[id] == NULL) {
        printf("Menu does not exist\n");
    } else {
        free(product[id]);
        product[id]=NULL;
        printf("Menu removed\n");
    }
}

void Info() {
    scanf("%d", &id);
    if (product[id] == NULL) {
        printf("Menu does not exist\n");
    } else {
        printf("#%d %s\n", product[id]->id, product[id]->name);
        printf("Price : Rp%d\n", product[id]->price);
        printf("Stock : %dx\n", product[id]->stock);
        printf("\n");
    }
}

void Add() {
    struct Food *f = (struct Food*) malloc(1 * sizeof(struct Food));

    scanf("%d", &id);
    f->id=id;
    scanf("\n%[^\n]%*c", f->name);
    scanf("%d", &f->price);
    scanf("%d", &f->stock);
    product[id] = f;
    printf("Menu added\n");
}

void Close() {
    printf("Earnings: Rp%d\n", earn);
    printf("Informatics canteen is closing... thanks for the visit!\n");
}

void Discount() {
    scanf("%d", &id);
    scanf("%d", &amount);
    if (product[id] == NULL) {
        printf("Menu does not exist\n");
    } else {
        product[id]->discount = amount;
        printf("Discount added\n");
    }
}

void Order() {
    scanf("%d", &id);
    scanf("%d", &amount);
    if (product[id] == NULL) {
        printf("Menu does not exist\n");
    } else if (amount <= 0) {
        printf("So you want to order or what\n");
    } else if (amount > product[id]->stock) {
        printf("Apologize, the stock is not enough\n");
    } else {
        int disc = product[id]->price*product[id]->discount/100;
        int totalPrice = amount*(product[id]->price-disc);
        earn += totalPrice;
        product[id]->stock -= amount;
        printf("Ordered %dx %s for Rp%d\n", amount, product[id]->name, totalPrice);
    }
}

int main()
{
    product = malloc(foodShelves* sizeof(struct People*));
    while (1==1) {
        scanf ("%s", op);
        if (strcmp(op, OP_ADD) == 0) {
            Add();
        }
        else if (strcmp(op, OP_INFO) == 0) {
            Info();
        }
        else if (strcmp(op, OP_REMOVE) == 0) {
            Remove();
        }
        else if (strcmp(op, OP_ORDER) == 0) {
            Order();
        }
        else if (strcmp(op, OP_DISC) == 0) {
            Discount();
        }
        else if (strcmp(op, OP_CLOSE) == 0) {
            Close();
            break;
        }
        else
        {
            printf("Unknown command\n");
        }
    }
}


