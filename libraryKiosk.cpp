/*  
Library Kiosk System
Author: classikh

Description:
This program is a self-service library kiosk system designed to automate library tasks and enhance efficiency. It allows users to issue books, check availability, and manage their library accounts. The system utilizes classes for students, teachers, and administrators, providing different levels of access and functionality. Data is stored in files located in the C drive, and book operations are handled through the custom header file "bookManagement.h".

Instructions:
1. Before issuing books, ensure the database is initialized by logging in as an admin or copying the provided book files into the bookdata folder.
2. The default admin account can be used for the first login. Username: 123456, Password: 123456.
3. Additional admins can be added after logging in.

*/  

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

using namespace std;

int main()  {

    int i = 0;
    //////////making our directory in C drive so data is secure and this program can run on all computers
    string directory;           ///////defining the directory where all data will be stored
    directory = "C:/Library Kiosk";
    mkdir(directory.c_str());   ///////making our main folder
    directory = "C:/Library Kiosk/studentData";
    mkdir(directory.c_str());   ///////,making our student folder
    directory =  "C:/Library Kiosk/teacherData";
    mkdir(directory.c_str());   ///////making our teacher folder
    directory =  "C:/Library Kiosk/adminData";
    mkdir(directory.c_str());   ///////making our admin folder
    directory =  "C:/Library Kiosk/bookdata";
    mkdir(directory.c_str());   ///////making our books folder


    while(1)    {
    system("cls");
    cout << "\n\n\n\n\n\t\t\t\t\t ::WELCOME TO THE LIBRARY KIOSK::";
    cout << "\n\n\t\t\t\t\t\t\tMENU \n\t\t\t\t\t\t1.Student, \n\t\t\t\t\t\t2.Teacher or \n\t\t\t\t\t\t3.Admin\n\t\t\t\t\t\t4.Exit\n\t\t\t\t\t\tYour choice: ";
    cin >> i;

    switch (i)  {

        case 1:     //////for student
        {
            student stud1;
            stud1.studentBegin();
            break;  //////////case break
        }
        case 2: ////////for teacher
        {
            teacher tech1;
            tech1.teacherBegin();
            break;
        }
        case 3: ////////for admin
        {
            admin adm;
            adm.Login();
            break;
        }
        case 4: exit(0);
        default:
        cout << "\n::Invalid choice entered::";
        break;

    }
    }

    return 0;

}