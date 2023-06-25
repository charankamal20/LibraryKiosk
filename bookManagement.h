#pragma once

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<ctime>
#include<unistd.h>
#include<iomanip>

using namespace std;

time_t now = time(NULL);				/////// taking seconds
tm *cur_time = localtime(&now);			/////// making a local time object

const int studBookLimit = 3;    /////// number of books the student can issue at one time
const int teachBookLimit = 5;   /////// number of books the teacher can issue at one time 
int adminFlag = 0;        /////// admin flag

class book	{		/////////our main book class for the functions we perform on our books

private:
	
	string *author,*title,*publisher;
	float price;
	string stock;
	string booksIssued;

public:	

	book()	{
		author = new string;
		title = new string;
		publisher = new string;
	}
	
	void feeddata();
	void editdata();
	void bookData(string Stock);
	void newbookIssue(string id, int i);
	void bookreturn(string id, int I, int adminFlag);
	int calculateFine(int numOfDays);
	void removeEntry(int linecount, string id, int i);
	void returnTomenu();
	void databaseEntry(string id, int i);

};
