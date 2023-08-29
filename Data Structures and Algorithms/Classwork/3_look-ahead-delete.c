#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int ID;
   char  LN[16], FN[24], MI;  // Lastname, Firstname, Middle Initial
   char course[8];          
   int yearLevel;
} Studrec;

typedef struct node {
    Studrec stud;
    struct node *link;
} *StudList;   // Definition of the List

void insertFirstIfUnique(Studrec elem, StudList *L);
Studrec deleteIfExist(StudList *L, int ID);
void displayList(StudList A);
void displayStud(Studrec S);

int main() {

    StudList L = NULL;

    Studrec a = {1, "lname", "fname", 'c', "BSCS", 2};
    Studrec b = {2, "lname", "fname", 'c', "BSCS", 2};
    Studrec c = {2, "lname", "fname", 'c', "BSCS", 2};
    Studrec d = {3, "lname", "fname", 'c', "BSCS", 2};
    
    insertFirstIfUnique(a, &L);
    insertFirstIfUnique(b, &L);
    insertFirstIfUnique(c, &L);
    insertFirstIfUnique(d, &L);

    displayList(L);
    Studrec x = deleteIfExist(&L, 2);
    displayList(L);

    printf("\nDeleted:\n");
    displayStud(x);
}

void insertFirstIfUnique(Studrec elem, StudList *L) {

    StudList trav;
    for (trav = *L; trav != NULL && trav->stud.ID != elem.ID; trav = trav->link) {}
    if (trav == NULL) {
        StudList temp = (StudList)malloc(sizeof(struct node));
        temp->stud = elem;
        temp->link = *L;
        *L = temp;
    }
}

Studrec deleteIfExist(StudList *L, int ID) {

    Studrec dummy = {0, "XXXXX", "XXXXX", 'X', "XXXXX", 0};

    if (*L != NULL) {
        StudList temp;
        if ((*L)->stud.ID == ID) {
            temp = *L;
            dummy = temp->stud;
            *L = temp->link;
            free(temp); 
        } else {
            StudList trav;
            for (trav = *L; trav->link != NULL && trav->link->stud.ID != ID; trav = trav->link) {}
            if (trav->link != NULL) {
                temp = trav->link;
                dummy = temp->stud;
                trav->link = temp->link;
                free(temp);
            }
        }
    }

    return dummy;
}

void displayList(StudList A) {

    printf("Current List: ");
    while (A != NULL) {
        printf("%d ", A->stud.ID);
        A = A->link;
    }

    printf("\n");
}

void displayStud(Studrec S) {

    printf("ID: %d\n", S.ID);
    printf("Full Name: %s %c. %s\n", S.FN, S.MI, S.LN);
    printf("Course: %s\n", S.course);
    printf("Year Level: %d\n", S.yearLevel);
}
