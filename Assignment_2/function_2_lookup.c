#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "function.h"

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

void lookup()
{
    char aname[20];
                printf("Enter the alias\n");
                fgets(aname,20,stdin);
                if (aname[0]!= '\0')
                {
                    size_t len = strlen(aname);
                    if (len > 0 && aname[len-1] == '\n')
                    {
                        aname[len-1] = '\0';
                    }
                }
                struct address_t *temp;    
                temp=head;
                int q,r,t,s;
                char fname[20];
                int flag=0;       
                while(temp!=NULL)
                {   memset(fname,'\0',sizeof(fname));
                    char temp1[50]="",temp2[50]="";
                    sscanf(temp->data, "%d.%d.%d.%d %s",&q, &r ,&t, &s, fname);
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
                        flag=1;
                        printf("\n%d.%d.%d.%d\n",q,r,t,s);
                        break;
                    }
                    temp=temp->next;
                }
                if(flag==0)
                {
                    printf("Record doesn't exist\n");
                }
}
