#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
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

void addaddress()
{
    char name[50];
    int a,b,c,d;
    printf("Enter your Address and alias pair: \n");
    char str[50];
    l:
    memset(str,'\0',sizeof(str));
    fgets(str,50,stdin);
    if (str[0]!='\0')
    {
        size_t len = strlen(str);
        if (len > 0 && str[len-1] == '\n')
        {
            str[len-1] = '\0';
        }
    }
    if(sscanf(str, "%d.%d.%d.%d %s",&a, &b ,&c, &d, name)!=5)
                    printf("Invalid Input");
                

                
                else
                {
                    if((a>=0 && a<256) && (b>=0 && b<256) && (c>=0 && c<256) && (d>=0 && d<256))
                    {
                        struct address_t *temp;    
                        temp=head;         
                        int flag=0;
                        while(temp!=NULL)
                        {
                            int w,x,y,z;
                            char temp1[50]="",temp2[50]="";
                            char aliasname[50];
                            memset(aliasname,'\0',sizeof(aliasname));
                            sscanf(temp->data, "%d.%d.%d.%d %s",&w, &x ,&y, &z, aliasname);
                            for(int i = 0; i<(strlen(aliasname)); i++) 
                            {
                                temp1[i] = tolower(aliasname[i]);
                            }
                            
                            for(int j=0; j<(strlen(name)); j++) 
                            {
                                temp2[j] = tolower(name[j]);
                            }
                            if(strcmp(temp1,temp2)==0 || (a==w && b==x && c==y && d==z))
                            {
                                flag=1;
                                printf("\nDuplicate record found\n");
                                
                                break;
                            }
                            else
                            {
                                temp=temp->next;
                            }
                        }
                        if(flag==0)
                        {
                            printf("\nRecord is inserted succesfully\n");
                            insert_node(str);
                        }
                    }
                    else
                    {
                        printf("\nInvalid size\n");
                        printf("please enter address again:\n");
                        goto l;
                    }

                }
                

}
