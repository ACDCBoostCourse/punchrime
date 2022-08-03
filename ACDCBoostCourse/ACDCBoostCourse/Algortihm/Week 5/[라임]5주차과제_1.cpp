#include <iostream>
using namespace std;

int main() {
	int startlink[10];
	int jamenis[10];
	int sum=0;
	int score_s=0;
	int score_j=0;

	for (int i = 1; i <= 9; i++)
		cin >> startlink[10];
	for (int i = 1; i <= 9; i++)
		cin >> jamenis[10];
	for (int i = 1; i <= 9; i++) {
		score_s = score_s + startlik[10];
		if (score_s > score_j) {
			cout << "YES" << endl;
			return 0;
		}
		score_j = score_j + jamenis[10];
	
	}

	cout << "NO " << endl;
	return 0;
}