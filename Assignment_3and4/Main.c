#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql.h>
#include"main_header.h"

int main()
{
	system("clear");
	MYSQL *conn;
	MYSQL_RES *result;
	MYSQL_ROW row;
	char *server = "helios.vse.gmu.edu";
	char *user = "abanerj";
	char *password = "sorsoons";
	char *database = "abanerj";
	conn = mysql_init(NULL);
    if (conn == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }
	if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0)) 
	{
		show_error(conn);
	}
	int choice;
    char pass[10];
pl:
do{	
    system("clear");
    printf("\n\tMain Menu");
    printf("\n1.Admin");
    printf("\n2.Search for Product");
    printf("\n3.My Shopping Cart");
    printf("\n4.Quit");
    printf("\n\nChoose an option from the above menu:");
    //pl:
    scanf("%d",&choice);
    
	switch (choice)
    {
        case 1: printf("\n\nEnter Your Admin Password: ");
                scanf(" %s", &pass);
                if(strcmp(pass, "1234")==0)
                {
                    admin(conn);
                }
                else{
                    printf("Incorrect Password !!!");
                }
                getchar();
                goto pl;
                break;
        
	case 2: search_prod(conn);
		getchar();
                break;
        
	case 3: my_shopping_cart(conn);
			getchar();
                break;
        
	case 4: printf("\nThank you\n");
		exit(1);
                break;
        
	default: printf("\nInvalid Input");
        	printf("\nPlease enter a valid input: ");
        	getchar();
		goto pl;
		break;
    }
}while(choice>=1 && choice<=4);
//mysql_free_result(result);
//mysql_close(conn);

    return EXIT_SUCCESS;
}

void show_error(MYSQL *conn)
{
    fprintf(stderr, "%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}