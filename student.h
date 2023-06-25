#pragma once

#include<ctime> //////////for time funtionality for calculating fine
#include<unistd.h>  /////////for sleep function
#include<iostream>
#include<string.h>
#include<fstream>
#include<ios>    //used to get stream size
#include<limits> //used to get numeric limits   //// for solving cin buffer issue
#include<conio.h>   //// for getch() function (for password entering)
#include<math.h>
#include<sys/stat.h>    /////for opening directories
#include"bookManagement.h"  ///custom header file with book class

class student   {

    int rollNum;
    char *name;
    string password;
    int Branch,year;

    public:
    
    student()   {
        name = new char[20];
    }

    void studentBegin();
    void setRollNum(int RollNum);
    int getRollNum();
    void setName(char Name[20]);
    string getName();
    int Login();
    int Register();
    void credentials();
    void yearAndBranchFinder();
    void bookManagement(string* rnum, int bookLimit);

};
