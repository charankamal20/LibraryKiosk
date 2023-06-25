#include"student.h"


void student :: studentBegin()  {
    
    system("cls");

    int flag=1;

            int loginOption;
            while(flag != 0) {   ///////taking student login and input
            cin.ignore();
            cout << "\n\t\t\t\t\t\tSelect one option:\n\t\t\t\t\t\t1. Login\n\t\t\t\t\t\t2. Register\n\t\t\t\t\t\tYour choice: ";
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

int student :: Login() {
        int flag=1;
        char c;
        while(flag != 0)    {
            cout << "\n\t\t\t\t\t\tEnter your 5 digit roll number: ";
            cin >> rollNum;
            if (rollNum <= 99999 && rollNum >= 10000)   {                       /////// roll num check
                yearAndBranchFinder();                                          ///checking the year, confirms the vaidity of the roll num
                if (Branch >0 && Branch <5) {
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
            string rollnum;
            string pass;
            string rnum = to_string(rollNum);

            string directory;
            directory = "C:/Library Kiosk/studentData/" + rnum;

            ifstream readFile(directory + "/" + rnum + ".txt");   ////////////  opening the file ///// reading from the student database ///opening athe file in the studnet folder

            if (readFile.is_open()) {           ////// checking ro see if the file is openend
            getline(readFile, rollnum);
            getline(readFile, pass);

            if (rnum == rollnum && pass == password) {      
                cout << "\n\t\t\t\t\t\tSuccessful Login";
                sleep(1);
                system("cls");
                cout << "\n\t\t\t\t\t\t\tLOADING";      ///////showing loading on screen
                for(int i = 0; i < 3 ; i++) {
                    cout << ".";
                    sleep(1);
                }
                system("cls");
                bookManagement(&rnum, studBookLimit);       ////// now we open book management
            }
            else    { 
                cout << "\t\t\t\t\t\t::Wrong password::";
            }
            }
            else {
                cout << "\n\t\t\t\t\t\t::Invalid Username Entered::\n\t\t\t\t\t\tPlease register first with your username"; /////// case if no file is found for the roll num
            }
            readFile.close();
            
            break;
            }
            else    {
                cout << "\n\t\t\t\t\t\t::Invalid roll number entered::";
            }
            }
            else {
                cout << "\n\t\t\t\t\t\t::You entered the wrong roll number::\n\t\t\t\t\t\tTry again :(";    
            }   
        }   
    return 0;
}

int student :: Register()   {
    int flag=1; 
    char c;
        while(flag != 0)    {
            cout << "\n\t\t\t\t\t\tEnter your 5 digit roll number: ";
            cin >> rollNum;
            if (rollNum <= 99999 && rollNum >= 10000)   {                   ////////////Roll no check
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

                string RollNum;
                RollNum = to_string(rollNum);
                //cout << "\n" << RollNum;
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                
                yearAndBranchFinder();  ////////// year and brach are calculated
                credentials();      ///////pass and username is created now we take the other credentials
                string directory;
                directory = "C:/Library Kiosk/studentData/" + RollNum;
                mkdir(directory.c_str());               ///////making a folder with roll number as name

                ofstream ofs(directory + "/" + RollNum + ".txt");
                ofs << rollNum << endl;
                ofs << password << endl;
                ofs.close();
                
                cout << "\n\n\t\t\t\t\t::Your ID has been created in the Library DataBase::";
                cout << "\n\t\t\t\t\tYou may login again using your RollNum and Password";
                //break;
            }   
            else {
                cout << "\n\t\t\t\t\t\t::You entered the wrong roll number::\n\t\t\t\t\t\tTry again :(";    
            }   
        }       
    sleep(5);
    return 0;   
}   

void student :: credentials()   {
    
    cout << "\n\t\t\t\t\t\tEnter your name: ";
    cin.getline(name,20);
    cout << "\n\t\t\t\t\t\tName: \t" << name ;
    cin.clear();
    cout << "\n\t\t\t\t\t\tYear: \t20" << year;

    switch(Branch)  {
        case 3: 
            cout << "\n\t\t\t\t\t\tBranch: CSE";
            break;
        case 1:
            cout << "\n\t\t\t\t\t\tBranch: CIVIL";
            break;
        case 2:
            cout << "\n\t\t\t\t\t\tBranch: ECE";
            break;
        case 4:
            cout << "\n\t\t\t\t\t\tBranch: MECH";
            break;
        default:
            cout << "\n\t\t\t\t\t\t::Invalid Roll-Num entered::";
            break;

    }
    //setName(Name);
    //cout << endl << getName();

}

void student :: yearAndBranchFinder()   {
    
    year = (rollNum/1000);
    Branch = rollNum;
    for (int i = 5; i >= 3; i--)    {
        int power;
        power = pow(10,i);
        Branch = (Branch%power);
    }
    Branch = Branch/100;
}

void student :: bookManagement(string *rnum, int bookLimit)    {

    int choice, i=0;
    book B;

    while(1)    {
        cout<<"\n\n\t\t\t\t\t\t\tMENU"
		<<"\n\t\t\t\t\t\t1. Issue New Book"
		<<"\n\t\t\t\t\t\t2. Return Book"
		<<"\n\t\t\t\t\t\t3. Search For Book"
		<<"\n\t\t\t\t\t\t4. Exit"
		<<"\n\t\t\t\t\t\tEnter your Choice: ";
		cin>>choice;

        switch (choice)
        {
        case 1: {
            
            B.newbookIssue(*rnum, bookLimit);
            break;
        }
        
        case 2: {
            adminFlag = 1;
            B.bookreturn(*rnum, bookLimit, adminFlag);
            break;
        }
        case 3: {
            
            string stock;
            cin.clear();
            cout << "\n\t\t\t\t\t\tEnter the stock number of the book(Example: A3): ";
            cin >> stock;
            B.bookData(stock);
            break;
        }
        case 4: {
            exit(0);
        }
        default:
            break;
        }

    }

}

void student :: setName(char Name[20]) {
    strcpy(name, Name);
}
string student :: getName ()    {
    return name;
}
void student :: setRollNum(int RollNum) {
    rollNum = RollNum;
}
int student :: getRollNum() {
    return rollNum;
}

