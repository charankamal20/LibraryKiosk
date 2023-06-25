#include"admin.h"

void admin :: adminConsole()    {

    system("cls");

    book *B;
	int i=0,r,t,choice;
	char titlebuy[20],authorbuy[20];
	while(1)	{
		cout<<"\n\n\t\t\t\t\t\t\tMENU"
		<<"\n\t\t\t\t\t\t1. Entry of New Book"
		<<"\n\t\t\t\t\t\t2. Add a new Admin"
		<<"\n\t\t\t\t\t\t3. Search For Book"
		<<"\n\t\t\t\t\t\t4. Edit Details Of Book"
        <<"\n\t\t\t\t\t\t5. Approve late book return"
		<<"\n\t\t\t\t\t\t6. Exit"
		<<"\n\t\t\t\t\t\tEnter your Choice: ";
		cin>>choice;
		
		switch(choice)	{
			case 1:	
                B = new book;
				B->feeddata();
				i++;	
                break;
				
			case 2: 
                cin.ignore();
				Register();
				break;
			case 3: {
                
                string stock;
                
                cin.ignore();
                cout << "\t\t\t\t\t\tEnter the stock value for the book: ";
                cin >> stock;

				B->bookData(stock);

				break;
            }
			case 4: 
                
                B->editdata();
				break;

			case 5: {

                student stud;
                string RollNum;
                int i = 0;
                while(1)    {

                    cout << "\t\t\t\t\t\tBook return for: "
                    << "\n\t\t\t\t\t\t1. Student"
                    << "\n\t\t\t\t\t\t2. Teacher"
                    << "\n\t\t\t\t\t\tYour choice: ";
                    cin >> i;
                    switch(i)   {
                    case 1: {
                        cin.ignore();
                        cout << "\t\t\t\t\t\tEnter the roll Num of the student: ";
                        cin >> RollNum;
                        B->bookreturn(RollNum, studBookLimit, adminFlag);
                        break;
                    }
                    case 2: {
                        cin.ignore();
                        cout << "\t\t\t\t\t\tEnter the teacher's ID: ";
                        cin >> RollNum;
                        B->bookreturn(RollNum, teachBookLimit, adminFlag);
                        break;
                    }
                    default:
                        cout << "\n\n\t\t\t\t\t\t::Invalid Choice Entered::";
                        break;
                    }
                }
            }
			case 6:
                exit(0);
            default: 
                cout<<"\n\t\t\t\t\t\tInvalid Choice Entered";
                system("cls");
			
		}
	}

}


int admin :: Login()    {
        
        cout << "\n\t\t\t\t\t::Login with your Admin ID and password::\n";
        int flag=1;
        char c;
        while(flag != 0)    {
            cout << "\n\t\t\t\t\t\tEnter your 6 digit admin ID: ";
            cin >> adminID;
            if (adminID <= 999999 && adminID >= 100000)   {                       /////// roll num check
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
            string rnum = to_string(adminID);

            string directory;
            
            directory = "C:/Library Kiosk/adminData/" + rnum;

            ifstream readFile(directory + "/" + rnum + ".txt");   ////////////  opening the file ///// reading from the admin database ///opening athe file in the studnet folder

            if (readFile.is_open()) {           ////// checking ro see if the file is openend
            getline(readFile, rollnum);
            getline(readFile, pass);
            cout << rollnum << endl << pass;
            if (rnum == rollnum && pass == password) {      
                cout << "\n\t\t\t\t\t\tSuccessful Login";
                sleep(1);
                system("cls");
                cout << "\n\n\t\t\t\t\t\tLOADING";      ///////showing loading on screen
                for(int i = 0; i < 3 ; i++) {
                    cout << ".";
                    sleep(1);
                }
                system("cls");
                adminConsole();       ////// now we open admin console
            }
            else    { 
                cout << "\t\t\t\t\t\t::Wrong password::";
            }
            }
            else {
                cout << "\n\t\t\t\t\t::Invalid Username Entered::\n\t\t\t\t\tPlease register first with your username"; /////// case if no file is found for the roll num
            }
            readFile.close();
            
            break;
            }
            else {
                cout << "\n\t\t\t\t\t\t::You entered the wrong Admin ID::\n\t\t\t\t\t\tTry again :(";    
            }   
        }   
    return 0;
}

int admin :: Register()    {
    
    int flag=1; 
    char c;
        while(flag != 0)    {
            cout << "\n\t\t\t\t\t\tEnter your 6 digit Admin ID: ";
            cin >> adminID;
            if (adminID <= 999999 && adminID >= 100000)   {                   ////////////Roll no check
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

                string AdminID;
                AdminID = to_string(adminID);
                //cout << "\n" << RollNum;
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                
                string directory;
                directory = "C:/Library Kiosk/adminData/" + AdminID;
                mkdir(directory.c_str());               ///////making a folder with roll number as name

                ofstream ofs(directory + "/" + AdminID + ".txt");
                ofs << adminID << endl;
                ofs << password;
                ofs.close();
                
                cout << "\n\n\t\t\t\t\t::Your ID has been created in the Library DataBase::";
                cout << "\n\t\t\t\t\tYou may login again using your Admin's ID and Password";
                //break;
            }   
            else {
                cout << "\n\t\t\t\t\t\t::You entered the wrong Admin ID::\n\t\t\t\t\t\tTry again :(";    
                sleep(2);
                system("cls");
            }   
        }      
    sleep(2);
    return 0;

}