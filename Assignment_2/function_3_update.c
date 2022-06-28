#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

void updateaddress()
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
                struct address_t *temp;
                struct address_t *update;    
                temp=head;
                int q,r,t,s;
                char fname[20];
                int flag=0;       
                while(temp!=NULL)
                {
                    memset(fname,'\0',sizeof(fname));
                    sscanf(temp->data, "%d.%d.%d.%d %s",&q, &r ,&t, &s, fname);
                    char temp1[50]="",temp2[50]="";
                    for(int i = 0; i<(strlen(fname)); i++) 
                        {
                            temp1[i] = tolower(fname[i]);
                        }
                        //temp1[strlen(temp1)-1]=='\0';
                        for(int j=0; j<(strlen(aname)); j++) 
                        {
                            temp2[j] = tolower(aname[j]);
                        }
                    if(strcmp(temp1,temp2)==0)
                    {
                        flag=1;
                        printf("\n%d.%d.%d.%d\n",q,r,t,s);
                        update=temp;
                        break;
                    }
                temp=temp->next;
                }
                if(flag==0)
                {
                    printf("Record doesn't exist\n");
                }
                else
                {
                    printf("Enter the address to be updated\n");
                    char newadd[20];
                    int q1,q2,q3,q4;

                    blah:
                    memset(newadd,'\0',sizeof(newadd));
                    if (fgets(newadd, sizeof newadd, stdin) != NULL)
                    {
                    size_t len = strlen(newadd);
                        if (len > 0 && newadd[len-1] == '\n')
                        {
                            newadd[--len] = '\0';
                        }
                    }
                    sscanf(newadd,"%d.%d.%d.%d",&q1,&q2,&q3,&q4);
                    if((q1>=0 && q1<256) && (q2>=0 && q2<256) && (q3>=0 && q3<256) && (q4>=0 && q4<256))
                    {

                        int q,r,t,s;
                        int flag1=0;
                        char gname[20];
                        while(temp!=NULL)
                        {

                            sscanf(temp->data, "%d.%d.%d.%d %s",&q, &r ,&t, &s, gname);
                            if((q1==q && q2==r && q3==t && q4==s))
                            {
                                flag1=1;
                                printf("\nAddress already exists!!\n");
                                //goto down;
                            }
                            temp=temp->next;
                        }
                        if(flag1==0)
                        {
                            char new[50]="";
                            sprintf(new,"%d.%d.%d.%d %s",q1,q2,q3,q4,aname);

                            strcpy(update->data,new);
                            printf("\nRecord updated!!");
                            
                        }
                    }
                    else
                    {
                        printf("\nError!! Invalid size..\n");
                        printf("please Enter the address again: ");
                        goto blah;
                    }
                }
                
}
