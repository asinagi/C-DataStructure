#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITEMS 6

typedef struct {
    char name[10];
    int strength;
    int agility;
    int intelligence;
    int dexterity;
} Item;

void generateItems(Item *items[]) {
    char* names[NUM_ITEMS] = {"머리", "가슴", "바지", "신발", "장갑", "망토"};
    int i;
    for (i = 0; i < NUM_ITEMS; i++) {
        items[i] = (Item*)malloc(sizeof(Item));
        strcpy(items[i]->name, names[i]);
        items[i]->strength = rand() % 5 + 1;
        items[i]->agility = rand() % 5 + 1;
        items[i]->intelligence = rand() % 5 + 1;
        items[i]->dexterity = rand() % 5 + 1;
    }
}

void printItems(Item *items[]) {
    int i;
    for (i = 0; i < NUM_ITEMS; i++) {
        printf("%s - 힘: %d, 민첩: %d, 지식: %d, 수완: %d\n", items[i]->name, items[i]->strength, items[i]->agility, items[i]->intelligence, items[i]->dexterity);
    }
}

void freeItems(Item *items[]) {
    int i;
    for (i = 0; i < NUM_ITEMS; i++) {
        free(items[i]);
    }
}

int main() {
    srand(time(NULL));
    Item *items[NUM_ITEMS];
    generateItems(items);
    printItems(items);
    freeItems(items);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITEMS 6

typedef struct {
    char name[10];
    int strength;
    int agility;
    int intelligence;
    int dexterity;
} Item;

void generateItems(Item *items[]) {
    char* names[NUM_ITEMS] = {"머리", "가슴", "바지", "신발", "장갑", "망토"};
    int i;
    for (i = 0; i < NUM_ITEMS; i++) {
        items[i] = (Item*)malloc(sizeof(Item));
        strcpy(items[i]->name, names[i]);
        items[i]->strength = rand() % 5 + 1;
        items[i]->agility = rand() % 5 + 1;
        items[i]->intelligence = rand() % 5 + 1;
        items[i]->dexterity = rand() % 5 + 1;
    }
}

void printItems(Item *items[]) {
    int i;
    for (i = 0; i < NUM_ITEMS; i++) {
        printf("%s - 힘: %d, 민첩: %d, 지식: %d, 수완: %d\n", items[i]->name, items[i]->strength, items[i]->agility, items[i]->intelligence, items[i]->dexterity);
    }
}

void freeItems(Item *items[]) {
    int i;
    for (i = 0; i < NUM_ITEMS; i++) {
        free(items[i]);
    }
}

int main() {
    srand(time(NULL));
    Item *items[NUM_ITEMS];
    generateItems(items);
    printItems(items);
    freeItems(items);
    return 0;
}
