#include <iostream>
#include <math.h>
using namespace std;

class SavingAccount {
  public:
    SavingAccount(int id, int date, double rate);
    void deposit(int CurrentDate1, double OperationAmount1);
    void withdraw(int CurrentDate2, double OperationAmount2);
    void show(int CurrentDate3);
    int getLastDate() { return lastDate; }

  private:
    double OperationAmount;
    int id = 0;
    int CurrentDate = 0;
    int lastDate = 0;
    double ratePerDay = 0;
    double Sumbalance = 0;
    void record();
};
SavingAccount::SavingAccount(int id1, int date, double rate) {
    id = id1;
    lastDate = date;
    CurrentDate = date;
    ratePerDay = rate;
}
void SavingAccount::record() {
    Sumbalance = Sumbalance * pow((1 + ratePerDay), (CurrentDate - lastDate));
}
void SavingAccount::deposit(int CurrentDate1, double OperationAmount1) {
    if (CurrentDate1 >= lastDate) {
        cout << "calling the deposit function" << endl;
        CurrentDate = CurrentDate1;
        record();
        Sumbalance += OperationAmount1;
        lastDate = CurrentDate1;
        cout << "Finish!";
    }
}
void SavingAccount::withdraw(int CurrentDate2, double OperationAmount2) {
    if (CurrentDate2 >= lastDate) {
        if (Sumbalance >= OperationAmount2) {
            // cout << "calling the withdraw function " << endl;
            CurrentDate = CurrentDate2;
            record();
            lastDate = CurrentDate2;
            Sumbalance -= OperationAmount2;
            cout << "Finish!";
        } else
            cout << "No sufficient balance" << endl;
    }
}
void SavingAccount::show(int CurrentDate3) {
    // cout << "calling the show function" << endl;
    if (CurrentDate3 >= lastDate) {
        CurrentDate = CurrentDate3;
        record();
        lastDate = CurrentDate3;
        cout << "Current Date: " << CurrentDate3
             << " Account balance: " << Sumbalance << endl;
    } else
        cout << "Invalid Date" << endl;
}
int main() {
    SavingAccount xiaohong(0, 0, 0.000134);
    int flag = 0;
    while (true) {
        cout << "Do you want to open an account? Y/N?" << endl;
        char Judgement;
        cin >> Judgement;
        if (Judgement == 'Y' || Judgement == 'y') {
            cout << "Congratulations! General accout" << endl;
            flag = 1;
            break;
        }
    }
    while (flag) {
        cout << "What do you want to do? "
             << "1: deposit 2: withdraw 3: balance inquiry 0: exit" << endl;
        int Judge;
        double money = 0.0;
        int date = 0;
        cin >> Judge;
        switch (Judge) {
        case 1:
            cout << "The last operation was " << xiaohong.getLastDate()
                 << " days ago, ";
            cout << "What day is today? and how much do you want to deposit? "
                    "please space them off"
                 << endl;
            cin >> date >> money;
            xiaohong.deposit(date, money);
            xiaohong.show(date);
            break;
        case 2:
            cout << "The last operation was " << xiaohong.getLastDate()
                 << " days ago, ";
            cout << "What day is today? and how much do you want to withdraw? "
                    "please space them off"
                 << endl;
            cin >> date >> money;
            xiaohong.withdraw(date, money);
            xiaohong.show(date);
            break;
        case 3:
            cout << "The last operation was" << xiaohong.getLastDate()
                 << " days ago, ";
            cout << "What day is today?" << endl;
            cin >> date;
            xiaohong.show(date);
            break;
        case 0:
            flag = 0;
            break;
        }
    }
    return 0;
}