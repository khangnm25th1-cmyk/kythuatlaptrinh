#include<string>
using namespace std;
struct Account {
	int id;
	string lnk, usr, pwd, desc;
	friend ostream& operator<<(ostream& os, const Account& b) {
		os << "Account information:" << endl;
		os << "\t+ Id:" << b.lnk << endl;
		os << "\t+ Name:" << b.usr << endl;
		os << "\t+ Author name:" << b.pwd << endl;
		os << "\t+ Author name:" << b.desc << endl;
		return os;
	}
	friend istream& operator>>(istream& in, Account& b) {
		cout << "Account information:" << endl;
		cout << "\t+ Id:";
		in >> b.id;
		cout << "\t+ Link:";
		in.ignore();
		getline(in, b.lnk);
		cout << "\t+ User name:";
		in.ignore();
		getline(in, b.usr);
		cout << "\t+ Password:";
		in.ignore();
		getline(in, b.pwd);
		cout << "\t+ Description:";
		in.ignore();
		getline(in, b.desc);
		return in;
	}
};
