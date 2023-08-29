#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int ID;
   char  LN[16], FN[24], MI;  //Lastname, Firstname, Middle Initial
   char course[8];          
   int yearLevel;
} Studrec;
typedef struct node {
    Studrec stud;
    struct node *link;
} *StudList;   //Definition of the List

void insertFirstIfUnique(Studrec elem, StudList *L);
Studrec deleteIfExist(int ID, StudList *L);
void displayList(StudList A);
void displayStud(Studrec S);

int main () {

    StudList L = NULL;

    Studrec a = {1, "lname", "fname", 'c', "BSCS", 2};
    Studrec b = {2, "lname", "fname", 'c', "BSCS", 2};
    Studrec c = {2, "lname", "fname", 'c', "BSCS", 2};
    Studrec d = {3, "lname", "fname", 'c', "BSCS", 2};

    insertFirstIfUnique(a, &L);
    insertFirstIfUnique(b, &L);
    insertFirstIfUnique(c, &L);
    insertFirstIfUnique(d, &L);
    Studrec x = deleteIfExist(2, &L);
    Studrec y = deleteIfExist(2, &L);

    displayList(L);
    displayStud(x);
    displayStud(y);
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

Studrec deleteIfExist(int ID, StudList *L) {

    StudList *trav;
    Studrec deleted = {0, "XXXXX", "XXXXX", 'X', "XXXXX", 0};
    for (trav = L; *trav != NULL && (*trav)->stud.ID != ID; trav = &(*trav)->link) {}
    if (*trav != NULL) {
        StudList temp = *trav;
        deleted = (*trav)->stud;
        *trav = (*trav)->link;
        free(temp);
    }
    
    return deleted;
}

void displayList(StudList A) {

    while (A != NULL) {
        printf("%d\n", A->stud.ID);
        A = A->link;
    }
}

void displayStud(Studrec S) {

    printf("ID: %d\n", S.ID);
    printf("Full Name: %s %c. %s\n", S.FN, S.MI, S.LN);
    printf("Course: %s\n", S.course);
    printf("Year Level: %d\n", S.yearLevel);
}