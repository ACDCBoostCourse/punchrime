
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. typedef ����

typedef string transactionName_t;  //typedef���� ���� Ÿ���� ��Ī�� �����ϰ� ���� Ÿ���� �̸� ��� �� ��Ī�� ��밡��. typedef <�ڷ���> <��Ī> 
typedef int won_t;  // won_t�� int�� �ڷ����� ��Ī���� ����
typedef string name_t;

// 2. Transaction ����ü ����

struct Transaction {  //struct : �ϳ� �̻��� ������ �׷���� ���ο� �ڷ����� �����ϴ� �� 

    //Attributes
    transactionName_t transactionName;
    won_t depositAndWithdrawal;

};

// 3. DayOfTheWeek Enum ����

enum DayOfTheWeek {   //������ : ������ ��� ���� ��ȣ ���(������)���� ���ǵǴ� �ڷ���

    Monday = 0,
    Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday

};

// 4. BankAccount Ŭ���� ����

class BankAccount {    // ������ �Լ��� �Բ� ������ �� �ִ� Ŭ����
    // Attributes
private:   //�⺻ ���� ����, �ܺο��� ������ �Ұ���
    name_t clientName;
    int password;
    int accountID;
    won_t accountBalance;
    DayOfTheWeek termDepositDay;
    Transaction transactionList[2];

public: // �ܺο����� ������ ����
    // Constructors
    BankAccount() : clientName("������"), password(1234), accountID(rand() % 10000), accountBalance(0), termDepositDay(Monday) {
        transactionList[0] = { .transactionName = "�ŷ� ����", .depositAndWithdrawal = 0 };
        transactionList[1] = { .transactionName = "�ŷ� ����", .depositAndWithdrawal = 0 };
        cout << clientName << "���� ���°� �����Ǿ����ϴ�. Account ID: " << accountID << endl;
    }

    BankAccount(name_t clientName, int password, DayOfTheWeek termDepositDay) : clientName(clientName), password(password), accountID(rand() % 10000), accountBalance(0), termDepositDay(termDepositDay) {
        transactionList[0] = { .transactionName = "�ŷ� ����", .depositAndWithdrawal = 0 };
        transactionList[1] = { .transactionName = "�ŷ� ����", .depositAndWithdrawal = 0 };
        cout << clientName << "���� ���°� �����Ǿ����ϴ�. Account ID: ";
        printf("%04d\n", accountID);
    }

    // Destructor
    ~BankAccount() {
        cout << clientName << "���� ���°� �����Ǿ����ϴ�. Account ID: ";
        printf("%04d\n", accountID);
        // ���� Ŭ������ ��� ���� �� ���� �Ҵ�� ��� ������ �ִٸ�
    // ���� �Ҹ��ڿ��� ���� �Ҵ� �޸� ����!
    // �� ���ÿ��� ��������� ���� �Ҵ�� ���� �����Ƿ�
    // ���� ������ �� ���� ����!
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
            break; // ��� ������ ���ָ� �� �Լ��� Ż���ϹǷ� ������ break�� ��� �ʿ� ����.

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
            cout << "�ŷ� �̸�: " << transactionList[i].transactionName << "  �ŷ� �ݾ�: " << transactionList[i].depositAndWithdrawal << endl;
        }
    }

    void addTransaction(name_t transactionName, won_t depositAndWithdrawal) {
        for (int i = 0; i < 2; i++) {
            if (transactionList[i].transactionName == "�ŷ� ����") {
                transactionList[i].transactionName = transactionName;
                transactionList[i].depositAndWithdrawal = depositAndWithdrawal;
                accountBalance += depositAndWithdrawal;
                break; // �� ���������� ���� �������� �迭 2���� ��� ������� ��쿡 ��ó ����� ����ġ ������...... (���� �Ҵ�) -> ���� �Ҵ��� �̿��ϸ� �� �� �� �� �迭 ũ�⸦ �ٲ� �� �ֽ��ϴ�!
            }
        }
    }

    // mergeAccount �Լ����� accountBalance�� �����ϱ� ���� �߰������� �޼��� �Ʒ��� ���� ����
    void mergeAccountBalance(won_t mergedMoney) {
        accountBalance += mergedMoney;
    }

    // 6�� �������� accountID�� �����ϱ� ���� Getter �߰�
    int getAccountID() {
        return accountID;
    }
};

// 6. mergeAccount �Լ� ���� (Call by Pointer ������ Call by Reference ���� ��� �ۼ��ص帮�� �������ּ���!)
// int, float�� ���� �Ϲ� ������ ���� Pointer�� &�� �̿��� ���� ����������
// Class�� ��� -> �� �̿��� ���� �����մϴ�!

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

// 5. Main �Լ� ����
int main() {
    srand(time(NULL));
    name_t name;
    int password;
    int temp;
    DayOfTheWeek dayOfTheWeek;
    transactionName_t transactionName;
    won_t money;

    // A, B ���� ���
    cout << "�̸��� �Է����ּ���." << endl;
    cin >> name;
    cout << "��й�ȣ�� �Է����ּ���." << endl;
    cin >> password;
    cout << "���� ���� ������ ���ڷ� �Է����ּ���. \n������ - 1\nȭ���� - 2\n������ - 3\n����� - 4\n�ݿ��� - 5\n����� - 6\n�Ͽ��� - 7" << endl;
    cin >> temp;
    dayOfTheWeek = (DayOfTheWeek)(temp - 1);

    BankAccount A(name, password, dayOfTheWeek);

    cout << "�̸��� �Է����ּ���." << endl;
    cin >> name;
    cout << "��й�ȣ�� �Է����ּ���." << endl;
    cin >> password;
    cout << "���� ���� ������ ���ڷ� �Է����ּ���. \n������ - 1\nȭ���� - 2\n������ - 3\n����� - 4\n�ݿ��� - 5\n����� - 6\n�Ͽ��� - 7" << endl;
    cin >> temp;
    dayOfTheWeek = (DayOfTheWeek)(temp - 1);

    BankAccount B(name, password, dayOfTheWeek);

    // A, B ����
    cout << "�ŷ� �̸��� ������ �ݾ��� �Է����ּ���." << endl;
    cout << "�ŷ� �̸�: ";
    cin >> transactionName;
    cout << "������ �ݾ�: ";
    cin >> money;

    A.addTransaction(transactionName, money);
    cout << "���� �ܾ�: " << A.getAccountBalance() << endl;
    A.printTransactionList();

    cout << "�ŷ� �̸��� ������ �ݾ��� �Է����ּ���." << endl;
    cout << "�ŷ� �̸�: ";
    cin >> transactionName;
    cout << "������ �ݾ�: ";
    cin >> money;

    B.addTransaction(transactionName, money);
    cout << "���� �ܾ�: " << B.getAccountBalance() << endl;
    B.printTransactionList();

    // A ���� ����
    cout << "�ٲ� ������ �Է����ּ���. \n������ - 1\nȭ���� - 2\n������ - 3\n����� - 4\n�ݿ��� - 5\n����� - 6\n�Ͽ��� - 7" << endl;
    cin >> temp;
    cout << "�ٲٱ� �� ���� : " << A.getDayOfTheWeek() << endl;
    dayOfTheWeek = (DayOfTheWeek)(temp - 1);
    A.setDayOfTheWeek(dayOfTheWeek);
    cout << "�ٲ� �� ���� : " << A.getDayOfTheWeek() << endl;

    // B ���

    cout << "�ŷ� �̸��� ����� �ݾ� (������ �Է�) �� �Է����ּ���." << endl;
    cout << "�ŷ� �̸�: ";
    cin >> transactionName;
    cout << "����� �ݾ�: ";
    cin >> money;

    B.addTransaction(transactionName, money);
    cout << "���� �ݾ� : " << B.getAccountBalance() << endl;
    B.printTransactionList();

    // ���� ��ġ��
    mergeAccount(A, B);
    // ���⿡�� �ν��Ͻ� B�� �����Ͽ� �޸� ���� ���� �ʰ� �ϴ� ���� �� ���� �ڵ�!
    // �׷��� ���⿡�� B�� ���� �Ҵ����� ����������Ƿ� B�� �����ϴ°� �Ұ���!
    // �� B�� �Ҹ��� ȣ�� �� B�� �޸𸮿��� ���Ŵ� ���α׷��� ����� ���� �Ǽ��� ��μ� �̷����
    // ����ο��� BankAccount *B = new BankAccount(name, password, dayOfTheWeek)
    // �̷��� ���� �Ҵ����� ����ٸ� 
    // delete B; (�� ���� B�� �Ҹ��ڰ� ȣ��)
    // B = NULL;
    // �̷��� ������ ����!

    cout << "��ģ ���� �̸�: " << A.getName() << endl;
    cout << "��ģ ���� �ܰ�: " << A.getAccountBalance() << endl;
    cout << "��ģ ���� ID: " << A.getAccountID() << endl;
    cout << "��ģ ���� ��й�ȣ: " << A.getPassword() << endl;
    A.printTransactionList();
    cout << A.getDayOfTheWeek() << endl;

    return 0;

}
