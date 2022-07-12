#include <iostream>
using namespace std;

int main() {
	int n = 0;
	int score;
	int max = 0;
	double result = 0;

	cin >> n;
	double array[1000];
	
	for (int i = 0; i < n; i++) {
		cin >> array[i];
		if (max < array[i])
			max = array[i];
	}

	for (int i = 0; i < n; i++) {
		array[i] = array[i] / max * 100;
		result += array[i];
	}

	cout << result / n;
	return 0;
}