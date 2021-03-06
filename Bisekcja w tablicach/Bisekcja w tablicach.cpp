// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <array>
#include <ctime>

using namespace std;

int i = 0;
void szukaj(int arr[], int poszukiwanaLiczba, int begin, int end) {
	i++;
	int half = ((end - begin) / 2) + begin;

	if (poszukiwanaLiczba > arr[half] && half != 998) {
		cout << "Proba nr " << i << endl;
		cout << "Szukam w polowie przedzialu od " << begin << " do " << end << endl;
		cout << "arr[" << half << "] = " << arr[half] << endl;
		cout << "" << endl;
		szukaj(arr, poszukiwanaLiczba, half, end);
	}
	else if (poszukiwanaLiczba < arr[half]) {
		cout << "Proba nr " << i << endl;
		cout << "Szukam w polowie przedzialu od " << begin << " do " << end << endl;
		cout << "arr[" << half << "] = " << arr[half] << endl;
		cout << "" << endl;
		szukaj(arr, poszukiwanaLiczba, begin, half);
	}
	else if (arr[half] == poszukiwanaLiczba) {
		cout << "Proba nr " << i << endl;
		cout << "Szukam w polowie przedzialu od " << begin << " do " << end << endl;
		cout << "arr[" << half << "] = " << arr[half] << endl;
		cout << "" << endl;
		for (int j = 0; j < 100; j++) { cout << "="; }
		cout << endl;
		cout << "Poszukiwana liczba " << poszukiwanaLiczba << " znajduje sie pod indeksem " << half << "." << endl;
		cout << "Liczbe odnaleziono po " << i << " probach." << endl;
		for (int j = 0; j < 100; j++) { cout << "="; }
		cout << endl;
	}

	else if (half == 998 && arr[997] != poszukiwanaLiczba) { //warunek umożliwiający sprawdzenie ostatniego elementu tablicy
		for (int j = 0; j < 100; j++) { cout << "="; }
		cout << endl;
		cout << "Poszukiwana liczba " << poszukiwanaLiczba << " znajduje sie pod indeksem " << 999 << "." << endl;
		cout << "Liczbe odnaleziono po " << i << " probach." << endl;
		for (int j = 0; j < 100; j++) { cout << "="; }
		cout << endl;
	}

	else {
		cout << "ERROR" << endl;
	}
}


int main()
{
	int arr[1000];
	int t = time(NULL) % 1000;
	srand(t); //ustawienie losowego punktu startowego dla generatora liczb pseudolosowych na podstawie czasu systemu w formie liczby
	std::generate(std::begin(arr), std::end(arr), std::rand); //wypełnienie tablicy pseudolosowymi liczbami z przedziału od 1 do 10000
	std::sort(std::begin(arr), std::end(arr)); // sortowanie tablicy
	int index = (std::rand() % 1000) + 0; //wylosowanie indexu poszukiwanej liczby z przedziału od 0 do 999
										  //int index = 999;
	int poszukiwanaLiczba = arr[index]; //przypisanie poszukiwanej liczby do zmiennej
	cout << "Szukana liczba to: " << poszukiwanaLiczba << endl; //podaje szukaną liczbę przed uruchomieniem funkcji szukającej w celu zweryfikowania czy kod działa poprawnie
	cout << "" << endl;
	szukaj(arr, poszukiwanaLiczba, 0, (sizeof(arr) / sizeof(*arr)) - 1);
	return 0;
}


