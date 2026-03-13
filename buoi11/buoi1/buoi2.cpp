#include<iostream>
#include<vector>
#include<fstream> 
#include<string>
using namespace std;
struct connguoi {
	int maso;
	string hoten;
	int tuoi;
	string diachi;
}; 
void Viewpersonlist(vector<connguoi>p) {
	if (p.size() == 0)
		cout << "An empty list" << endl;
	else {
		for (int i = 0;i < p.size();i++) {
			cout << "Person" << (i + 1) << endl;
			cout << "\t+ Id:" << p[i].maso << endl;
			cout << "\t+ Hoten" << p[i].hoten << endl; 
			cout << "\t+ Tuoi" << p[i].tuoi << endl;
			cout << "\t+ diachi" << p[i].diachi << endl;
		}
	}
}
void Addperson(vector<connguoi>& p) {
	connguoi a;
	cout << "+Id:";
	cin >> a.maso;
	cout << "+name:";
	cin.ignore();
	getline(cin, a.hoten);
	cout << "+age:";
	cin >> a.tuoi;
	cout << "Address:";
	cin.ignore();
	getline(cin, a.diachi);
	p.push_back(a);
	cout << "Add a person successfully" << endl;

}
void removeperson(vector<connguoi>& p, int id) {
	for (auto i = p.begin();i != p.end();i++) {
		if (i->maso == id) {
			p.erase(i);
			cout << "remove a person successfully" << endl;
			return;
		}
	}
	cout << "Not found person with id:" << id << endl;
}
int main() {
	vector<connguoi>list;
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
			Viewpersonlist(list);
			break;
	    	} 
		case 2: { 
			Addperson(list);
			break;
		} 
		case 3: { 
			int id;
			cout << "Input iD to remove:";
			cin >> id;
			removeperson(list, id);
			break;
		}
		case 4: {
			     break;
		}
		case 5: {
			break;
		}
		case 6: {
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