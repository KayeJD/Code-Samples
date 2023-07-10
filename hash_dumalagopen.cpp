#include <iostream>
#include <cstdlib>
using namespace std;

/*
    Notes:
    - h(k, i) = (h’(k) + i) mod m.
	- h’(k) = k mod m
*/

//basic linked list structure
struct bankAccount{
    int accNum, balance;
    string ownerFirstName, ownerLastName;
};

class Bank{
private:
    int capacity;
    bankAccount** hashTable;
	
public:
	Bank(int m){
        capacity = m;
        hashTable = new bankAccount*[capacity]; //Array of pointers
    }

    int hashFunction(int key, int i){
        return ((key % capacity) + i) % capacity;
    }

    void INSERT_Account(string fname, string lname, int accountNumber, int balance){
        //find slot number
		int i = 0;
        int slotNum = hashFunction(accountNumber, i);

        //insert information
        bankAccount* newAcc = new bankAccount;
        newAcc->ownerFirstName = fname;
        newAcc->ownerLastName = lname;
        newAcc->accNum = accountNumber;
        newAcc->balance = balance;

		while (true){
			//empty slot case
			if (hashTable[slotNum] == nullptr){
				hashTable[slotNum] = newAcc; 
				return;
			} 
			//existing account case
			else if ((hashTable[slotNum]->accNum == accountNumber)){
				cout << "Account number already exists." << endl;
            	return;
			}

			i++;
			slotNum = hashFunction(accountNumber, i);

		}
        
    }
    
    void SEARCH_Account(int accountNumber){
		//find slot number
		int i = 0;
        int slotNum = hashFunction(accountNumber, i);

		while(true){
			// check if the slot is empty
			if (hashTable[slotNum] == nullptr) {
				cout << "Account does not exist." << endl;
				return;
			}
			// check if the account number matches
			else if (hashTable[slotNum]->accNum == accountNumber) {
				cout << endl;
				cout << " Account Details:" << endl;
				cout << " Owner Name: " << hashTable[slotNum]->ownerLastName << ", " << hashTable[slotNum]->ownerFirstName << endl;
				cout << " Account Number: " << hashTable[slotNum]->accNum << endl;
				cout << " Balance: $" << hashTable[slotNum]->balance << endl;
				return;
			}

			// increment i and calculate the new slot number using linear probing
			i++;
			slotNum = hashFunction(accountNumber, i);
		}
    }
};

int main()
{
	Bank bankAcc(753);
	int choice, accNum, accBalance;
    string firstName, lastName;

	while (true)
	{
		cout << endl << endl;
		cout << " Bank Account Management System " << endl;
		cout << " ------------------------------ " << endl;
		cout << " 1. Create New Account " << endl;
		cout << " 2. Display Account Information " << endl;
        cout << " 3. Exit " << endl;
		cout << " Enter your choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1: 
            cout << " Enter Account Number (100001-999999): ";
            cin >> accNum;
            cout << " Enter First Name : ";
			cin >> firstName;
            cout << " Enter Last Name : ";
			cin >> lastName;
            cout << " Enter Balance : ";
			cin >> accBalance;
            bankAcc.INSERT_Account(firstName, lastName, accNum, accBalance);
			break;
		case 2: cout << endl;
            cout << " Enter Account Number (100001-999999): ";
			cin >> accNum;
            bankAcc.SEARCH_Account(accNum);
			break;
		case 3: system("pause");
			return 0;
			break;
		default:
			cout << "Invalid choice";
		}
	}
}