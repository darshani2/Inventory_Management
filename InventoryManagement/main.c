#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
//#include <termcap.h>

//#include "LinkedList.h"
//#include "item.h"

//Creating new node to Item
struct Item{
    char name[100];//Data of the item structure(to store character value)
    float price;//Data of the item structure(to store Floating point value)
    int count;//Data of the item structure(to store integer value)
};

struct node {
    struct Item data;
    int key;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//display the list
void printList() {
    struct node *ptr = head;
    printf("\n--------------------------------------\n");

    //start from the beginning
    while(ptr != NULL) {
        printf("(%d) %s - %.2f : %i \n",ptr->key,ptr->data.name,ptr->data.price,ptr->data.count);
        ptr = ptr->next;
    }

    printf("---------------------------------------");
}

//insert link at the first location
void insertFirst(int key, struct Item data) {
    //create a link
    struct node *link = (struct node*) malloc(sizeof(struct node));

    link->key = key;
    link->data = data;

    //point it to old first node
    link->next = head;

    //point first to new first node
    head = link;
}

//delete first item
struct node* deleteFirst() {

    //save reference to first link
    struct node *tempLink = head;

    //mark next to first link as first
    head = head->next;

    //return the deleted link
    return tempLink;
}

//is list empty
bool isEmpty() {
    return head == NULL;
}

int length() {
    int length = 0;
    struct node *current;

    for(current = head; current != NULL; current = current->next) {
        length++;
    }
    //printf("%i",length);
    return length;
}

//find a link with given key
struct node* find(int key) {

    //start from the first link
    struct node* current = head;

    //if list is empty
    if(head == NULL) {
        return NULL;
    }

    //navigate through list
    while(current->key != key) {

        //if it is last node
        if(current->next == NULL) {
            return NULL;
        } else {
            //go to next link
            current = current->next;
        }
    }
    //if data found, return the current Link
    return current;
}

//delete a link with given key
struct node* delete(int key) {

    //start from the first link
    struct node* current = head;
    struct node* previous = NULL;

    //if list is empty
    if(head == NULL) {
        return NULL;
    }

    //navigate through list
    while(current->key != key) {

        //if it is last node
        if(current->next == NULL) {
            return NULL;
        } else {
            //store reference to current link
            previous = current;
            //move to next link
            current = current->next;
        }
    }

    //found a match, update the link
    if(current == head) {
        //change first to point to next link
        head = head->next;
    } else {
        //bypass the current link
        previous->next = current->next;
    }

    return current;
}

/*void sort() {

    int i, j, k, tempKey, tempData;
    struct node *current;
    struct node *next;

    int size = length();
    k = size ;

    for ( i = 0 ; i < size - 1 ; i++, k-- ) {
        current = head;
        next = head->next;

        for ( j = 1 ; j < k ; j++ ) {

            if ( current->data > next->data ) {
                tempData = current->data;
                current->data = next->data;
                next->data = tempData;

                tempKey = current->key;
                current->key = next->key;
                next->key = tempKey;
            }

            current = current->next;
            next = next->next;
        }
    }
}*/

void reverse(struct node** head_ref) {
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;

    while (current != NULL) {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}




/*struct sell{
    int itemId;
    int qty;
};*/

/*struct sell addItemToSale(){
    int itemId;
    int qty = 0;
    //float lineTotal = 0.00;
    struct sell row;
    printf("\nEnter item ID :");
    scanf("%i",&itemId);
    struct node *foundLink = find(itemId);
    if (foundLink != NULL){
        printf("Enter Quantity :");
        scanf("%i",&qty);
        if (foundLink->data.count < qty){
            printf("\nNot enough stock\n");
        } else{
            row.qty = qty;
            row.itemId = itemId;
        }
    } else{
        printf("\nCould not find item number %i \n",itemId);
    }
    return row;
};*/

void addNewSale(){
   // float total;
    int itemCount;

    printf("\nCreate New Sale\n");
    printf("Enter the number of items :");
    scanf("%i",&itemCount);
    //struct sell bill[] = {};
    //int bill_length = sizeof(bill)/sizeof(bill[0]);
    while (itemCount > 0){
        printf("%i",itemCount);
        int itemId;
        int qty;
        //struct sell row;
        printf("\nEnter item ID :");
        scanf("%i",&itemId);
        struct node *foundLink = find(itemId);
        if (foundLink != NULL){
            printf("Enter Quantity :");
            scanf("%i",&qty);
            if (foundLink->data.count < qty){
                printf("\nNot enough stock\n");
            } else{
                float lineTotal = foundLink->data.price * qty;
                printf("%s   -   %i  :   %.2f  :   %.2f ",foundLink->data.name,qty,foundLink->data.price,lineTotal);
                foundLink->data.count = foundLink->data.count-qty;
         /*       row.qty = qty;
                row.itemId = itemId;
                if (bill_length ==0){
                    bill[0] = row;
                } else{
                    bill[bill_length+1] = row;
                }*/
                //total = total+lineTotal;
            }
        } else{
            printf("\nCould not find item number %i \n",itemId);
        }

        //printf("%i",bill_length);
        itemCount--;

/*        if (bill_length == 0){
            bill[0] = addItemToSale();
        } else{
            printf("\nDo You want to add more items (yes = 1/no = 0) :");
            scanf("%i",&continueAddItems);
            bill[bill_length+1] = addItemToSale();
        }*/
    }
    //printf("\nTotal value of sale : %i \n",total);

}

void addNewItem(){
    struct Item item;
    char name[100];
    int nextkey;
    if (head != NULL){
        nextkey = head->key+1;
    } else{
        nextkey = 1;
    }
    printf("----------------------------\n");
    printf("| ** important : When entering the Item name(more than one word), replace the space with the underscore ** |\n");
    printf("(1) Enter Item name :");
    scanf("%s",name);
    strcpy(item.name, name);
    printf("(2) Enter Price : ");
    scanf("%f",&item.price);
    printf("(3) Enter Item Count :");
    scanf("%d",&item.count);
    insertFirst(nextkey,item);
}

void searchItem(){
    int key;
    printf("----------------------------\n");
    printf("Enter the item number you want to search for : ");
    scanf("%i",&key);
    struct node *foundLink = find(key);
    if (foundLink != NULL){
        printf("(%d)   %s    |   %.2f   |    %i \n",foundLink->key,foundLink->data.name,foundLink->data.price,foundLink->data.count);
    } else{
        printf("\nCould not find item number %i \n",key);
    }
}

void deleteItem(){
    int itemId;
    printf("\nEnter the item ID you want to delete\n");
    printf("Item ID :");
    scanf("%i",&itemId);
    struct node *foundLink = find(itemId);
    if(foundLink != NULL) {
        delete(itemId);
        printf("\nItem Deleted\n");

    } else {
        printf("\nElement not found.\n");
    }
}

void updateSalesPrice(){
    int itemId;
    printf("\nEnter the item ID you want to update\n");
    printf("Item ID :");
    scanf("%i",&itemId);
    struct node *foundLink = find(itemId);
    if(foundLink != NULL) {
        float newSalesPrice;
        printf("Enter New Sales price :");
        scanf("%f",&newSalesPrice);
        foundLink->data.price = newSalesPrice;
        printf("\nItem updated\n");

    } else {
        printf("\nElement not found.\n");
    }
}

void welcomeUser(){
   system("color 6F");
   printf("\n\n\n\n\n");
   int x; double y;

   char text1[]=    "\n\n \t\t\t\t\t\t\t\t\t  WELCOME!\n\n ";
   char text2[]=    "\n \t\t\t\t\t\t\t\t\t  To";
   char text3[]=    "\n\n\t\t\t\t\t\t\t\t  ================================\n";
   char text4[]=    "\n\n\t\t\t\t\t\t\t\t     ITEM INVENTORY PROGRAM\n";
   char text5[]=    "\n\n\t\t\t\t\t\t\t\t  ================================";
    printf("\n\n");
    for(x=0; text1[x]!=NULL; x++)
   {
     printf("%c",text1[x]);
      for(y=0; y<=8888888; y++)
      {
      }
   }
   printf("\n\n");
    for(x=0; text2[x]!=NULL; x++)
   {
     printf("%c",text2[x]);
      for(y=0; y<=8888888; y++)
      {
      }
   }
   printf("\n\n");
    for(x=0; text3[x]!=NULL; x++)
   {
     printf("%c",text3[x]);
      for(y=0; y<=8888888; y++)
      {
      }
   }
   printf("\n\n");
    for(x=0; text4[x]!=NULL; x++)
   {
     printf("%c",text4[x]);
      for(y=0; y<=8888888; y++)
      {
      }
   }
   printf("\n\n");
    for(x=0; text5[x]!=NULL; x++)
   {
     printf("%c",text5[x]);
      for(y=0; y<=8888888; y++)
      {
      }
   }
   printf("\n\n");
   system("pause");
   getch();

}

void start(){
    int userinput;
    system("color 2E");
    printf("\n\t\t\t\t\tFunctions Of Inventory management system\n\n");
    printf("Select 1 to add new item. "
           "\nSelect 2 to view inventory "
           "\nSelect 3 to Search "
           "\nSelect 4 to Create a new Sale"
           "\nSelect 5 to Update Price of item"
           "\nSelect 6 to Delete item"
           "\n----------------------------\n"
           );
    printf("Input :");
    scanf("%d", &userinput);
    if (userinput == 1){
        //Add new item
        addNewItem();
    } else if (userinput ==2){
        //view
        printList();
    } else if (userinput == 3){
        //search
        searchItem();
    } else if (userinput == 4){
        //sell
        addNewSale();
    } else if (userinput == 6){
        //delete item
        deleteItem();
    } else if (userinput == 5){
        //update sales price
        updateSalesPrice();
    }
    else{
        printf("\nInvalid Input\n");
    }
    start();
}


int main() {
   welcomeUser();
   system("cls");
   start();
   return 0;
}


