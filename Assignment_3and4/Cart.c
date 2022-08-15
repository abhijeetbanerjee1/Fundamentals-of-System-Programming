#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql.h>
#include"main_header.h"

void my_shopping_cart(MYSQL *conn)
{
	int choice;
	
	ans:
	system("clear");
	printf("\n\n\tMy Shopping Cart");
	printf("\n1. Add a product to your cart.");
	printf("\n2. Display my cart.");
    printf("\n3. Go back to the previous menu");
    m:
	printf("\nEnter your choice: ");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:	addcart(conn);
				getchar();
                goto ans;
			break;
		
		case 2: display_cart(conn);
                getchar();
                goto ans;
			break;
        case 3: 
            break;
        default:printf("\n\nInvalid Input!!!");
            goto m;
        break;
	}
}

void addcart(MYSQL *conn)
{
    MYSQL_RES *result;
	MYSQL_ROW row;
	char query[200] = "";
    char query1[200] = "";
    char query2[200] = "";
	char product[20];
	char model[20];
    int quant;
	
	printf("\nAvailable Products");
	printf("\n--------------------------------\n");
	display(conn, "Available");
	printf("Enter the name of the product you want to add to cart: ");
	scanf("%s", &product);
	getchar();
	display_row(conn, product);
    printf("\n\n");
	display(conn, product);

	printf("\nEnter the Model number of the product you want to be added to your cart: ");	
	scanf("%s", &model);
	getchar();

    printf("Enter the quantity: ");
    scanf("%d", &quant);


	printf("\n");

	sprintf(query, "insert into Cart select Brand, Model, Price, Count from %s where Model = '%s'", product, model);
	if (mysql_query(conn, query))
	{
		show_error(conn);
	}
    sprintf(query1, "update Cart set Quantity = %d where Model = '%s'", quant, model);
    if (mysql_query(conn, query1))
	{
		show_error(conn);
	}
    sprintf(query2, "update Cart set Price = Price * %d where Model = '%s'", quant, model);
    if (mysql_query(conn, query2))
	{
		show_error(conn);
	}
	printf("\n\nProduct Successfully Added to your Cart.\n");

	display_row(conn, "Cart");
	printf("\n------------------------------------------------------\n");
	display(conn, "Cart");
    
	if (mysql_query(conn, "SELECT sum(Price) FROM Cart"))
	{
		show_error(conn);
	}
	result = mysql_store_result(conn);
    row = mysql_fetch_row(result);
    printf("\n\nYour total is $ %s.", row[0]);
	printf("\n\nPress enter key to go back to proceed.");
	getchar();
    mysql_free_result(result);
}

void print_bill(MYSQL *conn)
{
	MYSQL_RES *result;
	MYSQL_ROW row;
    int total;
	char query[200] = "";
	char product[20];
	char model[20];
    system("clear");
	display_row(conn, "Cart");
	printf("\n-------------------------------------------------------\n");
	display(conn, "Cart");
	char option;
    //char car;
	printf("\n\nThese are the products in your cart right now.");
	printf("\n\nDo you want to check out with these items[Y/N]: ");
	scanf(" %c", &option);
	getchar();
	
	FILE *fptr;
	if(option == 'Y')
    {
	fptr = fopen("invoice.txt","w");
	if(fptr == NULL)
	{
		printf("Error!");   
		exit(1);             
	}
	
	
	if (mysql_query(conn, "SELECT * FROM Cart"))
	{
		show_error(conn);
	}

	result = mysql_store_result(conn);
	int num_fields = mysql_num_fields(result);
    fprintf(fptr, "\n\t\tINVOICE");
	fprintf(fptr, "\n\n\nBrand          Model            Price          Quantity");
	fprintf(fptr, "\n-------------------------------------------------------\n");
	while ((row = mysql_fetch_row(result))) 
	{ 
		for(int i = 0; i < num_fields; i++) 
		{ 
			fprintf(fptr, "%-10s ", row[i]); 
			fprintf(fptr, "\t");
		} 
		fprintf(fptr, "\n\n");
	}
}
else{
return;
}
    if (mysql_query(conn, "SELECT sum(Price) FROM Cart"))
	{
		show_error(conn);
	}
	result = mysql_store_result(conn);
    row = mysql_fetch_row(result);
    fprintf(fptr, "\n\n\tYour total is $%s", row[0]);
    fprintf(fptr, "\n\n\tAdded Sales Tax 6%%.");
    total = atoi(row[0]);
    float sum = total + total * 0.06;
    fprintf(fptr, "\n\n\tAmount Due $%.2f", sum);
    fprintf(fptr,"\n\n\n\t\tTHANK YOU FOR SHOPPING !!!");
fclose(fptr);
	if (mysql_query(conn, "truncate table Cart"))
	{
		show_error(conn);
	}
    printf("\n\n\n\t\tTHANK YOU FOR SHOPPING !!!");
mysql_free_result(result);	
}

void display_cart(MYSQL *conn)
{
    char ans;
    MYSQL_RES *result;
	MYSQL_ROW row;
    
	if (mysql_query(conn, "SELECT * FROM Cart"))
	{
		show_error(conn);
	}
	result = mysql_store_result(conn);
    row = mysql_fetch_row(result);

    if(!row)
    {
        printf("\n\n\tYour Cart is Empty.");
        
    }
    else
    {
        display_row(conn, "Cart");
        printf("\n\n");
        display(conn, "Cart");
	    getchar();
        printf("\n\nDo you want to checkout ?");
	    printf("\n\nY/N ?: ");
	    scanf("%c", &ans);
	    if(ans == 'Y' )
	    {
		    print_bill(conn);
	    }
	    else
	    {
		    my_shopping_cart(conn);
	    }
    }
    printf("\n\nPress enter key to go back to proceed.");
    getchar();
    return;
    mysql_free_result(result);
}