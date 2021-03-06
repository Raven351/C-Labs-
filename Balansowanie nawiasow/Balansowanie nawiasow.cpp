#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
#include <assert.h>

using namespace std;

bool isBalanced(string s) {
	int length = s.length();
	if (s[0] == ')' || s[0] == ']' || s[0]== '}') return false;
	stack<char> c;
	for (int i = 0; i < length; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') c.push(s[i]);
		else {
			char top = c.top();
			c.pop();
			if (s[i] == ')' && top != '(') {
				return false;
			}
			if (s[i] == ']' && top != '[') {
				return false;
			}
			if (s[i] == '}' && top != '{')
				return false;		}
	}
	if (c.empty()) return true;
	else return false;
}

int main() {
	assert(isBalanced("()") == true);
	assert(isBalanced("(") == false);
	assert(isBalanced("[()]") == true);
	assert(isBalanced("({}])") == false);
	assert(isBalanced(")") == false);
	assert(isBalanced("))") == false);
	assert(isBalanced(")()") == false);
	assert(isBalanced("([)]") == false);
	assert(isBalanced("()()") == true);
	cout << "Kod wykonal sie poprawnie" << endl;
	system("pause");
	return 0;

}