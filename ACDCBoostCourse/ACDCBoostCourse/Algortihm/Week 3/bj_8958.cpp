#include <iostream>
#inlclude <string>
using namespace std;

int main() {
	int count; //������
	int score; //������
	int n; 
	char array[80]; //ox���ڿ�

	cin >> array; //���ڿ� �Է�
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