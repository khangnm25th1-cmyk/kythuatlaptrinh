#include <iostream>
#include"Account.h"
#include"Linkedlist.h"
int main()
{

	LinkedList<Account> accounts = { NULL };
	system("cls");
	do {
		cout << "-----------------ACCOUNT MANAGEMENT-----------" << endl;
		cout << "1. Show all account" << endl;
		cout << "2. Add a account" << endl;
		cout << "3. Delete a account" << endl;
		cout << "4. Update a account" << endl;
		cout << "5. Find account" << endl;
		cout << "6.Export to file" << endl;
		cout << "7. Import to file" << endl;
		cout << "0.Exit" << endl;
		cout << "--------------------------" << endl;
		cout << "Enter your choice:";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: {
			accounts.Show();
			break;
		}
		case 2: {
			Account a;
			cin >> a;
			accounts.Add(a);
			break;
		}
		case 3: {
			int removeId;
			cout << "Enter account id to remove:" << endl;
			cin >> removeId;
			bool res = accounts.Remove(removeId);
			if (res)
				cout << "Remove acount with id:" << removeId << endl;
			else
				cout << "Not found account id:" << removeId << endl;
			break;
		}
		case 4: {
			int updateId;
			cout << "Enter account id to remove:" << endl;
			cin >> updateId;
			bool res = accounts.Update(updateId);
			if (res)
				cout << "Remove acount with id:" << updateId << endl;
			else
				cout << "Not found account id:" << updateId << endl;
			break;
		}
		case 5: {

			break; 
			string userName;
			cout << "Emter account name:";
			cin.ignore();
			getline(cin, userName);
			accounts.Find(userName);
			break;                             
		}
		case 6: {

			break;
		}
		case 7: {

			break;
		}
		case 0: {
			return 0;
		default:
			cout << "Invavalid choice,try again" << endl;
			break;
		}
		}
		system("pause");
		cout << "Press any key to comtinue....";
	} while (true);
	return 0;
}
