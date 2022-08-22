//76) 상속이 필요한 이유(1)

#include <iostream>
#include <string>

using namespace std;

class Image {
public:
	operator string() { // string으로 형변환을 하는 연산자를 오버로딩
		return "사진";
	}
};

class Message { 
public:
	Message(int sendTime, string sendName) {
		this->sendTime = sendTime;
		this->sendName = sendName;
	}
	int GetSendTime() const { return sendTime; }
	string GetSendName() const { return sendName; }

private:
	int sendTime;
	string sendName;
};

class TextMessage : public Message {
public:
	TextMessage(int sendTime, string sendName, string text)
		: Message(sendTime, sendName) {
		this->text = text;
	}

	string GetText() const { return text; }

private:
	string text;
};

class ImageMessage : public Message {
public:
	ImageMessage(int sendTime, string sendName, Image* image)
		: Message(sendTime, sendName) {
		this->image = image; 
	}

	Image* GetImage() const { return image; } 

private:
	Image* image; 
};

int main() {
	// 라임 : "안녕"
	// 라임 : "강아지 사진"
	Image* p_dogImage = new Image();
	TextMessage* hello = new TextMessage(10, "라임", "안녕");
	ImageMessage* dog = new ImageMessage(20, "라임", p_dogImage);

	cout << "보낸 시간 : " << hello->GetSendTime() << endl;
	cout << "보낸 사람 : " << hello->GetSendName() << endl;
	cout << " 내   용  : " << hello->GetText() << endl;
	cout << endl;

	cout << "보낸 시간 : " << dog->GetSendTime() << endl;
	cout << "보낸 사람 : " << dog->GetSendName() << endl;
	cout << " 내   용  : " << (string)*dog->GetImage() << endl;
	cout << endl;


	delete hello;
	delete dog;
	delete p_dogImage;
}