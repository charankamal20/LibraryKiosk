#pragma once
#include"student.h"

class teacher : public student {
    
    int teachID;
    char *name;
    string password;
    
    public:

    teacher()   {
        name = new char[20];
    }

    void teacherBegin();
    void getname();
    string getid();
    void idcheck();
    int Login();
    int Register();

};