#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <cstdio>

using namespace std;

double avg(double t[]) {
	double sum = 0;
	for (int i = 0; i < 12; i++) {
		sum += t[i];
	}
	return sum / 12;
}

double std_dev(double t[], double avg) {
	double sum = 0;
	for (int i = 0; i < 12; i++) {
		sum += (t[i]-avg) * (t[i] - avg);
	}
	sum = sum / 12;
	return sqrt(sum);
}

int main()
{
	while (!cin.eof()) {
		string nazwa;
		double temps[12];
		cin >> nazwa;
		for (int i = 0; i < 12; i++)
			cin >> temps[i];
		cout << nazwa << " avg = " << avg(temps) << " std_dev = " << std_dev(temps, avg(temps)) << endl;
	}
	system("pause");
	return 0;
}