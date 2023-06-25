<h1>Library Kiosk System</h1>

<h3>Introduction</h3> 

The Library Kiosk System is a software solution designed to automate and streamline library operations, replacing the traditional librarian with a self-service kiosk. This project aims to enhance the efficiency and accuracy of library tasks while reducing the possibility of errors. The system provides dedicated functionality tailored to the needs of our college library.
<h3>Features</h3>

    * Three main user classes: Student, Teacher, and Admin, representing the different entities that interact with the program.
    * Multilevel inheritance: The Student class serves as the base class, the Teacher class inherits from the Student class, and the Admin class inherits from the Teacher class.
    * Access control: The admin has access to all public and private attributes and methods of both the Student and Teacher classes, while vice versa is not possible.
    * Data storage: The program creates directories in the C drive of the computer and stores all data in the form of files.
    * Utilizes "bookManagement.h" header file: The program works with a custom header file called "bookManagement.h," which contains all the operations that can be performed on books and the database.

<h3>Getting Started</h3>

    * Database Initialization: Before issuing books, it is necessary to enter the books into the database. This can be done by logging in as an admin. Alternatively, you can copy the provided files in the "books" folder into the "bookdata" folder created in "C:/Library Kiosk/bookdata".

    * Admin Login: The program creates a default admin account the first time it is run. Use the following credentials to log in as the admin:
        * Username: 123456
        * Password: 123456

    * After logging in, additional admins can be added.

<h3>Requirements</h3>

    * The system requires access to the C drive of the computer for data storage.
    * The "bookManagement.h" header file must be present and correctly configured for the program to function properly.


Feel free to add or modify any additional sections as per your project's requirements.
You can also visit this link:  
https://linktr.ee/libraryKiosk
