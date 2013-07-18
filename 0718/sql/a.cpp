#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>
int main()
{

	sqlite3_stmt* stmt;
	sqlite3 *handle;
	int retval;

	string sqlStr="select * from phone_book";
	
	retval=sqlite3_open("phone_book.db",&handle);

	if(retval)
	{
		printf("연결실패\n");
		return -1;
	}
	printf("연결성공\n");

	retval=sqlite3_prepare_v3(handle,sqlStr.c_str(),-1,&stmt,NULL);

	return 0;
}
