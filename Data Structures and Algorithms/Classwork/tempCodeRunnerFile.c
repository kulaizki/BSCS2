void deleteAllOccurences(char elem, LIST *A) {

    LIST *trav = A, temp;
    while (*trav != NULL) {
        if ((*trav)->data == elem) {
            temp = *trav;
            *trav = temp->link;
            free(temp);
        } else {
            trav = &(*trav)->link;
        }
    }
}