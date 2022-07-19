#include <iostream>
#inlclude <string>
using namespace std;

int main() {
	int count; //누적값
	int score; //점수합
	int n; 
	char array[80]; //ox문자열

	cin >> array; //문자열 입력
	for (int i = 0; i <= strlen(array); i++) {
		if (array[i] == 'o', i++) {
			count++;
			score += count;
		}

		else if (array[i] == 'x', i++) {
			count = 0;
			score += count; 
		}
		return 0;
	}

}