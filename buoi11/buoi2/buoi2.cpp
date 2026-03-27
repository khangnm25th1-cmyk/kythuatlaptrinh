#include <iostream>
using namespace std;
struct person {
	int id;
	string name;
	friend ostream operator<<ostream & os, const person& p){
		os << "\t+ Id:" << p.id << endl;
		os << "\t+ Name:" << p.name << endl;
		return os;
	}
	friendl istream& operator>>(istream& in, person& p) {
		cout << "Input person information:" << endl;
		cout << "\t+ Id:";
		in >> p.id;
		cout << "\t+ name:";
		in.ignore();
		getline(in, p.name);
		return in;
	}
};
struct node {
    person data;
    node* next;
};
struct linkedlist {
    node* head; 
	void show() {
		if (head == NULL) {
			cout << "Emty list" << endl;
			return;
		}
		node* item = head;
		while (item != NULL) {
			cout << "Id" << item->data.id << endl;
			cout << "Name" << item->data.name << endl;
			item = item->next;
		}

	}
};
int main()
{
    linkedlist list; 
	do {
		system("cls");
		cout << "--HUMAN RESOURCE--" << endl;
		cout << "1.view person" << endl;
		cout << "2.Add a person" << endl;
		cout << "3.remove a person" << endl;
		cout << "4. Find a peson by name" << endl;
		cout << "5.Export to file" << endl;
		cout << "6.Import from file" << endl;
		cout << "0.Exit" << endl;
		cout << "------------------------" << endl;
		cout << "Your command:";
		int cmd;
		cin >> cmd;
		switch (cmd) {
		case 1: {
			list.show();
			break;
		}
		case 2: {
			
			break;
		}
		case 3: {
			int id;
			cout << "Input iD to remove:";
			cin >> id;
			
			break;
		}
		case 4: {
			break;
		}
		case 5: { 
			cout << "Export successfully" << endl;
			break;
		}
		case 6: { 
			cout << "Import successfully" << endl;
			break;
		}
		case 0: {
			return 0;
		default:
			cout << "KHONG CO CHUC NANG NAY DAU THANG MAT LOL" << endl;
		}
		}
		cout << "Go enter de tiep tuc di thang ku...";
		cin.ignore();
		cin.get();
	} while (true);
	return 0;
}
