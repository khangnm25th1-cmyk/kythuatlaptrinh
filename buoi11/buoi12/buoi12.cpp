#include <iostream>
using namespace std;
#define MAX 100;
struct Book {
	int id;
	char name[50];
	double price;
};
int main()
{
	int nBook = 0;
	Book BooksMAX;
	do {
		system("cls");
		cout << "----------BOOK MANAGEMENT--------------"<<endl;
		cout << "1.Add a book" << endl;
		cout << "2.show books" << endl;
		cout << "3.Sort books" << endl;
		cout << "4.Find a Book" << endl;
		cout << "0.Exit" << endl;
		cout << "--------------------------------------------" << endl;
		cout << "Choose";
		int choose;
		cin >> choose;
		switch (choose) {
		case 1: {
			break;
		}
		case 2: {
			break;
		}
		case 3: {
			break;
		}
		case 4: {
			break;
		}
		case 0;
			return 0;
		default: {
			cout << "Invalid command" << endl;
			break;
		}
		}
		system("pause");
		cout << "Press enter to continue.." << endl;


	} while (true);
}
