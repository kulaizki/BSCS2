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
void displayList(StudList A);

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
}

void insertFirstIfUnique(Studrec elem, StudList *L) {

    StudList *trav;
    for (trav = L; *trav != NULL && (*trav)->stud.ID != elem.ID; trav = &(*trav)->link) {}
    if (*trav == NULL) {
        StudList temp = (StudList)malloc(sizeof(struct node));
        temp->stud = elem;
        temp->link = NULL;
        *trav = temp;
    }
}

void displayList(StudList A) {

    while (A != NULL) {
        printf("%d\n", A->stud.ID);
        A = A->link;
    }
}