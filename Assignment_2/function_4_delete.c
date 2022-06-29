#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

void deleteaddress()
{
    char aname[20];
                printf("Enter the alias\n");
                fgets(aname,20,stdin);
                if (aname[0]!='\0')
                {
                    size_t len = strlen(aname);
                    if (len > 0 && aname[len-1] == '\n')
                    {
                        aname[len-1] = '\0';
                    }
                }
                int q,r,t,s,g=0;
                struct address_t *temp;    
                temp=head;
                int count=0;
                char fname[20];
                char ch;
                while(temp!=NULL)
                {
                    memset(fname,'\0',sizeof(fname));
                    sscanf(temp->data, "%d.%d.%d.%d %s",&q, &r ,&t, &s, fname);
                    char temp1[50]="",temp2[50]="";
                    for(int i = 0; i<(strlen(fname)); i++)
                        {
                            temp1[i] = tolower(fname[i]);
                        }
                    
                        for(int j=0; j<(strlen(aname)); j++) 
                        {
                            temp2[j] = tolower(aname[j]);
                        }
                    if(strcmp(temp1,temp2)==0)
                    {
                        g=0;
                        printf("\n%d.%d.%d.%d\n",q,r,t,s);
                        printf("\nAre you sure you want to delete this record(Y|N)\n");
                        scanf("%c",&ch);
                        if(ch=='Y' || ch=='y')
                        {
                            delete_node(count);
                            displayaddress();
                            break;
                        }
                        else if(ch=='N' || ch=='n')
                        {
                            printf("\nYou have chosen not to delete\n");
                            
                        }
                        else
                        {
                            printf("\nInvalid choice!!..\n");
                            
                        }
                    }
                    else
                    {
                        temp=temp->next;
                        g = 1;
                        count++;
                    }
                }
                if(g==1)
                    {
                        printf("\nAlias doesn't exists!!\n");
                    }
                
}
