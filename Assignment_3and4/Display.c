#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql.h>
#include"main_header.h"

void display(MYSQL *conn, char prod[20])
{
	//system("clear");
	MYSQL_RES *result;
	MYSQL_ROW row;
	char product[20];
	char query[200] = "";
		
	sprintf(query, "SELECT * FROM %s", prod);

	if (mysql_query(conn, query))
	{
		show_error(conn);
	}

	result = mysql_store_result(conn);
	int num_fields = mysql_num_fields(result);
	
	while ((row = mysql_fetch_row(result))) 
	{ 
		for(int i = 0; i < num_fields; i++) 
		{ 
			printf("%-15s ", row[i]); 
			//printf("\t");
		} 
		printf("\n\n"); 
	}
	mysql_free_result(result);
}

void display_row(MYSQL * conn, char prod[20])
{
	MYSQL_RES *result;
	MYSQL_ROW row;
	char product[20];
	char query[200] = "";
		
	sprintf(query, "describe %s", prod);

	if (mysql_query(conn, query))
	{
		show_error(conn);
	}

	result = mysql_store_result(conn);
	int num_fields = mysql_num_fields(result);
	
	while ((row = mysql_fetch_row(result))) 
	{ 
			printf("%-15s ", row[0]); 
			//printf("\t"); 
	}
	mysql_free_result(result);

}