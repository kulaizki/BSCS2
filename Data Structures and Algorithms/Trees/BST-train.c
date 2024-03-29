#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

typedef struct node {
    int elem;
    struct node *LC;
    struct node *RC;
} *Node;

typedef struct {
	int elem[MAX];
	int count;
} AList;

Node createNode(int data);
void insert(Node *root, int e);
void insertIterative(Node *root, int elem);
void preOrder(Node node);
void inOrder(Node node);
void postOrder(Node node);
int sum(Node root);
bool isMember(Node root, int e);
bool isMemberIterative(Node root, int e);
void delete(Node *root, int e);
void deleteIterative(Node *root, int e);
int min(Node root);
int minIterative(Node root);
int max(Node root);
int maxIterative(Node root);
AList convertToAList(Node *root);
void convertAndDelete(Node *root, AList *result);

int main() {

    Node tree = NULL;

    insert(&tree, 4);
    insert(&tree, 2);
    insert(&tree, 5);
    insert(&tree, 5);
    insertIterative(&tree, 1);
    insertIterative(&tree, 3);
    insertIterative(&tree, 9);
    insertIterative(&tree, 9);

    delete(&tree, 1);
    deleteIterative(&tree, 2);
    
    printf("PreOrder Traversal\n");
    preOrder(tree);
    printf("\nPostOrder Traversal\n");
    postOrder(tree);
    printf("\nInOrder Traversal\n");
    inOrder(tree);

    printf("\nTree sum: %d\n", sum(tree));
    printf("isMember (5): %d\n", isMember(tree, 4));
    printf("isMember (6): %d\n", isMember(tree, 6));
    printf("isMember (5): %d\n", isMemberIterative(tree, 4));
    printf("isMember (6): %d\n", isMemberIterative(tree, 6));

    printf("min: %d\n", min(tree));
    printf("minIterative: %d\n", minIterative(tree));
    printf("max: %d\n", max(tree));
    printf("maxIterative: %d\n", maxIterative(tree));

    AList A = convertToAList(&tree);
    printf("Convert to Sorted Array List\n");
    for (int i = 0; i < A.count; ++i) {
        printf("%d ", A.elem[i]);
    }
    printf("\n");
}

Node createNode(int data) {

    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->elem = data;
    newNode->LC = NULL;
    newNode->RC = NULL;

    return newNode;
}

void insert(Node *root, int e) {

    if (*root == NULL) {
        *root = createNode(e);
    } else if (e < (*root)->elem) {
        insert(&(*root)->LC, e);
    } else if (e > (*root)->elem) {
        insert(&(*root)->RC, e);
    }

    return;
}

void insertIterative(Node *root, int elem) {
	
	Node *trav;
	for (trav = root; *trav != NULL && (*trav)->elem != elem; trav = elem < (*trav)->elem ? &(*trav)->LC : &(*trav)->RC) {}
	
	if (*trav == NULL) {
		*trav = createNode(elem);
	}
}

void preOrder(Node node) {

    if (node != NULL) {
        if(node->LC != NULL) preOrder(node->LC);
        if(node->RC != NULL) preOrder(node->RC);
        printf("%d ", node->elem);
    }
}

void inOrder(Node node) {

    if (node != NULL) {
        if(node->LC != NULL) inOrder(node->LC);
        printf("%d ", node->elem);
        if(node->RC != NULL) inOrder(node->RC);
    }
}

void postOrder(Node node) {

    if (node != NULL) {
        if (node->LC != NULL) postOrder(node->LC);
        if (node->RC != NULL) postOrder(node->RC);
        printf("%d ", node->elem);
    }
}

int sum(Node root) {

    if (root == NULL) return 0;
    return root->elem + sum(root->LC) + sum(root->RC);
}

bool isMember(Node root, int e) {

    return root == NULL ? false : e == root->elem ? true : e < root->elem ? isMember(root->LC, e) : isMember(root->RC, e);
}

bool isMemberIterative(Node root, int e) {

    while (root != NULL && e != root->elem) {
        root = e < root->elem ? root->LC : root->RC;
    }

    return root == NULL ? false : true;
}

void delete(Node *root, int e) {

    if (*root == NULL) return;

    if (e < (*root)->elem) {
        delete(&(*root)->LC, e);
    } else if (e > (*root)->elem) {
        delete(&(*root)->RC, e);
    } else {
        if ((*root)->LC == NULL) {
            Node temp = (*root)->RC;
            free(*root);
            *root = temp;
        } else if ((*root)->RC == NULL) {
            Node temp = (*root)->LC;
            free(*root);
            *root = temp;
        } else {
            (*root)->elem = min((*root)->RC);
            delete(&(*root)->RC, (*root)->elem);
        }
    }
}

void deleteIterative(Node *root, int e) {
	
	Node *trav, temp;
	for (trav = root; *trav != NULL && (*trav)->elem != e; trav = e < (*trav)->elem ? &(*trav)->LC : &(*trav)->RC) {}
	
	if (*trav != NULL) {
		temp = *trav;
		if (temp->LC != NULL && temp->RC != NULL) {
			for (trav = &(*trav)->RC; (*trav)->LC != NULL; trav = &(*trav)->LC) {}
			temp->elem = (*trav)->elem;
			temp = *trav;
		}
		*trav = (*trav)->LC != NULL ? (*trav)->LC : (*trav)->RC;
		free(temp);
	}
}

int min(Node root) {

    return (root != NULL) ? (root->LC == NULL) ? root->elem : min(root->LC) : -1;
}

int minIterative(Node root) {
	
	int retval = -1;
    if (root != NULL) {
        for (;root->LC != NULL; root = root->LC) {}
        retval = root->elem;
    }

    return retval;
}

int max(Node root) {

    return (root != NULL) ? (root->RC == NULL) ? root->elem : max(root->RC) : -1;
}

int maxIterative(Node root) {
	
	int retval = -1;
    if (root != NULL) {
        for (; root->RC != NULL; root = root->RC) {}
        retval = root->elem;
    }

    return retval;
}

void displayTree(Node root, int level) {

    if (root != NULL) {
        displayTree(root->RC, level + 1);
		
		int i;
        for (i = 0; i < level; i++) {
            printf("   ");
        }

        printf("%d\n", root->elem);
        displayTree(root->LC, level + 1);
    } else {
        printf("No elements to display\n");
    }
}

AList convertToAList(Node *root) {

    AList result;
    result.count = 0; 

    convertAndDelete(root, &result);

    return result;
}

void convertAndDelete(Node *root, AList *result) {

    if (*root != NULL) {
        convertAndDelete(&(*root)->LC, result);
        result->elem[result->count++] = (*root)->elem;
        convertAndDelete(&(*root)->RC, result);

        free(*root);
        *root = NULL;
    }
}