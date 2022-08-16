//62강 연산자 오버로딩

#include <iostream>
#include <stdio.h>
using namespace std;

#include <iostream>
#include <stdio.h>
using namespace std;

class Vector2 {
public:

	Vector2();   //: x(0), y(0) {}
	Vector2(float x, float y);  // : x(x), y(x) {}

	float GetX() const;  //{ return x; }
	float GetY() const;  //{ return y; }


	//static Vector2 Sum(Vector2 a, Vector2 b) {
		//return Vector2(a.x + b.x, a.y + b.y);

	//}
	//static Vector2 Sum(Vector2 a, Vector2 b) {
		//return Vector2(a.x + b.x, a.y + b.y);
	//}
	Vector2 operator+(const Vector2 rhs) const;   //멤버연산자
	Vector2 operator-(const Vector2 rhs) const;
	Vector2 operator*(const float rhs) const;
	Vector2 operator/(const float rhs) const;
	Vector2 operator*(const Vector2 rhs) const;

private:
	float x;
	float y;
};


Vector2 operator*(const float a, const Vector2 b){   //비멤버연산자
	return Vector2(a * b.GetX(), a * b.GetY());

}

int main() {
	Vector2 a(2, 3);
	Vector2 b(-1, 4);
	//Vector2 c = a + b; // 벡터 두개를 더할 수 없다 왜냐하면 컴퓨터는 이름만 벡터인 클래스로 인식하니까 
	Vector2 c1 = a - b;
	Vector2 c2 = a * 1.6;  //객체에서만 operator가 가능
	Vector2 c3 = 1.6 * a;
	float c4 = a * b;


	cout << a.GetX() << "," << a.GetY() << endl;
	cout << b.GetX() << "," << b.GetY() << endl;
	cout << c1.GetX() << "," << c1.GetY() << endl;
	cout << c2.GetX() << "," << c2.GetY() << endl;
	cout << c3.GetX() << "," << c3.GetY() << endl;
	cout << c4 << endl;
}

Vector2::Vector2() : x(0), y(0) {} //vector2라는 메서드가 class 안에 속해있다 
Vector2::Vector2(float x, float y) : x(x), y(y) {}
float Vector2::GetX() const { return x; }
float Vector2::GetY() const { return y; }


Vector2 Vector2::operator+(const Vector2 rhs) const {
		return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator-(const Vector2 rhs) const {
	return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator*(const float rhs) const {
	return Vector2(x * rhs, y * rhs);
}

Vector2 Vector2::operator/(const float rhs) const {
	return Vector2(x / rhs, y / rhs);
}

Vector2 Vector2::operator*(const Vector2 rhs) const {
	return x * rhs.x + y * rhs.y;
}
