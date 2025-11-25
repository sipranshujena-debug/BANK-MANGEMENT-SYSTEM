📘 Bank Management System (C Program)

This is a simple Bank Management System written in C.
It uses file handling (bank.dat) to store account details permanently.

The system allows you to:

Create new bank accounts

Deposit money

Withdraw money

Display a single account

List all accounts

Exit the program

This project is ideal for beginners learning C, file handling, and basic system design.

🚀 Features
✔ Create Account

Create a new account with an account number and holder name.

✔ Deposit Money

Add money to an existing account.

✔ Withdraw Money

Withdraw money (only if sufficient balance is available).

✔ Display Account

View details (name, account number, balance) of a specific account.

✔ List All Accounts

Show all accounts stored in the system.

✔ Persistent Storage

Account data is saved inside bank.dat so it remains available after program exit.

🛠 Technologies Used

C programming language

File handling (binary files)

Structures (struct)

Standard I/O

📂 Project Structure
/BankManagementSystem
│
├── bank.c        → Main program source code
├── bank.dat      → Auto-generated data file (after first run)
└── README.md     → Documentation

▶️ How to Compile and Run
Step 1: Compile
gcc bank.c -o bank

Step 2: Run
./bank

📝 Example Program Output
===== BANK MANAGEMENT SYSTEM =====
1. Create Account
2. Deposit Money
3. Withdraw Money
4. Display Account Details
5. List All Accounts
6. Exit
Enter your choice:

💾 Data Storage Format

All accounts are stored in:

bank.dat


Each record contains:

struct account {
    int acc_no;
    char name[50];
    float balance;
};

⚠️ Notes

Account numbers must be unique.

Only numeric input is supported for deposits/withdrawals.

Do not delete bank.dat unless you want to reset all accounts.

📘 Future Improvements (Optional)

If you want, you can extend the system with:

Password-protected login

Transaction history

Admin and user roles

Interest calculation

GUI using C++ or Python



AUTHOR: SIPRANSU JENA

![image alt](https://github.com/sipranshujena-debug/BANK-MANGEMENT-SYSTEM/blob/672a79222eb683c5229abd3143f1ef2c5ab6d010/Untitled%20design.png)

