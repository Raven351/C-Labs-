// Litery w słowie.cpp : Defines the entry point for the console application.

//



#include "stdafx.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;


char upper[26]; //tablica przechowująca wszystkie znaki które mają być liczone
char lower[26];
char numbers[10];

void fill_array(char characters[], int i, int j, int k) { //wypełnia tablicę znakami ASCII
	char ascii = k;
	for (i; i < j; i++) {
		characters[i] = ascii;
		ascii++;
	}
}

bool check_lower(char character) {
	for (int i = 0; i < 26; i++) {
		if (character == lower[i]) return 1;
	}
	return 0;
}

bool check_upper(char character) {
	for (int i = 0; i < 26; i++) {
		if (character == upper[i]) return 1;
	}
	return 0;
}

bool check_num(char character) {
	for (int i = 0; i < 10; i++) {
		if (character == numbers[i]) return 1;
	}
	return 0;
}

bool check_special(int character) {
	if (check_lower(character) == 0 && check_upper(character == 0) && check_num(character) == 0) return 1;
	else return 0;
}

bool check_pass(string password) { //
	if (password.size > 20 && password.size < 8) return 0;
	bool c1 = 0, c2 = 0, c3 = 0, c4 = 0;
	for (int i = 0; i < password.size(); i++) {
		if (check_lower(password[i]) == 1) c1 = 1;
		else if (check_upper(password[i]) == 1) c2 = 1;
		else if (check_num(password[i]) == 1) c3 = 1;
		else c4 = 1;

	}
	if (c1 == 1 && c2 == 1 && c3 == 1 && c4 == 1) return 1;
	else {
		return 0;
	}

}

int main(int argc, char *argv[])

{
	int i = 1;
	fill_array(upper, 0, 26, 65);
	fill_array(lower, 0, 26, 97);
	fill_array(numbers, 0, 10, 48);
	string password;
	string pass_confirm;
	cout << "Podaj haslo" << endl;
	cin >> password;
	assert(check_pass(password) == true);
	cout << check_pass(password);
	cout << "Potwierdz wpisane haslo" << endl;
	cin >> pass_confirm;
	while (pass_confirm != password) {
		cout << "Wpisane hasla nie sa identyczne! Potwierdz haslo ponownie" << endl;
		cin >> pass_confirm;
	}
	cout << "Wpisane hasla sa identyczne" << endl;
	system("pause");

	return 0;

}

