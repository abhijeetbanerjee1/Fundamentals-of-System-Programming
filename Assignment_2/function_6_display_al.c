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
void displayalias()
{
    int o1,o2;
                printf("\nEnter two address octets to be searched for..\n");
                up:
                printf("\nEnter octet1: ");

                if(scanf(" %d",&o1)==1)
                {
                    if(o1>=0 && o1<256)
                    {   up1:
                        printf("\nEnter octet2: ");
                        if(scanf(" %d",&o2)==1)
                        {
                            if(!(o2>=0 && o2<256))
                            {
                                printf("\nNot valid.\n");
                                goto up1;
                            }
                        }
                    }
                    else
                    {
                        printf("\nNot valid.\n");
                        goto up;
                    }
                }
                struct address_t *temp;    
                temp=head;          
                int a,b,c,d,ind=0;
                char arr[20];
                printf("\nAlias(s) having these octets in the address are: \n");
                    while(temp!=NULL)
                    {
                        sscanf(temp->data,"%d.%d.%d.%d %s",&a,&b,&c,&d,arr);
                        if(a==o1 && b==o2)
                        {
                            printf("\n%s",arr);
                            ind=1;
                        }
                    temp=temp->next;
                    }
                if(ind==0)
                {
                    printf("None\n");
                printf("\nNo records found for location: [%d.%d]\n",o1,o2);
                }
}
