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

void save()
{
    FILE *fptr;
    char temp_var[100];
    printf("\nEnter of the file: ");
    fgets(temp_var,100,stdin);
    
    printf("Before temp_var: %s",temp_var);
    temp_var[strcspn(temp_var,"\n")]='\0';
    printf("\nFile Name= %s",temp_var);
    fptr = fopen(temp_var, "w");
    struct address_t *temp_node;    
    temp_node=head;          
    while(temp_node!=NULL)
    {   
        fputs(temp_node->data, fptr);
        if(temp_node->next!=NULL)
            fputs("\n",fptr);
        
        temp_node=temp_node->next;
    }
}
