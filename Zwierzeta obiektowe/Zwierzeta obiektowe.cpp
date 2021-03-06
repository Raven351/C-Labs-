#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Zwierze {
protected:
	int dlugoscZycia;
	Zwierze(int dlugoscZycia) {
		this->dlugoscZycia = dlugoscZycia;
	}

public:
	int DlugoscZycia() { return dlugoscZycia; }
};

class Ssak : public Zwierze {
protected:
	int dlugoscCiazy;
public:
	int DlugoscCiazy() { return dlugoscCiazy; }
	Ssak(int dlugoscZycia, int dlugoscCiazy) : Zwierze(dlugoscZycia) { //
		this->dlugoscCiazy = dlugoscCiazy;
	}
	void wypiszInformacje() {
		cout << endl;
		cout << "Dlugosc zycia danego ssaka to " << dlugoscZycia << " lat\n";
		cout << "Dlugosc ciazy danego ssaka to " << dlugoscCiazy << " miesiecy\n";
	}
};

//enum TypWody { 
//	Slodka ,
//	Slona 
//};


class Ryba : public Zwierze {
protected:
	string typWody;
public:
	string TypWody() { return typWody; }
	Ryba(int dlugoscZycia, string typWody) : Zwierze(dlugoscZycia) {
		this->typWody = typWody;
	}
	void wypiszInformacje() {
		cout << endl;
		cout << "Dlugosc zycia danej ryby to " << dlugoscZycia << " lat\n";
		cout << "Rodzaj wody dla danej ryby to: " << typWody << ".\n";
	}
};

class Pies : public Ssak {
public:
	Pies(int dlugoscCiazy, int dlugoscZycia) : Ssak(dlugoscZycia, dlugoscCiazy) {

	}
};

class Kot : public Ssak {
public:
	Kot(int dlugoscCiazy, int dlugoscZycia) : Ssak(dlugoscZycia, dlugoscCiazy) {

	}
};

class Rekin : public Ryba {
public:
	Rekin(int dlugoscZycia, string typWody) : Ryba(dlugoscZycia, typWody) {

	}
};

int main()
{
	Pies burek(1, 15);
	Kot tom(1, 9);
	Ssak panda(20, 1);
	Ryba nemo(1,"Slona");
	//Zwierze animal(); konstruktor typu proteced, utworzenie obiektu nie jest mozliwe
	cout << "Dlugosc zycia psa to " << burek.DlugoscZycia() << " lat. " << endl;
	cout << "Dlugosc zycia kota to " << tom.DlugoscZycia() << " lat. " << endl;
	cout << "Dlugosc zycia pandy (ssaka) to " << panda.DlugoscZycia() << " lat. " << endl;
	cout << "Dlugosc zycia ryby to " << nemo.DlugoscZycia() << " rok. " <<endl;
	burek.wypiszInformacje();
	tom.wypiszInformacje();
	panda.wypiszInformacje();
	nemo.wypiszInformacje();
	cout << endl;
	system("pause");
	return 0;
}

