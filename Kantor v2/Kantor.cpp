// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Kantor.h"
#include <iostream>
#include <string>

using namespace std;

float const avgUSD;
float const avgEUR;
float const spread = 0.10;
float income = 0; //zarobki kantoru ze spreadu na jednorazowej transakcji
float totalIncome = 0; // laczne zarobki kantoru

Kantor::Kantor(float avgUSD, float avgEUR){
	this->avgUSD = avgUSD;
	this->avgEUR = avgEUR;
}

Kantor::kupUSD(float pln) {
	float usd;
	float kursKantoru = KursKantoru(avgUSD, 0);
	usd = pln / kursKantoru;
	income = pln * 0.05;
	totalIncome += income;
	return usd;
}

Kantor::kupEUR(float pln) {
	float eur;
	float kursKantoru = KursKantoru(avgEUR, 0);
	eur = pln / kursKantoru;
	income = pln * 0.05;
	totalIncome += income;
	return eur;
}

Kantor::sprzedajUSD(float usd) {
	float pln;
	float kursKantoru = KursKantoru(avgUSD, 1);
	pln = usd * kursKantoru;
	income = pln * 0.05;
	totalIncome += income;
	return pln;
}


Kantor::sprzedajEUR(float eur) {
	float pln;
	float kursKantoru = KursKantoru(avgEUR, 1);
	pln = eur * kursKantoru;
	income = pln * 0.05;
	totalIncome += income;
	return pln;
}

Kantor::PobierzIncome() {
	return income;
}

Kantor::PobierzTotalIncome() {
	return totalIncome;
}

Kantor::KursKantoru(float waluta, bool typ) { // 0 = kupno, 1 = sprzedaz
	if (typ == 0) return waluta + (waluta * (spread / 2));
	else return waluta - (waluta * (spread / 2));
}

class Kantor {

private:




	//void TransakcjaKomunikat(string waluta1, string waluta2, float w1, float w2){
	//	cout << "Transakcja wykonana: \n";
	//	cout << "Kupiono " << w1 << " " << waluta1 << " za " << w2 << " " << waluta2 << " .\n";
	//	cout << "Kantor na transakcji zarobil " << income << " PLN.\n ";
	//	for (int i = 0; i < 50; i++) cout << "=\n";
	//}

	//kupno za drozej, sprzedaz za taniej



};


int _tmain(int argc, _TCHAR* argv[])
{
	Kantor kantor = Kantor(3.48, 4.23);
	float temp2 = 100;
	float temp =  kantor.kupUSD(temp2);
	cout << "Kupiono " << temp << " USD za " << temp2 << " PLN. \n";
	cout << "Kantor na transakcji zarobil " << kantor.PobierzIncome() << " PLN.\n ";
	for (int i = 0; i < 50; i++) cout << "-";
	cout << endl;
	temp2 = kantor.sprzedajUSD(temp);
	cout << "Sprzedano " << temp << " USD za " << temp2 << " PLN. " << endl;
	cout << "Kantor na transakcji zarobil " << kantor.PobierzIncome() << " PLN.\n ";
	for (int i = 0; i < 50; i++) cout << "-";
	cout << endl;
	temp = kantor.kupEUR(temp2);
	cout << "Kupiono " << temp << " EUR za " << temp2 << " PLN. \n";
	cout << "Kantor na transakcji zarobil " << kantor.PobierzIncome() << " PLN.\n ";
	for (int i = 0; i < 50; i++) cout << "-";
	cout << endl;
	temp2 = kantor.sprzedajEUR(temp);
	cout << "Sprzedano " << temp << " EUR za " << temp2 << " PLN. " << endl;
	cout << "Kantor na transakcji zarobil " << kantor.PobierzIncome() << " PLN.\n ";
	for (int i = 0; i < 50; i++) cout << "-";
	cout << endl;
	cout << "Kantor na wszystkich transakcjach zarobil " << kantor.PobierzTotalIncome() << " PLN.\n ";
	cout << endl;

	return 0;
}

