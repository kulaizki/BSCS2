#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StatsType {
    int health;
    int damage;
    char attribute[10];
} StatsType;

typedef struct HeroType {
    char name[40];
    StatsType stats;
    char ultimate[40];    
} HeroType;

typedef struct HeroList {
    HeroType hero;
    struct HeroList *nextHero;
} *HeroList;

void addHero(HeroList *HL);

int main() {

    HeroList A = NULL;
    int n;

    printf("Input amount of heroes to add: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        addHero(&A);
    }    
}

void addHero(HeroList *HL) {

}
