#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql.h>
#include"main_header.h"


void admin(MYSQL *conn)
{
	pos:
	system("clear");
    int choice;
    printf("\n\tAdmin");
    printf("\n1. Insert a Product");
    printf("\n2. Delete a Product");
    printf("\n3. Display Products");
	printf("\n4. Go back to Main Menu");
    printf("\n\nChoose an option from the above menu:");
    //pos:
    scanf("%d",&choice);
    
	switch(choice)
    	{
        	case 1: insert_product_info(conn);
			getchar();
        	break;
        
			case 2: delete_product_info(conn);
        		break;
        
			case 3: display_list_product(conn);
        		break;
			case 4:	
				break;
			default: printf("\nInvalid Choice");
        			printf("\nPlease enter a valid input.\n\n");
					getchar();
        			goto pos;
					break;
		}
}

void insert_product_info(MYSQL *conn)
{
    system("clear");
	MYSQL_RES *result;
	MYSQL_ROW row;
    char query[200] = "";
	char product[20];
	char attribute1[20];
	char attribute2[20];
	char attribute3[20];
	char attribute4[20];
	char attribute5[20];
	//char attribute6[20];
	int intattribute1;
	int intattribute2;
	int intattribute3;
	int intattribute4;
	int intattribute5;
	
	if (mysql_query(conn, "SELECT * FROM Available"))
	{
		show_error(conn);
	}

	result = mysql_store_result(conn);
	int num_fields = mysql_num_fields(result);
	printf("\tAvailable Products\n");
	printf("---------------------------------\n");
	while ((row = mysql_fetch_row(result))) { 
		for(int i = 0; i < num_fields; i++) 
		{ 
			printf("\t%s ", row[i]); 
		} 
		printf("\n"); 
	}
	la:
	printf("\n\nEnter the name of the product in which you want to insert: ");
	scanf("%s", &product);
	
	//Insert for Refrigerator
	if(strcmp(product, "Refrigerator") == 0)
	{
		printf("\nPlease fill the required information about the product.");
	
		printf("\n\nEnter Brand name: ");
		scanf("%s", &attribute1);
	
		printf("\nEnter Model number: ");
		scanf("%s", &attribute2);

		printf("\nEnter Total Capacity (cu.ft.): ");
		scanf("%d", &intattribute1);

		printf("\nEnter Door type: ");
		scanf("%s", &attribute3);
	
		printf("\nEnter Condition (New/Used): ");
		scanf("%s", &attribute4);

		printf("\nEnter Price($): ");
		scanf("%d", &intattribute2);
	
		printf("\nEnter Count: ");
		scanf("%d", &intattribute3);

		sprintf(query, "insert into %s values('%s', '%s', %d, '%s', '%s', %d, %d)", product, attribute1, attribute2, intattribute1, attribute3, attribute4, intattribute2, intattribute3);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
		
		printf("\nNew product Inserted Successfully !\n\n");
		display_row(conn, product);
		printf("\n");
		display(conn, product); 
	}

	//Insert for Laundry Washer
	else if(strcmp(product, "Laundry_Washer") == 0)
	{
		printf("\nPlease fill the required information about the product.");

		printf("\n\nEnter Brand name: ");
		scanf("%s", &attribute1);
	
		printf("\nEnter Model number: ");
		scanf("%s", &attribute2);

		printf("\nEnter Total Capacity (cu.ft.): ");
		scanf("%d", &intattribute1);

		printf("\nEnter Load Type: ");
		scanf("%s", &attribute3);
	
		printf("\nEnter Yes/No for Stackability: ");
		scanf("%s", &attribute4);
	
		printf("\nEnter Condition (New/Used): ");
		scanf("%s", &attribute5);

		printf("\nEnter Price ($): ");
		scanf("%d", &intattribute2);
	
		printf("\nEnter Count: ");
		scanf("%d", &intattribute3);
	
		sprintf(query, "insert into %s values('%s', '%s', %d, '%s', '%s', '%s', %d, %d)", product, attribute1, attribute2, intattribute1, attribute3, attribute4, attribute5, intattribute2, intattribute3);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}	
		printf("\nNew product Inserted Successfully !\n\n");
		display_row(conn, product);
		printf("\n");
		display(conn, product);
	}

	//Insert for Laundry Dryer
	else if(strcmp(product, "Laundry_Dryer") == 0)
	{
		printf("\nPlease fill the required information about the product.");
	
		printf("\n\nEnter Brand name: ");
		scanf("%s", &attribute1);
	
		printf("\nEnter Model number: ");
		scanf("%s", &attribute2);

		printf("\nEnter Total Capacity (cu.ft.): ");
		scanf("%d", &intattribute1);

		printf("\nEnter Load Type: ");
		scanf("%s", &attribute3);
	
		printf("\nEnter Yes/No for Stackability: ");
		scanf("%s", &attribute4);
	
		printf("\nEnter Condition (New/Used): ");
		scanf("%s", &attribute5);

		printf("\nEnter Price ($): ");
		scanf("%d", &intattribute2);
	
		printf("\nEnter Count: ");
		scanf("%d", &intattribute3);
	
		sprintf(query, "insert into %s values('%s', '%s', %d, '%s', '%s', '%s', %d, %d)", product, attribute1, attribute2, intattribute1, attribute3, attribute4, attribute5, intattribute2, intattribute3);
		if (mysql_query(conn, query))
		{
		show_error(conn);
		}	
		printf("\nNew product Inserted Successfully !\n\n");
		display_row(conn, product);
		printf("\n");
		display(conn, product);
	}

	//Insert for Microwave
	else if(strcmp(product, "Microwave") == 0)
	{
		printf("\nPlease fill the required information about the product.");
	
		printf("\n\nEnter Brand name: ");
		scanf("%s", &attribute1);
	
		printf("\nEnter Model number: ");
		scanf("%s", &attribute2);

		printf("\nEnter Total Capacity (cu.ft.): ");
		scanf("%d", &intattribute1);

		printf("\nEnter Door Type: ");
		scanf("%s", &attribute3);
	
		printf("\nEnter Condition (New/Used): ");
		scanf("%s", &attribute4);

		printf("\nEnter Price ($): ");
		scanf("%d", &intattribute2);
	
		printf("\nEnter Count: ");
		scanf("%d", &intattribute3);
		sprintf(query, "insert into %s values('%s', '%s', %d, '%s', '%s', %d, %d)", product, attribute1, attribute2, intattribute1, attribute3, attribute4, intattribute2, intattribute3);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
		printf("\nNew product Inserted Successfully !\n\n");
		display_row(conn, product);
		printf("\n");
		display(conn, product);
	}
	
	//Insert for Laptops
	else if(strcmp(product, "Laptops") == 0)
	{
		printf("\nPlease fill the required information about the product.");

		printf("\n\nEnter Brand name: ");
		scanf("%s", &attribute1);
	
		printf("\nEnter Model number: ");
		scanf("%s", &attribute2);

		printf("\nEnter Processor name: ");
		scanf("%s", &attribute3);

		printf("\nEnter Operating System: ");
		scanf("%s", &attribute4);
	
		printf("\nEnter Ram size (gb): ");
		scanf("%d", &intattribute1);

		printf("\nEnter Storage size (gb): ");
		scanf("%d", &intattribute2);
	
		printf("\nEnter Condition (New/Used): ");
		scanf("%s", &attribute5);

		printf("\nEnter Price ($): ");
		scanf("%d", &intattribute3);

		printf("\nEnter Count: ");
		scanf("%d", &intattribute4);

		sprintf(query, "insert into %s values('%s', '%s', '%s','%s', %d, %d, '%s', %d, %d)", product, attribute1, attribute2, attribute3, attribute4, intattribute1, intattribute2, attribute5, intattribute3, intattribute4);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
		printf("\nNew product Inserted Successfully !\n\n");
		display_row(conn, product);
		printf("\n");
		display(conn, product);
	}

	//Insert for Phone
	else if(strcmp(product, "Phone") == 0)
	{
		printf("\nPlease fill the required information about the product.");

		printf("\n\nEnter Brand name: ");
		scanf("%s", &attribute1);
	
		printf("\nEnter Model number: ");
		scanf("%s", &attribute2);
	
		printf("\nEnter Ram size (gb): ");
		scanf("%d", &intattribute1);
	
			printf("\nEnter Storage size (gb): ");
		scanf("%d", &intattribute2);
	
		printf("\nEnter Operating System: ");
		scanf("%s", &attribute3);

		printf("\nEnter Condition (New/Used): ");
		scanf("%s", &attribute4);

		printf("\nEnter Price ($): ");
		scanf("%d", &intattribute3);

		printf("\nEnter Count: ");
		scanf("%d", &intattribute4);

		sprintf(query, "insert into %s values('%s', '%s', %d, %d, '%s', '%s', %d, %d)", product, attribute1, attribute2, intattribute1, intattribute2, attribute3, attribute4, intattribute3, intattribute4);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
		printf("\nNew product Inserted Successfully !\n\n");
		display_row(conn, product);
		printf("\n");
		display(conn, product);
	}

	//Insert for Watches
	else if(strcmp(product, "Watches") == 0)
	{
		printf("\nPlease fill the required information about the product.");

		printf("\n\nEnter Brand name: ");
		scanf("%s", &attribute1);
	
		printf("\nEnter Model number: ");
		scanf("%s", &attribute2);
	
		printf("\nEnter the type of watch strap: ");
		scanf("%s", &attribute3);
	
		printf("\nEnter Color of the watch: ");
		scanf("%s", &attribute4);

		printf("\nEnter Condition (New/Used): ");
		scanf("%s", &attribute5);

		printf("\nEnter Price ($): ");
		scanf("%d", &intattribute1);

		printf("\nEnter Count: ");
		scanf("%d", &intattribute2);

		sprintf(query, "insert into %s values('%s', '%s','%s', '%s', '%s', %d, %d)", product, attribute1, attribute2, attribute3, attribute4, attribute5, intattribute1, intattribute2);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
		printf("\nNew product Inserted Successfully !\n\n");
		display_row(conn, product);
		printf("\n");
		display(conn, product);
	}
	
	//Insert for Camera
	else if(strcmp(product, "Camera") == 0)
	{
		printf("\nPlease fill the required information about the product.");

		printf("\n\nEnter Brand name: ");
		scanf("%s", &attribute1);
	
		printf("\nEnter Model number: ");
		scanf("%s", &attribute2);
	
		printf("\nEnter the number of Pixels: ");
		scanf("%s", &attribute3);

		printf("\nEnter Storage size (gb): ");
		scanf("%d", &intattribute1);

		printf("\nEnter Condition (New/Used): ");
		scanf("%s", &attribute4);

		printf("\nEnter Price ($): ");
		scanf("%d", &intattribute2);

		printf("\nEnter Count: ");
		scanf("%d", &intattribute3);

		sprintf(query, "insert into %s values('%s', '%s','%s', %d, '%s', %d, %d)", product, attribute1, attribute2, attribute3, intattribute1, attribute4, intattribute2, intattribute3 );
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
		printf("\nNew product Inserted Successfully !\n\n");
		display_row(conn, product);
		printf("\n");
		display(conn, product);
	}

	else
	{
		printf("\n\nInvalid Input!!!");
		goto la;
	}

	printf("Press enter key to go back to the main menu.");
	getchar();
	mysql_free_result(result);
}

void delete_product_info(MYSQL *conn)
{
        system("clear");
        int choice;
        printf("\tDelete Product Info");
        printf("\n1. Delete product");
        printf("\n2. Delete product item");
		printf("\n3. Go to the previous menu");
        printf("\n\nEnter an option from the above menu:");
        loc:
        scanf("%d",&choice);
        
		switch(choice)
        {
        	case 1: delete_product(conn);
				getchar();
        	break;
        
			case 2: delete_product_item(conn);
				getchar();
        	break;

			case 3: return admin(conn);
			//break;
        
			default: printf("\n\nInvalid Choice");
        			printf("\n\nPlease enter a valid input.\n");
        			goto loc;
			break;
        }
}

void delete_product(MYSQL *conn)
{
	char query[200] = "";
	char product[20];
	MYSQL_RES *result;
	MYSQL_ROW row;
	
	printf("\tAvailable Products\n");
	printf("---------------------------------\n");
	display(conn, "Available");
	

	printf("\n\nEnter the name of the product you want to delete: ");
	scanf("%s", &product);
	sprintf(query, "drop table %s", product);
	if (mysql_query(conn, query)) 
	{
		show_error(conn);
	}

	sprintf(query, "delete from Available where (products = '%s')", product);
	if (mysql_query(conn, query)) 
	{
		show_error(conn);
	}
	
	printf("\n\nThe product %s has been deleted successfully!", product);
	printf("\n\nPress enter key to return to the main menu.");
	getchar();
	//mysql_free_result(result);
}

void delete_product_item(MYSQL *conn)
{
	char query[200] = "";
	char item[20];	
	char model[20];
	MYSQL_RES *result;
	MYSQL_ROW row;
	
	printf("\tAvailable Products\n");
	printf("---------------------------------\n");
	display(conn, "Available");

	printf("Enter the name of the product whose item you want to delete: ");
	scanf("%s", &item);
	
	display_row(conn, item);
	printf("\n\n");
	display(conn, item);

	printf("Enter the model number of the item you want to delete: ");
	scanf("%s", &model);
	
	sprintf(query, "delete from %s where (Model = '%s')", item, model);
	if (mysql_query(conn, query))
	{
		show_error(conn);
	}
	
	printf("\n\nThe item with model number %s has been deleted successfully!", model);
	printf("\n\nPress enter key to return to the main menu.");
	getchar();
	//mysql_free_result(result);
}

void display_list_product(MYSQL *conn)
{
        system("clear");
        int choice;
        printf("\tDisplay List of Product");
        printf("\n1. Display number of product");
        printf("\n2. Display product details");
		printf("\n3. Go back to the previous menu");	
        printf("\nEnter an option from the above menu:");
        checkpoint:
        scanf("%d",&choice);
        
		switch(choice)
        {
        	case 1: display_num_prod(conn);
			getchar();
        	break;
        
			case 2: display_prod_details(conn);
			getchar();
        	break;
        
			case 3: return admin(conn);
			break;
			default: printf("\nInvalid Choice");
        	printf("\nPlease enter a valid input: ");
        	goto checkpoint; 
			break;
        }
}

void display_prod_details(MYSQL *conn)
{
	system("clear");
	char product[20];
	printf("\n\nThe list of currently available products:");
	printf("\n\n\tAvailable Products");
	printf("\n--------------------------------\n");
	display(conn, "Available");
	getchar();

	printf("Enter the product whose details you want to see: ");
	scanf("%s", &product);
	printf("\n\n\n");
	display_row(conn, product);
	printf("\n\n");
	display(conn, product);
	printf("\n\nPress enter to go to the main menu.");
	getchar();
}

void display_num_prod(MYSQL *conn)
{
	MYSQL_RES *result;
	MYSQL_ROW row;
	char query[200] = "";
	char product[20];
	printf("\n\n\tAvailable Products");
	printf("\n-----------------------------\n");
	display(conn, "Available");
	printf("\n\nEnter the product to see its count: ");
	scanf("%s", &product);
	getchar();
	sprintf(query,"select sum(Count) from %s",product);
	if (mysql_query(conn, query))
	{
		show_error(conn);
	}
	result = mysql_store_result(conn);
	row = mysql_fetch_row(result);
	printf("\n\nThe total count of %s available is %s.\n\n", product, row[0]);
	
	sprintf(query,"select Brand, count(*) from %s group by Brand", product);
	if (mysql_query(conn, query))
	{
		show_error(conn);
	}
	result = mysql_store_result(conn);
	int num_fields = mysql_num_fields(result);
	printf("\n\nBrand          Count\n");
	printf("-------------------------\n");
	while ((row = mysql_fetch_row(result))) 
	{ 
		for(int i = 0; i < num_fields; i++) 
		{ 
			printf("%-10s ", row[i]); 
			printf("\t");
		} 
		printf("\n\n"); 
	}
	printf("\n\nPress enter to go to the main menu.");
	//getchar();
mysql_free_result(result);
}
