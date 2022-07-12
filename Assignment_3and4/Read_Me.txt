Command used to compile code on Zeus:
	gcc -o test $(mysql_config --cflags) *.c $(mysql_config --libs)  

Command used to run code on Zeus:
	./test
	
The admin password is 1234.