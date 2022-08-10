
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. typedef 선언

typedef string transactionName_t;  //typedef사용시 기존 타입의 별칭을 생성하고 실제 타입의 이름 대신 그 별칭을 사용가능. typedef <자료형> <별칭> 
typedef int won_t;  // won_t를 int의 자료형의 별칭으로 지정
typedef string name_t;

// 2. Transaction 구조체 정의

struct Transaction {  //struct : 하나 이상의 변수를 그룹지어서 새로운 자료형을 정의하는 것 

    //Attributes
    transactionName_t transactionName;
    won_t depositAndWithdrawal;

};

// 3. DayOfTheWeek Enum 정의

enum DayOfTheWeek {   //열거형 : 가능한 모든 값이 기호 상수(열거형)으로 정의되는 자료형

    Monday = 0,
    Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday

};

// 4. BankAccount 클래스 정의

class BankAccount {    // 변수와 함수를 함께 포함할 수 있는 클래스
    // Attributes
private:   //기본 접근 제한, 외부에서 접근이 불가능
    name_t clientName;
    int password;
    int accountID;
    won_t accountBalance;
    DayOfTheWeek termDepositDay;
    Transaction transactionList[2];

public: // 외부에서도 접근이 가능
    // Constructors
    BankAccount() : clientName("이의진"), password(1234), accountID(rand() % 10000), accountBalance(0), termDepositDay(Monday) {
        transactionList[0] = { .transactionName = "거래 없음", .depositAndWithdrawal = 0 };
        transactionList[1] = { .transactionName = "거래 없음", .depositAndWithdrawal = 0 };
        cout << clientName << "님의 계좌가 생성되었습니다. Account ID: " << accountID << endl;
    }

    BankAccount(name_t clientName, int password, DayOfTheWeek termDepositDay) : clientName(clientName), password(password), accountID(rand() % 10000), accountBalance(0), termDepositDay(termDepositDay) {
        transactionList[0] = { .transactionName = "거래 없음", .depositAndWithdrawal = 0 };
        transactionList[1] = { .transactionName = "거래 없음", .depositAndWithdrawal = 0 };
        cout << clientName << "님의 계좌가 생성되었습니다. Account ID: ";
        printf("%04d\n", accountID);
    }

    // Destructor
    ~BankAccount() {
        cout << clientName << "님의 계좌가 삭제되었습니다. Account ID: ";
        printf("%04d\n", accountID);
        // 만약 클래스의 멤버 변수 중 동적 할당된 멤버 변수가 있다면
    // 여기 소멸자에서 동적 할당 메모리 해제!
    // 이 예시에는 멤버변수에 동적 할당된 것이 없으므로
    // 따로 해제해 줄 놈이 없다!
    }

    // Methods
    name_t getName() {
        return clientName;
    }

    won_t getAccountBalance() {
        return accountBalance;
    }

    int getPassword() {
        return password;
    }

    string getDayOfTheWeek() {
        switch (termDepositDay) {
        case Monday:
            return "Monday";
            break; // 사실 리턴을 해주면 이 함수를 탈출하므로 여기의 break는 사실 필요 없음.

        case Tuesday:
            return "Tuesday";
            break;

        case Wednesday:
            return "Wednesday";
            break;

        case Thursday:
            return "Thursday";
            break;

        case Friday:
            return "Friday";
            break;

        case Saturday:
            return "Saturday";
            break;

        case Sunday:
            return "Sunday";
            break;

        default:
            break;
        }
    }

    void setDayOfTheWeek(DayOfTheWeek termDepositDay) {
        this->termDepositDay = termDepositDay;
    }

    void printTransactionList() {
        for (int i = 0; i < 2; i++) {
            cout << "거래 이름: " << transactionList[i].transactionName << "  거래 금액: " << transactionList[i].depositAndWithdrawal << endl;
        }
    }

    void addTransaction(name_t transactionName, won_t depositAndWithdrawal) {
        for (int i = 0; i < 2; i++) {
            if (transactionList[i].transactionName == "거래 없음") {
                transactionList[i].transactionName = transactionName;
                transactionList[i].depositAndWithdrawal = depositAndWithdrawal;
                accountBalance += depositAndWithdrawal;
                break; // 이 문제에서는 구현 안했지만 배열 2개를 모두 사용했을 경우에 대처 방안이 마땅치 않은데...... (정적 할당) -> 동적 할당을 이용하면 그 때 그 때 배열 크기를 바꿀 수 있습니다!
            }
        }
    }

    // mergeAccount 함수에서 accountBalance에 접근하기 위해 추가적으로 메서드 아래와 같이 구현
    void mergeAccountBalance(won_t mergedMoney) {
        accountBalance += mergedMoney;
    }

    // 6번 문제에서 accountID에 접근하기 위해 Getter 추가
    int getAccountID() {
        return accountID;
    }
};

// 6. mergeAccount 함수 구현 (Call by Pointer 구현과 Call by Reference 구현 모두 작성해드리니 참고해주세요!)
// int, float와 같은 일반 변수에 대한 Pointer는 &을 이용해 값에 접근하지만
// Class의 경우 -> 를 이용해 값에 접근합니다!

// Call By Pointer
void mergeAccount(BankAccount* absorbing, BankAccount* absorbed) {
    won_t mergedMoney = absorbed->getAccountBalance();
    absorbing->mergeAccountBalance(mergedMoney);
}

// Call by Reference
void mergeAccount(BankAccount& absorbing, BankAccount& absorbed) {
    won_t mergedMoney = absorbed.getAccountBalance();
    absorbing.mergeAccountBalance(mergedMoney);
}

// 5. Main 함수 구현
int main() {
    srand(time(NULL));
    name_t name;
    int password;
    int temp;
    DayOfTheWeek dayOfTheWeek;
    transactionName_t transactionName;
    won_t money;

    // A, B 계좌 등록
    cout << "이름을 입력해주세요." << endl;
    cin >> name;
    cout << "비밀번호를 입력해주세요." << endl;
    cin >> password;
    cout << "정기 예금 요일을 숫자로 입력해주세요. \n월요일 - 1\n화요일 - 2\n수요일 - 3\n목요일 - 4\n금요일 - 5\n토요일 - 6\n일요일 - 7" << endl;
    cin >> temp;
    dayOfTheWeek = (DayOfTheWeek)(temp - 1);

    BankAccount A(name, password, dayOfTheWeek);

    cout << "이름을 입력해주세요." << endl;
    cin >> name;
    cout << "비밀번호를 입력해주세요." << endl;
    cin >> password;
    cout << "정기 예금 요일을 숫자로 입력해주세요. \n월요일 - 1\n화요일 - 2\n수요일 - 3\n목요일 - 4\n금요일 - 5\n토요일 - 6\n일요일 - 7" << endl;
    cin >> temp;
    dayOfTheWeek = (DayOfTheWeek)(temp - 1);

    BankAccount B(name, password, dayOfTheWeek);

    // A, B 예금
    cout << "거래 이름과 예금할 금액을 입력해주세요." << endl;
    cout << "거래 이름: ";
    cin >> transactionName;
    cout << "예금할 금액: ";
    cin >> money;

    A.addTransaction(transactionName, money);
    cout << "계좌 잔액: " << A.getAccountBalance() << endl;
    A.printTransactionList();

    cout << "거래 이름과 예금할 금액을 입력해주세요." << endl;
    cout << "거래 이름: ";
    cin >> transactionName;
    cout << "예금할 금액: ";
    cin >> money;

    B.addTransaction(transactionName, money);
    cout << "계좌 잔액: " << B.getAccountBalance() << endl;
    B.printTransactionList();

    // A 요일 변경
    cout << "바꿀 요일을 입력해주세요. \n월요일 - 1\n화요일 - 2\n수요일 - 3\n목요일 - 4\n금요일 - 5\n토요일 - 6\n일요일 - 7" << endl;
    cin >> temp;
    cout << "바꾸기 전 요일 : " << A.getDayOfTheWeek() << endl;
    dayOfTheWeek = (DayOfTheWeek)(temp - 1);
    A.setDayOfTheWeek(dayOfTheWeek);
    cout << "바꾼 후 요일 : " << A.getDayOfTheWeek() << endl;

    // B 출금

    cout << "거래 이름과 출금할 금액 (음수로 입력) 을 입력해주세요." << endl;
    cout << "거래 이름: ";
    cin >> transactionName;
    cout << "출금할 금액: ";
    cin >> money;

    B.addTransaction(transactionName, money);
    cout << "남은 금액 : " << B.getAccountBalance() << endl;
    B.printTransactionList();

    // 계좌 합치기
    mergeAccount(A, B);
    // 여기에서 인스턴스 B를 제거하여 메모리 낭비를 하지 않게 하는 것이 더 좋은 코드!
    // 그러나 여기에선 B를 정적 할당으로 만들어줬으므로 B를 제거하는게 불가능!
    // 즉 B의 소멸자 호출 및 B를 메모리에서 제거는 프로그램이 종료될 때가 되서야 비로소 이루어짐
    // 선언부에서 BankAccount *B = new BankAccount(name, password, dayOfTheWeek)
    // 이렇게 동적 할당으로 해줬다면 
    // delete B; (이 순간 B의 소멸자가 호출)
    // B = NULL;
    // 이렇게 해제가 가능!

    cout << "합친 계좌 이름: " << A.getName() << endl;
    cout << "합친 계좌 잔고: " << A.getAccountBalance() << endl;
    cout << "합친 계좌 ID: " << A.getAccountID() << endl;
    cout << "합친 계좌 비밀번호: " << A.getPassword() << endl;
    A.printTransactionList();
    cout << A.getDayOfTheWeek() << endl;

    return 0;

}
