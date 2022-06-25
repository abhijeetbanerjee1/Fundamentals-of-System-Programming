/* Name:- Abhijeet Amitava Banerjee
 * G-number:- G01349260 */

#include <stdio.h>
#include <string.h>

int val(char s[]);
char choose(char sr[][100], char ch);
void ascending(char stng[][100]);
void descending(char stg[][100]);

/*  This is the main function which takes ten strings as input from the user through a for loop and for every string we enter 
    it passes the string to the function val() and validates the input. If a error is found in the input, the flag1 is 
    set to a non-zero integer and this flag1 triggres a goto statement which tells the user to nput another stings The 
    main function also loosk for duplicate strings entered bu the user. It also askes the user to choose between Ascending and Descending, if users input is not recognized
    then a similar flag2 makes the user input the correct option. */
int main()
{
   int i, flag1, h, flag2=0;
   char st[10][100];
   char choice;
   
   //Input ten strings
   printf("Enter 10 unique strings with length from 1 to 25 without special characters.\n");
   for(i=0; i<10; i++)
   {
       ask_again:
       printf("Enter string no.%d :",i+1);
       fgets(st[i], 100, stdin);
       
       //Function call to validate user input
       flag1 = val(st[i]);
       if(flag1 != 0 )
       {
           goto ask_again;
       }
       
       //Look for duplication
       for(h=0; h<i; h++)
       {
           if(strcmp(st[i], st[h]) == 0)
           {
               printf("Error: Duplicate string detected.\nPlease enter again.\n");
               goto ask_again;
           }
       }
   }
   
   //Input for switch case
    printf("Choose A if you want the array of strings to be printed in Ascendeing order.\n");
    printf("Or choose D if you want the array of strings to be printed in Descending order.\n");
    
    chs:
    printf("Enter A or D:");
    scanf(" %c", &choice);
    
    //Function call for switch case
    flag2 = choose(st, choice);
    if (flag2 != 0)
    {
        printf("Error: Invalid input.\n");
        goto chs;
    }
    
}


/*  This is the 1st function outside the main function and it validates the input given by the user. It receives a string passed 
    by the main function and checks if the string entered is empty or if its strlen exceeds 25 or does the string contain any 
    specified special character. If for any such attribute an error is detected, it returns a non-zero value to flag1 in the 
    main function which triggers the goto statemet or if the input does not get any errors this function return 0 which does 
    not trigger the goto statement.*/
int val(char s[])
{
    int t = 0;
    char spl_char[] = "!@#$%^()"; //string of specific special characters
    int idx, len_s;
    
    //Replaces the new-line with null that is picked up by fgets after every string
    s[strcspn(s,"\n")] = '\0';
    
    //To detect empty string
    if(strlen(s)==0)
    {
        printf("Error: Empty string entered.\nPlease enter again.\n");
        t++;
        return t;
    } 
    
    //To detect if the string enteres has length greater than 25
    if(strlen(s) > 25)
    {
        printf("Error: String length exceeds 25.\nPlease enter again.\n");
        t++;
        return t;
    }
    
    //To detect special character in the String
    //If any such characters specified in the spl_chara string is found than strcspn would give the index of that character.
    //If not found than strcspn will just give the string length.
    len_s = strlen(s);
    idx = strcspn(s,spl_char);
    if(idx != len_s)
    {
        printf("Error: %c is an illegal character.\nPlease enter again.\n",s[idx]);
        t++;
        return t;
    }
  
  return 0;
}


/*  This is the 2nd function outside of the main function and if takes the choice entered by the user in the main() and uses
    it as input for switch case to choose between Ascending and Descending. It also takes the entier validated string which 
    is passed form main(), just to further pass it the ascending or and descending functions. It checks it the input choice 
    given by the user is ialid or not, if not then it uses a similar flag3 variable to trigger the goto statement to ask 
    another input from the user. */
char choose(char sr[][100], char ch)
{   int flag3=0; 
    
    switch(ch)
    {
        case 'A' :
        printf("In Ascending order.\n");
        ascending(sr);
        break;
        
        case 'D' :
        printf("In Descending order.\n");
        descending(sr);
        break;
        
        default:
        flag3++;
        return flag3;
        
    }
    return 0;
}

/*  This is the 3rd function outside the main function and it takes the entire validated string passed to it by choose() and
    uses bubble sort to sort the strings in ascending order and print them along with printing the strings with lowest and 
    highest ascii value. */
void ascending(char stng[][100])
{
    char temp[100];
    
    for(int x = 0; x<9; x++)
    {
        for(int y = 0; y<9-x; y++)
        {
            if(strcmp(stng[y],stng[y+1]) > 0)
            {
                // Swapping
                strcpy(temp, stng[y]);
                strcpy(stng[y], stng[y+1]);
                strcpy(stng[y+1], temp);
            }
        }
    }
    
    //Print the string in new order
    for(int j = 0; j<10; j++)
    {
        printf("%s\n",stng[j]);
    }
    
    //Print strings that have lowest and highest ascii value
    printf("The string with lowest ascci value is %s.\n",stng[0]);
    printf("And the string with highest ascii value is %s.\n",stng[9]);
}

/*  This is the 4rd and last function outside the main function and it takes the entire validated string passed to it by choose() and
    uses bubble sort to sort the strings in descending order and print them along with printing the strings with lowest and 
    highest ascii value. */
void descending(char stg[][100])
{
    char temp[100];
    for(int x=0; x<9; x++)
    {
        for(int y=0; y<9-x; y++)
        {
            if(strcmp(stg[y], stg[y+1]) < 0)
            {
                // Swapping
                strcpy(temp, stg[y]);
                strcpy(stg[y], stg[y+1]);
                strcpy(stg[y+1], temp);
            }
        }
    }
    
    //Print the string in new order
    for(int j = 0; j<10; j++)
    {
        printf("%s\n",stg[j]);
    }
    
    //Print strings that have lowest and highest ascii value
    printf("The string with lowest ascci value is %s.\n",stg[0]);
    printf("And the string with highest ascii value is %s.\n",stg[9]);
}

