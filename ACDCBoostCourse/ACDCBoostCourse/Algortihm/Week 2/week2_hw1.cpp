#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int alpha[26] = { 0, };
	int max_count = 0;
	int index = 0;
	int count = 0;

	cin >> str; 

	for (int i = 0; i < str.length(); i++) {
		int n = str[i];
		if (n < 97)
			alpha[n - 65]++;
		else
			alpha[n - 97]++;
	}

	for (int i = 0; i < 26; i++) {
		if (alpha[i] > max_count) {
			max_count = alpha[i];
			index = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (alpha[i] == max_count) {
			count++;
			if (count >= 2) {
				cout << "?" << endl;
				return 0;
			}
		}
	}

	cout << (char)(index + 65) << endl;
	return 0;

}