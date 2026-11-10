#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string accountNumber, customerName;
    double balance = 0;
    int deposits = 0, withdrawals = 0, rejected = 0;
    bool created = false;

public:
    bool isCreated()
    {
        return created;
    }

    void createAccount(string number, string name, double amount)
    {
        if (number.empty() || name.empty())
            cout << "Account number and name cannot be empty.\n";
        else if (amount < 0)
            cout << "Opening balance cannot be negative.\n";
        else
        {
            accountNumber = number;
            customerName = name;
            balance = amount;
            created = true;
            cout << "Account created successfully.\n";
        }
    }

    void deposit(double amount)
    {
        if (amount <= 0)
        {
            rejected++;
            cout << "Deposit rejected: Invalid amount.\n";
        }
        else
        {
            balance += amount;
            deposits++;
            cout << "Deposit successful.\n";
            cout << "Balance: " << balance << "\n";
        }
    }

    void withdraw(double amount)
    {
        if (amount <= 0 || amount > balance)
        {
            rejected++;

            if (amount <= 0)
                cout << "Withdrawal rejected: Invalid amount.\n";
            else
                cout << "Withdrawal rejected: Insufficient balance.\n";
        }
        else
        {
            balance -= amount;
            withdrawals++;
            cout << "Withdrawal successful.\n";
            cout << "Balance: " << balance << "\n";
        }
    }

    void checkBalance()
    {
        cout << "Current balance: " << balance << "\n";
    }

    void displayAccount()
    {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nCustomer Name: " << customerName;
        cout << "\nBalance: " << balance << "\n";
    }

    void displaySummary()
    {
        cout << "\nSuccessful Deposits: " << deposits;
        cout << "\nSuccessful Withdrawals: " << withdrawals;
        cout << "\nRejected Transactions: " << rejected;
        cout << "\nFinal Balance: " << balance << "\n";
    }
};

int main()
{
    BankAccount account;

    int choice;
    string number, name;
    double amount;

    while (true)
    {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Balance Enquiry\n";
        cout << "5. Display Account Details\n";
        cout << "6. Transaction Summary\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            if (cin.eof()) break;

            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input.\n";
            continue;
        }

        cin.ignore(10000, '\n');

        if (choice == 7)
        {
            cout << "Thank you for using our bank.\n";
            break;
        }

        if (choice < 1 || choice > 7)
        {
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        if (choice == 1 && account.isCreated())
        {
            cout << "Account already exists.\n";
            continue;
        }

        if (choice != 1 && !account.isCreated())
        {
            cout << "Please create an account first.\n";
            continue;
        }

        if (choice == 1)
        {
            cout << "Enter account number: ";
            getline(cin, number);

            cout << "Enter customer name: ";
            getline(cin, name);

            cout << "Enter opening balance: ";
        }
        else if (choice == 2 || choice == 3)
        {
            cout << "Enter amount: ";
        }

        if (choice >= 1 && choice <= 3)
        {
            if (!(cin >> amount))
            {
                if (cin.eof()) break;

                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid amount.\n";
                continue;
            }
            cin.ignore(10000, '\n');
        }

        switch (choice)
        {
            case 1:
                account.createAccount(number, name, amount);
                break;

            case 2:
                account.deposit(amount);
                break;

            case 3:
                account.withdraw(amount);
                break;

            case 4:
                account.checkBalance();
                break;

            case 5:
                account.displayAccount();
                break;

            case 6:
                account.displaySummary();
                break;
        }
    }

    return 0;
}
