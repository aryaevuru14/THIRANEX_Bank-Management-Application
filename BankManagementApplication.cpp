#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    char name[50];
    double balance;

public:
    void createAccount() {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;
        cin.ignore();
        cout << "Enter Account Holder Name: ";
        cin.getline(name, 50);
        cout << "Enter Initial Balance: ";
        cin >> balance;
        cout << "\n[Success] Account created successfully!\n";
    }

    void showAccount() const {
        cout << left << setw(15) << accountNumber
             << setw(25) << name
             << setw(15) << fixed << setprecision(2) << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "\n[Success] Amount deposited. New Balance: $" << balance << endl;
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "\n[Error] Insufficient balance!\n";
            return false;
        }
        balance -= amount;
        cout << "\n[Success] Amount withdrawn. Remaining Balance: $" << balance << endl;
        return true;
    }

    int getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }

    void writeToFile() const {
        ofstream outFile("bank_data.dat", ios::binary | ios::app);
        outFile.write(reinterpret_cast<const char*>(this), sizeof(*this));
        outFile.close();
    }
};

void displayAllAccounts() {
    ifstream inFile("bank_data.dat", ios::binary);
    if (!inFile) {
        cout << "\nNo records found!\n";
        return;
    }
    BankAccount acc;
    cout << "\n----------------------------------------------------\n";
    cout << left << setw(15) << "Account No." << setw(25) << "Holder Name" << setw(15) << "Balance" << endl;
    cout << "----------------------------------------------------\n";
    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(acc))) {
        acc.showAccount();
    }
    inFile.close();
}

void depositWithdraw(int accNo, int option) {
    fstream file("bank_data.dat", ios::binary | ios::in | ios::out);
    if (!file) {
        cout << "\nFile could not be opened!\n";
        return;
    }
    BankAccount acc;
    bool found = false;
    while (!file.eof() && file.read(reinterpret_cast<char*>(&acc), sizeof(acc))) {
        if (acc.getAccountNumber() == accNo) {
            found = true;
            double amount;
            if (option == 1) {
                cout << "Enter Deposit Amount: ";
                cin >> amount;
                acc.deposit(amount);
            } else if (option == 2) {
                cout << "Enter Withdrawal Amount: ";
                cin >> amount;
                acc.withdraw(amount);
            }
            int pos = (-1) * static_cast<int>(sizeof(acc));
            file.seekp(pos, ios::cur);
            file.write(reinterpret_cast<char*>(&acc), sizeof(acc));
            break;
        }
    }
    file.close();
    if (!found) cout << "\nAccount Not Found!\n";
}

void checkBalance(int accNo) {
    ifstream inFile("bank_data.dat", ios::binary);
    if (!inFile) {
        cout << "\nFile could not be opened!\n";
        return;
    }
    BankAccount acc;
    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(acc))) {
        if (acc.getAccountNumber() == accNo) {
            cout << "\n--- Account Details ---\n";
            cout << "Account Number: " << acc.getAccountNumber() << endl;
            cout << "Current Balance: $" << fixed << setprecision(2) << acc.getBalance() << endl;
            found = true;
            break;
        }
    }
    inFile.close();
    if (!found) cout << "\nAccount Not Found!\n";
}

int main() {
    int choice, accNo;
    do {
        cout << "\n=== BANK MANAGEMENT SYSTEM ===";
        cout << "\n1. Create New Account";
        cout << "\n2. Deposit Amount";
        cout << "\n3. Withdraw Amount";
        cout << "\n4. Check Balance";
        cout << "\n5. Display All Accounts";
        cout << "\n6. Exit";
        cout << "\nEnter choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                BankAccount acc;
                acc.createAccount();
                acc.writeToFile();
                break;
            }
            case 2:
                cout << "Enter Account Number: "; cin >> accNo;
                depositWithdraw(accNo, 1);
                break;
            case 3:
                cout << "Enter Account Number: "; cin >> accNo;
                depositWithdraw(accNo, 2);
                break;
            case 4:
                cout << "Enter Account Number: "; cin >> accNo;
                checkBalance(accNo);
                break;
            case 5:
                displayAllAccounts();
                break;
            case 6:
                cout << "\nExiting Bank Management Application...\n";
                break;
            default:
                cout << "\nInvalid Choice!\n";
        }
    } while (choice != 6);

    return 0;
}