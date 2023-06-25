#pragma once 
#include"teacher.h"

class admin : public teacher {
    
    char* name;
    int adminID;
    string password;
    

    public:

    admin() {
        name = new char[20];
        mkdir("C:/Library Kiosk/adminData/123456");
        ofstream ofs("C:/Library Kiosk/adminData/123456/123456.txt");
        ofs << "123456" << endl << "123456";
        ofs.close();
    }

    void adminConsole();
    int Login();
    int Register();

};