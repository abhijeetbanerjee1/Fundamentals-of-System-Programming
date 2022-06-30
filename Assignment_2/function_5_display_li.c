#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"function.h"

/* CS 531 - HW2
Abhijeet Banerjee
G01349260*/


struct address_t{
char data[50];
int octet[4];
char alias[11];
struct address_t *next;
};
extern struct address_t *head;
extern struct address_t *tail;

void displayaddress()
{
    int nodes=0;
    struct address_t *temp;    
    temp=head;          
    while(temp!=NULL)
    {   nodes+= 1;
        
        if(temp->next==NULL)
        {
            printf("\n===>%s\n->NULL",temp->data);
        }
        else
        {
            printf("\n===>%s",temp->data);
        }
        temp=temp->next;            
    }
    printf("\nNumber of nodes in the list: %d",nodes);
    if(head==NULL)
    {
        printf("\nThe list is empty!!!..\n");
    }
    
    return ;
}
