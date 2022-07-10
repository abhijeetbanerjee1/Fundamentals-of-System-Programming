#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql.h>
#include"main_header.h"

void search_prod(MYSQL *conn)
{
	MYSQL_RES *result;
	MYSQL_ROW row;
	char query[200] = "";
	char product[20];
	char brand[20];
	char cond[20];
	char processor[20];
	char os[20];
	char storage[20];
	char ram[20];
	char strap[20];
	int choice;
    int num_fields;
	printf("\tAvailable Products\n");
	printf("---------------------------------\n");
    display(conn, "Available");
    op:
	printf("Enter the product you want to search: ");
	scanf("%s", &product);
	getchar();
	//if(strcmp(product, "Refrigerator")==0 || strcmp(product, "laundry_washer")==0 || strcmp(product, "laundry_dryer")==0 || strcmp(product, "Microwave")==0)
	if(strcmp(product, "Laundry_Washer")==0 || strcmp(product, "Refrigerator")==0 || strcmp(product, "Laundry_Dryer")==0 || strcmp(product, "Microwave")==0)
	{
		//Brands
		printf("\n\n\tAvailable Brands");
		printf("\n----------------------------\n");
		sprintf(query,"select distinct Brand from %s", product);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
	
		result = mysql_store_result(conn);
		num_fields = mysql_num_fields(result);
	
		while ((row = mysql_fetch_row(result))) 
		{ 
			for(int i = 0; i < num_fields; i++) 
			{ 
				printf("\t%-10s ", row[i]); 
				printf("\t");
			} 
			printf("\n"); 
		}
		//Condition
		printf("\n\n\tConditions");
		printf("\n----------------------------\n");
		sprintf(query,"select distinct Condition_ from %s", product);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
	
		result = mysql_store_result(conn);
		num_fields = mysql_num_fields(result);
	
		while ((row = mysql_fetch_row(result))) 
		{ 
			for(int i = 0; i < num_fields; i++) 
			{ 
				printf("\t%-10s ", row[i]); 
				printf("\t");
			}	 
			printf("\n"); 
		}
		printf("\nFilter by...");
		printf("\n1. Brand");
		printf("\n2. Condition");
        l:
		printf("\nChoose an option from the table: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:	printf("Enter Brand name: ");
				scanf("%s", &brand);
                display_row(conn, product);
                printf("\n\n");
				sprintf(query, "select * from %s where Brand = '%s'",product, brand);
				if (mysql_query(conn, query))
				{
					show_error(conn);
				}
				result = mysql_store_result(conn);
				num_fields = mysql_num_fields(result);
	
				while ((row = mysql_fetch_row(result))) 
				{ 
					for(int i = 0; i < num_fields; i++) 
					{ 
						printf("%-15s ", row[i]); 
						//printf("\t");
					} 
					printf("\n\n"); 
				}
			break;
		
			case 2:	printf("Enter Condition: ");
				scanf("%s", &cond);
                display_row(conn, product);
                printf("\n\n");
				sprintf(query, "select * from %s where Condition_ = '%s'",product, cond);
				if (mysql_query(conn, query))
				{
					show_error(conn);
				}
				result = mysql_store_result(conn);
				num_fields = mysql_num_fields(result);
	
				while ((row = mysql_fetch_row(result))) 
				{ 
					for(int i = 0; i < num_fields; i++) 
					{ 
						printf("%-15s ", row[i]); 
						//printf("\t");
					} 
					printf("\n\n"); 
				}
			break;
            default: printf("Invalid Input!!!");
                    goto l;
                break;
		}
	}
	else if(strcmp(product, "Laptops")==0)
	{	
		//Brands
		printf("\n\n\tAvailable Brands");
		printf("\n----------------------------\n");
		sprintf(query,"select distinct Brand from %s", product);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
	
		result = mysql_store_result(conn);
		num_fields = mysql_num_fields(result);
	
		while ((row = mysql_fetch_row(result))) 
		{ 
			for(int i = 0; i < num_fields; i++) 
			{ 
				printf("\t%-10s ", row[i]); 
				printf("\t");
			} 
			printf("\n"); 
		}
		//Condition
		printf("\n\n\tCondition");
		printf("\n----------------------------\n");
		sprintf(query,"select distinct Condition_ from %s", product);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
	
		result = mysql_store_result(conn);
		num_fields = mysql_num_fields(result);
	
		while ((row = mysql_fetch_row(result))) 
		{ 
			for(int i = 0; i < num_fields; i++) 
			{ 
				printf("\t%-10s ", row[i]); 
				printf("\t");
			} 
			printf("\n"); 
		}
		//Processors
		printf("\n\n\tAvailable Processors");
		printf("\n----------------------------\n");
		sprintf(query,"select distinct Processor from %s", product);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
	
		result = mysql_store_result(conn);
		num_fields = mysql_num_fields(result);
	
		while ((row = mysql_fetch_row(result))) 
		{ 
			for(int i = 0; i < num_fields; i++) 
			{ 
				printf("\t%-10s ", row[i]); 
				printf("\t");
			} 
			printf("\n"); 
		}
	
		//Operating System
		printf("\n\n\tAvailable Operating Systems");
		printf("\n----------------------------\n");
		sprintf(query,"select distinct OS from %s", product);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
	
		result = mysql_store_result(conn);
		num_fields = mysql_num_fields(result);
	
		while ((row = mysql_fetch_row(result))) 
		{	 
			for(int i = 0; i < num_fields; i++) 
			{ 
				printf("\t%-10s ", row[i]); 
				printf("\t");
			} 
			printf("\n"); 
		}


		printf("\nFilter by...");
		printf("\n1. Brand");
		printf("\n2. Condition");
		printf("\n3. Processor");
		printf("\n4. Operating System");
        al:
		printf("\nChoose an option from the table: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:	printf("Enter Brand name: ");
					scanf("%s", &brand);
                    display_row(conn, product);
                    printf("\n\n");
					sprintf(query, "select * from %s where Brand = '%s'",product, brand);
					if (mysql_query(conn, query))
					{
						show_error(conn);
					}
					result = mysql_store_result(conn);
					num_fields = mysql_num_fields(result);

					while ((row = mysql_fetch_row(result))) 
					{ 
						for(int i = 0; i < num_fields; i++) 
						{ 
							printf("%-15s ", row[i]); 
							//printf("\t");
						} 
						printf("\n\n"); 
					}

				break;
			case 2:	printf("Enter Condition: ");
					scanf("%s", &cond);
                    display_row(conn, product);
                    printf("\n\n");
					sprintf(query, "select * from %s where Condition_ = '%s'",product, cond);
					if (mysql_query(conn, query))
					{
						show_error(conn);
					}
					result = mysql_store_result(conn);
					num_fields = mysql_num_fields(result);
	
					while ((row = mysql_fetch_row(result))) 
					{ 
						for(int i = 0; i < num_fields; i++) 
						{ 
							printf("%-15s ", row[i]); 
							//printf("\t");
						} 
						printf("\n\n"); 
					}

				break;

	
			case 3: printf("Enter Processor: ");
					scanf("%s", &processor);
                    display_row(conn, product);
                    printf("\n\n");
					sprintf(query, "select * from %s where Processor = '%s'",product, processor);
					if (mysql_query(conn, query))
					{
						show_error(conn);
					}
					result = mysql_store_result(conn);
					num_fields = mysql_num_fields(result);

					while ((row = mysql_fetch_row(result))) 
					{ 
						for(int i = 0; i < num_fields; i++) 
						{ 
							printf("%-15s ", row[i]); 
							//printf("\t");
						} 
						printf("\n\n"); 
					}
				break;
	
			case 4: printf("Enter Operating System: ");
					scanf("%s", &os);
                    display_row(conn, product);
                    printf("\n\n");
					sprintf(query, "select * from %s where OS = '%s'",product, os);
					if (mysql_query(conn, query))
					{
						show_error(conn);
					}
					result = mysql_store_result(conn);
					num_fields = mysql_num_fields(result);
	
					while ((row = mysql_fetch_row(result))) 
					{ 
						for(int i = 0; i < num_fields; i++) 
						{ 
							printf("%-15s ", row[i]); 
							//printf("\t");
						} 
						printf("\n\n"); 
					}
				break;
                default: printf("Invalid Input!!!");
                    goto al;
                break;
		}
	}

	else if(strcmp(product, "Camera") == 0)
	{
		//Brands
		printf("\n\n\tAvailable Brands");
		printf("\n----------------------------\n");
		sprintf(query,"select distinct Brand from %s", product);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
	
		result = mysql_store_result(conn);
		num_fields = mysql_num_fields(result);
	
		while ((row = mysql_fetch_row(result))) 
		{ 
			for(int i = 0; i < num_fields; i++) 
			{ 
				printf("\t%-10s ", row[i]); 
				printf("\t");
			} 
			printf("\n"); 
		}
		//Condition
		printf("\n\n\tCondition");
		printf("\n----------------------------\n");
		sprintf(query,"select distinct Condition_ from %s", product);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
	
		result = mysql_store_result(conn);
		num_fields = mysql_num_fields(result);
	
		while ((row = mysql_fetch_row(result))) 
		{ 
			for(int i = 0; i < num_fields; i++) 
			{ 
				printf("\t%-10s ", row[i]); 
				printf("\t");
			} 
			printf("\n"); 
		}
		//Storage
		printf("\n\n\tStorage Size in GB");
		printf("\n----------------------------\n");
		sprintf(query,"select distinct Storage from %s", product);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
	
		result = mysql_store_result(conn);
		num_fields = mysql_num_fields(result);
	
		while ((row = mysql_fetch_row(result))) 
		{ 
			for(int i = 0; i < num_fields; i++) 
			{ 
				printf("\t%-10s ", row[i]); 
				printf("\t");
			} 
			printf("\n"); 
		}
		
		printf("\nFilter by...");
		printf("\n1. Brand");
		printf("\n2. Condition");
		printf("\n3. Storage Size");
		aal:
		printf("\nChoose an option from the table: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:	printf("Enter Brand name: ");
					scanf("%s", &brand);
                    display_row(conn, product);
                    printf("\n\n");
					sprintf(query, "select * from %s where Brand = '%s'",product, brand);
					if (mysql_query(conn, query))
					{
						show_error(conn);
					}
					result = mysql_store_result(conn);
					num_fields = mysql_num_fields(result);

					while ((row = mysql_fetch_row(result))) 
					{ 
						for(int i = 0; i < num_fields; i++) 
						{ 
							printf("%-15s ", row[i]); 
							//printf("\t");
						} 
						printf("\n\n"); 
					}

				break;
			case 2:	printf("Enter Condition: ");
					scanf("%s", &cond);
                    display_row(conn, product);
                    printf("\n\n");
					sprintf(query, "select * from %s where Condition_ = '%s'",product, cond);
					if (mysql_query(conn, query))
					{
						show_error(conn);
					}
					result = mysql_store_result(conn);
					num_fields = mysql_num_fields(result);
	
					while ((row = mysql_fetch_row(result))) 
					{ 
						for(int i = 0; i < num_fields; i++) 
						{ 
							printf("%-15s ", row[i]); 
							//printf("\t");
						} 
						printf("\n\n"); 
					}

				break;

	
			case 3: printf("Enter Storage Size in GB: ");
					scanf("%s", &storage);
                    display_row(conn, product);
                    printf("\n\n");
					sprintf(query, "select * from %s where Storage = '%s'",product, storage);
					if (mysql_query(conn, query))
					{
						show_error(conn);
					}
					result = mysql_store_result(conn);
					num_fields = mysql_num_fields(result);

					while ((row = mysql_fetch_row(result))) 
					{ 
						for(int i = 0; i < num_fields; i++) 
						{ 
							printf("%-15s ", row[i]); 
							//printf("\t");
						} 
						printf("\n\n"); 
					}
				break;
                default: printf("Invalid Input!!!");
                    goto aal;
                break;
		}
	}


	else if (strcmp(product, "Phone") == 0)
	{
		printf("\n\n\tAvailable Brands");
		printf("\n----------------------------\n");
		sprintf(query,"select distinct Brand from %s", product);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
	
		result = mysql_store_result(conn);
		num_fields = mysql_num_fields(result);
	
		while ((row = mysql_fetch_row(result))) 
		{ 
			for(int i = 0; i < num_fields; i++) 
			{ 
				printf("\t%-10s ", row[i]); 
				printf("\t");
			} 
			printf("\n"); 
		}

		//Condition
		printf("\n\n\tCondition");
		printf("\n----------------------------\n");
		sprintf(query,"select distinct Condition_ from %s", product);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
	
		result = mysql_store_result(conn);
		num_fields = mysql_num_fields(result);
	
		while ((row = mysql_fetch_row(result))) 
		{ 
			for(int i = 0; i < num_fields; i++) 
			{ 
				printf("\t%-10s ", row[i]); 
				printf("\t");
			} 
			printf("\n"); 
		}
		//Storage
		printf("\n\n\tStorage Size in GB");
		printf("\n----------------------------\n");
		sprintf(query,"select distinct Storage from %s", product);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
	
		result = mysql_store_result(conn);
		num_fields = mysql_num_fields(result);
	
		while ((row = mysql_fetch_row(result))) 
		{ 
			for(int i = 0; i < num_fields; i++) 
			{ 
				printf("\t%-10s ", row[i]); 
				printf("\t");
			} 
			printf("\n"); 
		}

		//Ram
		printf("\n\n\tRam Size in GB");
		printf("\n----------------------------\n");
		sprintf(query,"select distinct Ram from %s", product);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
	
		result = mysql_store_result(conn);
		num_fields = mysql_num_fields(result);
	
		while ((row = mysql_fetch_row(result))) 
		{ 
			for(int i = 0; i < num_fields; i++) 
			{ 
				printf("\t%-10s ", row[i]); 
				printf("\t");
			} 
			printf("\n"); 
		}

		printf("\nFilter by...");
		printf("\n1. Brand");
		printf("\n2. Condition");
		printf("\n3. Storage Size");
		printf("\n4. Ram Size");
		all:
		printf("\nChoose an option from the table: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:	printf("Enter Brand name: ");
					scanf("%s", &brand);
                    display_row(conn, product);
                    printf("\n\n");
					sprintf(query, "select * from %s where Brand = '%s'",product, brand);
					if (mysql_query(conn, query))
					{
						show_error(conn);
					}
					result = mysql_store_result(conn);
					num_fields = mysql_num_fields(result);

					while ((row = mysql_fetch_row(result))) 
					{ 
						for(int i = 0; i < num_fields; i++) 
						{ 
							printf("%-15s ", row[i]); 
							//printf("\t");
						} 
						printf("\n\n"); 
					}

				break;
			case 2:	printf("Enter Condition: ");
					scanf("%s", &cond);
                    display_row(conn, product);
                    printf("\n\n");
					sprintf(query, "select * from %s where Condition_ = '%s'",product, cond);
					if (mysql_query(conn, query))
					{
						show_error(conn);
					}
					result = mysql_store_result(conn);
					num_fields = mysql_num_fields(result);
	
					while ((row = mysql_fetch_row(result))) 
					{ 
						for(int i = 0; i < num_fields; i++) 
						{ 
							printf("%-15s ", row[i]); 
							//printf("\t");
						} 
						printf("\n\n"); 
					}

				break;

	
			case 3: printf("Enter Storage Size in GB: ");
					scanf("%s", &storage);
                    display_row(conn, product);
                    printf("\n\n");
					sprintf(query, "select * from %s where Storage = '%s'",product, storage);
					if (mysql_query(conn, query))
					{
						show_error(conn);
					}
					result = mysql_store_result(conn);
					num_fields = mysql_num_fields(result);

					while ((row = mysql_fetch_row(result))) 
					{ 
						for(int i = 0; i < num_fields; i++) 
						{ 
							printf("%-15s ", row[i]); 
							//printf("\t");
						} 
						printf("\n\n"); 
					}
				break;
			case 4: printf("Enter Ram Size in GB: ");
					scanf("%s", &ram);
                    display_row(conn, product);
                    printf("\n\n");
					sprintf(query, "select * from %s where Ram = '%s'",product, ram);
					if (mysql_query(conn, query))
					{
						show_error(conn);
					}
					result = mysql_store_result(conn);
					num_fields = mysql_num_fields(result);

					while ((row = mysql_fetch_row(result))) 
					{ 
						for(int i = 0; i < num_fields; i++) 
						{ 
							printf("%-15s ", row[i]); 
							//printf("\t");
						} 
						printf("\n\n"); 
					}
				break;
                default: printf("Invalid Input!!!");
                    goto all;
                break;
		}
	}
	else if(strcmp(product, "Watches") == 0)
	{
		printf("\n\n\tAvailable Brands");
		printf("\n----------------------------\n");
		sprintf(query,"select distinct Brand from %s", product);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
	
		result = mysql_store_result(conn);
		num_fields = mysql_num_fields(result);
	
		while ((row = mysql_fetch_row(result))) 
		{ 
			for(int i = 0; i < num_fields; i++) 
			{ 
				printf("\t%-10s ", row[i]); 
				printf("\t");
			} 
			printf("\n"); 
		}

		//Condition
		printf("\n\n\tCondition");
		printf("\n----------------------------\n");
		sprintf(query,"select distinct Condition_ from %s", product);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
	
		result = mysql_store_result(conn);
		num_fields = mysql_num_fields(result);
	
		while ((row = mysql_fetch_row(result))) 
		{ 
			for(int i = 0; i < num_fields; i++) 
			{ 
				printf("\t%-10s ", row[i]); 
				printf("\t");
			} 
			printf("\n"); 
		}

		//Watch Strap
		printf("\n\n\tWatch Strap Material");
		printf("\n----------------------------\n");
		sprintf(query,"select distinct Watch_Strap from %s", product);
		if (mysql_query(conn, query))
		{
			show_error(conn);
		}
	
		result = mysql_store_result(conn);
		num_fields = mysql_num_fields(result);
	
		while ((row = mysql_fetch_row(result))) 
		{ 
			for(int i = 0; i < num_fields; i++) 
			{ 
				printf("\t%-10s ", row[i]); 
				printf("\t");
			} 
			printf("\n"); 
		}

		printf("\nFilter by...");
		printf("\n1. Brand");
		printf("\n2. Condition");
		printf("\n3. Watch Strap Material");
		aall:
		printf("\nChoose an option from the table: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:	printf("Enter Brand name: ");
					scanf("%s", &brand);
                    display_row(conn, product);
                    printf("\n\n");
					sprintf(query, "select * from %s where Brand = '%s'",product, brand);
					if (mysql_query(conn, query))
					{
						show_error(conn);
					}
					result = mysql_store_result(conn);
					num_fields = mysql_num_fields(result);

					while ((row = mysql_fetch_row(result))) 
					{ 
						for(int i = 0; i < num_fields; i++) 
						{ 
							printf("%-15s ", row[i]); 
							//printf("\t");
						} 
						printf("\n\n"); 
					}

				break;
			case 2:	printf("Enter Condition: ");
					scanf("%s", &cond);
                    display_row(conn, product);
                    printf("\n\n");
					sprintf(query, "select * from %s where Condition_ = '%s'",product, cond);
					if (mysql_query(conn, query))
					{
						show_error(conn);
					}
					result = mysql_store_result(conn);
					num_fields = mysql_num_fields(result);
	
					while ((row = mysql_fetch_row(result))) 
					{ 
						for(int i = 0; i < num_fields; i++) 
						{ 
							printf("%-15s ", row[i]); 
							//printf("\t");
						} 
						printf("\n\n"); 
					}

				break;

	
			case 3: printf("Enter Watch Strap Materail: ");
					scanf("%s", &strap);
                    display_row(conn, product);
                    printf("\n\n");
					sprintf(query, "select * from %s where Watch_Strap = '%s'",product, strap);
					if (mysql_query(conn, query))
					{
						show_error(conn);
					}
					result = mysql_store_result(conn);
					num_fields = mysql_num_fields(result);

					while ((row = mysql_fetch_row(result))) 
					{ 
						for(int i = 0; i < num_fields; i++) 
						{ 
							printf("%-15s ", row[i]); 
							//printf("\t");
						} 
						printf("\n\n"); 
					}
				break;
                default: printf("Invalid Input!!!");
                    goto aall;
                break;

		}

	}
    else
    {
        printf("\n\nInvalid Input!!!");
        goto op;
    }





	
	printf("\n\nPress enter to go the main menu.");
	getchar();
	mysql_free_result(result);
}