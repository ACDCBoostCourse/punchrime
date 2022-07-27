#include <iostream>
using namespace std;

class vector2 {
public:
	vector2() :x(0), y(0) {
		cout << this << " : vector2()" << endl;
	}
	vector2(const float x, const float y) :x(x), y(y) {
		cout << this << " : vector2(const float x, const float y)" << endl;
	}
	~vector2() {
		cout << this << " : ~vector2()" << endl;
	}

	float GetX() const { return x; }
	float GetY() const { return y; }

private:
	float x;
	float y;
};

int main() {
	vector2 s1 = vector2();
	vector2 s2 = vector2(3, 2);

	vector2* d1 = new vector2();
	vector2* d2 = new vector2(3, 2);

	cout << "(" << d1->GetX() << ", " << d1->GetY() << ")" << endl;
	cout << "(" << d2->GetX() << ", " << d2->GetY() << ")" << endl;

	delete d1;
	delete d2;