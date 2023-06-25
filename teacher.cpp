#include"teacher.h"


int teacher :: Login()  {
    
    int flag=1;
        char c;
        while(flag != 0)    {
            cout << "\n\t\t\t\t\t\tEnter your 5 digit teacher's ID: ";
            cin >> teachID;
            if (teachID <= 99999 && teachID >= 10000)   {                       /////// roll num check
                flag = 0;
                cout << "\n\t\t\t\t\t\tEnter your password: ";
                while(c != '\r') //////////Loop until 'Enter' is pressed
                {
                c = getch();
                if(c == 0)
                {
                switch(getch())
                {
                default:
                    break;            
                };
                }
                else if(c == '\b')   /////If the 'Backspace' key is pressed
                {
                if(password.size() != 0)  //////If the password string contains data, erase last character
                {
                cout << "\b \b";
                password.erase(password.size() - 1, 1);
                }
                continue;
                }
                else if(c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')  //If user enters 1-9, a-z, or A-Z, add it to the password and display an asterisk
                {
                password += c;
                cout << "*";
                }
                else
                continue;
                }
            string TeachID;
            string pass;
            string rnum = to_string(teachID);

            string directory;
            directory = "C:/Library Kiosk/teacherData/" + rnum;

            ifstream readFile(directory + "/" + rnum + ".txt");   ////////////  opening the file ///// reading from the student database ///opening athe file in the studnet folder

            if (readFile.is_open()) {           ////// checking ro see if the file is openend
            getline(readFile, TeachID);
            getline(readFile, pass);

            if (rnum == TeachID && pass == password) {      
                cout << "\n\t\t\t\t\t\tSuccessful Login";
                sleep(1);
                system("cls");
                cout << "\n\n\t\t\t\t\t\t\tLOADING";      ///////showing loading on screen
                for(int i = 0; i < 3 ; i++) {
                    cout << ".";
                    sleep(1);
                }
                system("cls");
                bookManagement(&rnum, teachBookLimit);       ////// now we open book management
            }
            else    { 
                cout << "\t\t\t\t\t\t\t::Wrong password::";
            }
            }
            else {
                cout << "\n\t\t\t\t\t::Invalid Username Entered::\n\t\t\t\t\tPlease register first with your username"; /////// case if no file is found for the roll num
            }
            readFile.close();
            
            break;

            }
            else {
                cout << "\n\t\t\t\t\t\t::You entered the wrong Teacher's ID::\n\t\t\t\t\t\tTry again :(";    
            }   
        }   
    return 0;
}


void teacher :: getname()   {
    cout << "Enter your name below:";
    cin >> name;
}

string teacher :: getid() {
    string TeachID;
    TeachID = to_string(teachID);
    return TeachID;
}

void teacher :: idcheck()   {
    
}

void teacher :: teacherBegin()  {
    
    int flag=1;

            int loginOption;
            while(flag != 0) {   ///////taking student login and input
            cin.ignore();
            cout << "\n\t\t\t\t\t\t\tSelect one option:\n\t\t\t\t\t\t1. Login\n\t\t\t\t\t\t2. Register\n";
            cin >> loginOption;
            try {
                if (loginOption == 1 || loginOption == 2)   {
                    if (loginOption == 1)   {
                        flag = 0;
                        Login();
                    }
                    else    {
                        flag = 0;
                        Register();
                    }
                }

                else{
                    throw(loginOption);
                }
            }
            catch(int a) {
                cout << "\n\t\t\t\t\t\t::Choose only from options given above::\n";
                //loginOption = 1;
            }
        }
}

int teacher :: Register()  {
        
        int flag=1; 
        char c;
        while(flag != 0)    {
            cout << "\n\t\t\t\t\t\tEnter your 5 digit Teacher's ID: ";
            cin >> teachID;
            if (teachID <= 99999 && teachID >= 10000)   {                   ////////////Roll no check
                flag = 0;
                //cin.ignore();
                cout << "\n\t\t\t\t\t\tEnter your password: ";
            while(c != '\r') //////////Loop until 'Enter' is pressed
            {
            c = getch();
            if(c == 0)
            {
            switch(getch())
               {
               default:
                  break;            
               };
            }
            else if(c == '\b')   /////If the 'Backspace' key is pressed
            {
            if(password.size() != 0)  //////If the password string contains data, erase last character
               {
               cout << "\b \b";
               password.erase(password.size() - 1, 1);
               }
            continue;
            }
            else if(c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')  //If user enters 1-9, a-z, or A-Z, add it to the password and display an asterisk
            {
            password += c;
            cout << c;
            }
            else
            continue;
            }
                cin.ignore();

                cout << "\n\t\t\t\t\t\tEnter your name: ";
                cin >> name;

                string TeachID;
                TeachID = to_string(teachID);
                //cout << "\n" << RollNum;
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                
                string directory;
                directory = "C:/Library Kiosk/teacherData/" + TeachID;
                mkdir(directory.c_str());               ///////making a folder with roll number as name

                ofstream ofs(directory + "/" + TeachID + ".txt");
                ofs << teachID << endl;
                ofs << password;
                ofs.close();
                
                cout << "\n\n\t\t\t\t\t::Your ID has been created in the Library DataBase::";
                cout << "\n\t\t\t\t\tYou may login again using your Teacher's ID and Password";
                //break;
            }   
            else {
                cout << "\n\t\t\t\t\t::You entered the wrong Teacher's ID::\nTry again :(";    
            }   
        }     
        sleep(2);  
    return 0;
}