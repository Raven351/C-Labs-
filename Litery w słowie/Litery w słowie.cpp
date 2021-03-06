// Litery w słowie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

char characters_array[62]; //tablica przechowująca wszystkie znaki które mają być liczone
int numb_of_chars_array[62]; //tablica licząca występowanie danego znaku ze wcześniejszej tablicy

void fill_array(int i, int j, int k) { //wypełnia tablicę znakami ASCII
	char ascii = k;
	for ( i ; i < j; i++) {
		characters_array[i] = ascii;
		ascii++;
	}
}

void zero_counter() { //wyzerowuje licznik
	for (int i = 0; i < 62; i++) {
		numb_of_chars_array[i] = 0;
	}
}

void check_character(char character) { //zwiększa licznik dla danego znaku w tablicy zliczającej znaki w słowie
	for (int i = 0; i < 62; i++) {
		if (character == characters_array[i]) {
			numb_of_chars_array[i]++; 
		}
	}
}

void count_letters(string word){ //liczy litery w zadanym słowie
	zero_counter();
	for (int i = 0; i < word.size(); i++) { 
		char character = word[i];
		check_character(character);
	}
	cout <<"Slowo: "<< word << endl;
	for (int i = 0; i < 62; i++) {
		if (numb_of_chars_array[i] != 0) {
			cout << "Znak '" << characters_array[i] << "' wystepuje " << numb_of_chars_array[i] << " razy." << endl;
		}
	}
	cout << endl;

}


int main(int argc, char *argv[])
{
	int i = 1;
	fill_array(0, 26, 65);
	fill_array(26, 52, 97);
	fill_array(52, 62, 48);
	while (i < argc) {
		count_letters(argv[i]);
		i++;
	}
	system("pause");
    return 0;
}

