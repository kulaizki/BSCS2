#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VH_SIZE     0XF   //size of Virtual Heap
#define MAX         0xF  // MAX size of the list
/******************************************************************************
 * Data Structure Definition:                                                 *
 ******************************************************************************/
typedef struct {  
	char name[24];          // Chocolate name  
 	int  weight;            // Chocolate weight in grams  
}chocoDesc;
 
typedef struct {
   char prodID[8];          //  product ID uniquely identifies the products; EMPTY or DELETED   
  	chocoDesc prodDesc;     //  product description 
 	float prodPrice;        //  product price 
  	int prodQty;            //  product count or quantity   
}product;                   //  product record  

/**************************************
 * Cursor-based implementation of BST *
 **************************************/
typedef int BST;   //Definition of BST
 
typedef struct {
  product elem;            
  int LC;        //holds the index of the left child
  int RC;        //holds the index of the Right Child; USE as link to next node in the Virtual heap               
}BSTnode;        // Product node, used in cursor-based implementation of BST  


/************************
 * Virtual Heap         *
 ************************/
typedef struct {
   BSTnode VH_node[VH_SIZE];
   int avail;
}VHeap;

/************************
 * List definition       *
 ************************/
typedef struct {
	product prod[MAX];
	int last;     //index of the last element	
}ArrayList;

      
/**********************************************************
 * Function Prototypes                                    *
 *********************************************************/
//---Problem #3 ---
BST createMagicalBSTvheap(VHeap *VH);    // Complete
void displayVHeap(VHeap V);              // Partially coded
void displayProduct(product P);          // Complete
ArrayList convertBstToList(BST *B, VHeap *VH);   //Removes from the BST smallest element to the biggest until BST is empty
void displayList(ArrayList A);                //displays the elements of the list
 
 
int main() 
{
    printf("\n\n\nProblem #3:: "); 
    printf("\n------------");
  
    // Declare variables needed for Problem #3
    BST magicalBST;
    VHeap virtualHeap;
    ArrayList productList;

    // Populate the Virtual heap and the BST
    createMagicalBSTvheap(&virtualHeap);
    magicalBST = virtualHeap.avail;

    // Display the state of the virtual heap
    displayVHeap(virtualHeap);

    // Convert BST to List and display the List
    productList = convertBstToList(&magicalBST, &virtualHeap);
    displayList(productList);

    // Display the state of the virtual heap after conversion
    displayVHeap(virtualHeap);

    return 0; 
}

// ...

void displayVHeap(VHeap V)
{
    int x;

    printf("\n\nDetails of the Virtual Heap :: ");
    printf("\n------------------------------");
    printf("\nAvailable Index  :: %d", V.avail);

    printf("\n\n%10s", "Index");
    printf("%10s", "Prod ID");
    printf("%15s", "LC Field");
    printf("%15s", "RC Field");
    printf("\n%10s%10s%15s%15s", "-----", "-------", "--------", "--------");

    for (x = 0; x < VH_SIZE; x++)
    {
        printf("\n%10d%10s%15d%15d", x, V.VH_node[x].elem.prodID, V.VH_node[x].LC, V.VH_node[x].RC);
    }

    printf("\n\n");
    system("Pause");
}

ArrayList convertBstToList(BST *B, VHeap *VH)
{
    ArrayList productList;
    productList.last = -1;

    // Write code here to remove elements from the BST and add them to the List

    return productList;
}

void displayList(ArrayList A)
{
    int i;

    printf("\n\nDetails of the List :: ");
    printf("\n----------------------");

    if (A.last == -1)
    {
        printf("\nList is Empty!");
    }
    else
    {
        printf("\n%-8s", "Prod ID");
        printf("%-10s", "Name");
        printf("%-6s", "Weight");
        printf("%-10s", "Price");
        printf("%-6s", "Qty");
        printf("\n%-8s", "-------");
        printf("%-10s", "----");
        printf("%-6s", "------");
        printf("%-10s", "--------");
        printf("%-6s", "---");

        for (i = 0; i <= A.last; i++)
        {
            displayProduct(A.prod[i]);
        }
    }

    printf("\n\n");
    system("Pause");
}