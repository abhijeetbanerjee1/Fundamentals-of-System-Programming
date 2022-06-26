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
struct address_t *head = NULL;
struct address_t *tail = NULL;

int main()
{
  char temp_str[50];
  int switch_var;
  FILE *fptr;
  

  fptr = fopen("CS531_Inet.txt","r");
  if(fptr == NULL)
  {
    printf("Error opening file");
    return 1;
  }
  
  while(fgets(temp_str,100,fptr))
  {
      size_t len = strlen(temp_str);
        if (len > 0 && temp_str[len-1] == '\n')
        {
            temp_str[--len] = '\0';
        }
        insert_node(temp_str);
  }
  
  while(1)
    {
        printf("\n\n\t\tMenu\n");
        printf("\t1) Add address\n");
        printf("\t2) Look up address\n");
        printf("\t3) Update address\n");
        printf("\t4) Delete address\n");
        printf("\t5) Display list\n");
        printf("\t6) Display aliases for location\n");
        printf("\t7) Save to file\n");
        printf("\t8) Quit\n");

        printf("Enter your choice of action from the above menu: ");
        if(scanf(" %d",&switch_var)==1)
        {
            int i=getchar();
            if(i==0)
            {
                printf(" ");
            }
        }

        switch(switch_var)
        {
            case 1: addaddress();
            break;
            
            case 2: lookup();
            break;
            
            case 3: updateaddress();
            break;
            
            case 4: deleteaddress();
            break;
            
            case 5: displayaddress();
            break;
            
            case 6: displayalias();
            break;
            
            case 7: save();
            break;
            
            case 8: quit();
            break;
        }
    }
  fclose(fptr);
  return 0;
}


void insert_node(char space[50])
{
    struct address_t *new_node; 
     // Creating a new node
    new_node = (struct address_t *)malloc(sizeof(struct address_t)); // Allocating dynamic memory
    strcpy(new_node->data,space);
    new_node->next = NULL;

    if(head==NULL)      // Checking if List is empty
    {
        head = new_node;
        tail = new_node;
    }
    else                // If not empty then...
    {
        tail->next=new_node;
        tail=new_node;       // Updating the tail node with each insertion
    }
    return ;
}

void delete_node(int location)
{
    int i;
    struct address_t *temp_node = head;       // Creating a temporary variable pointing to head
    
    if(location==0)
    {
        printf("\n%s is removed.\n",temp_node->data);
        head=head->next;        // Advancing the head pointer
        temp_node->next=NULL;
        free(temp_node);             // Node is deleted
    }
    else
    {
        for(i=0;i<location-1;i++)
        {
            temp_node=temp_node->next;
        }
        // Now temp_node pointer points to the previous node of the node to be deleted
        struct address_t *delete_node =temp_node->next;       // delete_node pointer points to the node to be deleted
        temp_node->next=temp_node->next->next;
        printf("\n%s is removed\n",delete_node->data);
        delete_node->next=NULL;
        free(delete_node);                          // Node is deleted
    }
    return ;
}
