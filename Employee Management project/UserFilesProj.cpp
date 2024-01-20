#include <iostream>
#include <stdlib.h>
#include <fstream> //to let us read or write to/from files
using namespace std;
const char* fileName="Employee.txt";

class Employee {
    //Unless specified, all declarations in a class are private
    private:
        /*
        Basically declare all of the variables that this class uses here
        so the getters are able to access them after the setters 
        */
        double rating;
        string fName, lName, password, department, address;
        string front, back, middle, somewhere;
        int userID;
    public: 
        //Default Constructor
        Employee(){cout << "\nNew employee registration..." << endl;}
        
        void newEmployee();

};

void Employee::newEmployee(){
    char data[100];

    // open a file in write mode.
    ofstream outfile;
    outfile.open("afile.dat"); 

    cout << "Writing to the file" << endl;
    cout << "Enter your name: "; 
    cin.getline(data, 100);

    // write inputted data into the file.
    outfile << "Name: " << data << endl;

    cout << "Enter your age: "; 
    cin >> data;
    cin.ignore();
   
    // again write inputted data into the file.
    outfile << "Age: " << data << endl;

    // close the opened file.
    outfile.close();

    // open a file in read mode.
    ifstream infile; 
    infile.open("afile.dat"); 
 
    cout << "Reading from the file" << endl; 
    infile >> data; 

    // write the data at the screen.
    cout << data << endl;
   
    // again read the data from the file and display it.
    infile >> data; 
    cout << data << endl; 

    cout << "Create 7 digit user ID: ";
    cin >> userID;

    cout << "Department:";
    cout << "(1) Front" << endl;
    cout << "(2) Back" << endl;
    cout << "(3) Middle" << endl;
    cout << "(4) Somewhere" << endl;
    char depOption;
    cin >> depOption;

    switch (depOption){
        case '1':
            department = "Front";
            break;
        case '2':
            department = "Back";
            break;
        case '3':
            department = "Middle";
            break;
        case '4':
            department = "Somewhere";
            break;
        default:
            department = "Undecided";
            break;
    }

    cout << "Mailing Address: " << endl;
    cin >> address;

    // close the opened file.
    infile.close(); 

}

//The forward declaration for the functions
//void newFile(string, string); 
void menu();

void menu(){
    cout << "--------------------------------" << endl;
    printf("Employee Management System");
    printf("--------------------------------\n\n");

    printf("Available Options:\n");
    printf("(1) Add a new employee\n");
    printf("(2) Update an employee record\n");
    printf("(3) Search for an employee\n");
    printf("(4) Display a department\n");
    printf("(5) Exit the program\n");

    // Get user input from the keyboard
    char menuChoice; // use char variable to account for incorrect input & less memory space
    cout << "Option: ";
    cin >> menuChoice; 
    
    switch(menuChoice){
        case '1':
            Employee newEmployee;

            string f, l;
            printf("First Name: ");
            cin >> f;
            printf("Last Name: ");
            cin >> l;
            
            break;

        case '2':
            break;

        case '5':
            exit(0);
            break;

        default:
            cout << "Expected Options: \n(1) / (2) / (3) / (4) / (5) 5\n\n";   
            menu(); 
            break; 
    }

}

/*
void newFile(string firstName, string lastName){
    
    
    // Create and open a text file
    ofstream MyFile("filename.txt");

    // Write to the file
    MyFile << "Files can be tricky, but it is fun enough!";

    // Close the file
    MyFile.close();
}
*/

//Driver
int main(int argc, char** argv){
    menu();

    return 0;
}