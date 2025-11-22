#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    int acc_no;
    char name[50];
    float balance;
};

void createAccount();
void deposit();
void withdrawMoney();
void displayAccount();
void listAll();
int accountExists(int acc_no);

int main() {
    int choice;

    while (1) {
        printf("\n\n===== BANK MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account Details\n");
        printf("5. List All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdrawMoney(); break;
            case 4: displayAccount(); break;
            case 5: listAll(); break;
            case 6: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void createAccount() {
    struct account acc;
    FILE *fp = fopen("bank.dat","ab");

    printf("Enter Account Number: ");
    scanf("%d", &acc.acc_no);

    if (accountExists(acc.acc_no)) {
        printf("Account already exists!\n");
        fclose(fp);
        return;
    }

    printf("Enter Account Holder Name: ");
    scanf("%s", acc.name);

    acc.balance = 0.0;

    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);

    printf("Account Created Successfully!\n");
}

void deposit() {
    int acc_no;
    float amount;
    struct account acc;
    int found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &acc_no);

    FILE *fp = fopen("bank.dat", "rb+");

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.acc_no == acc_no) {
            printf("Enter Deposit Amount: ");
            scanf("%f", &amount);

            acc.balance += amount;
            fseek(fp, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);

            printf("Amount Deposited Successfully!\n");
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Account Not Found!\n");
}

void withdrawMoney() {
    int acc_no;
    float amount;
    struct account acc;
    int found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &acc_no);

    FILE *fp = fopen("bank.dat", "rb+");

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.acc_no == acc_no) {
            printf("Enter Withdrawal Amount: ");
            scanf("%f", &amount);

            if (amount > acc.balance) {
                printf("Insufficient Balance!\n");
            } else {
                acc.balance -= amount;
                fseek(fp, -sizeof(acc), SEEK_CUR);
                fwrite(&acc, sizeof(acc), 1, fp);
                printf("Amount Withdrawn Successfully!\n");
            }

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Account Not Found!\n");
}

void displayAccount() {
    int acc_no;
    struct account acc;
    int found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &acc_no);

    FILE *fp = fopen("bank.dat", "rb");

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.acc_no == acc_no) {
            printf("\n--- Account Details ---\n");
            printf("Account No: %d\n", acc.acc_no);
            printf("Name: %s\n", acc.name);
            printf("Balance: %.2f\n", acc.balance);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Account Not Found!\n");
}

void listAll() {
    struct account acc;
    FILE *fp = fopen("bank.dat", "rb");

    printf("\n===== All Accounts =====\n");

    while (fread(&acc, sizeof(acc), 1, fp)) {
        printf("Acc No: %d | Name: %s | Balance: %.2f\n",
               acc.acc_no, acc.name, acc.balance);
    }

    fclose(fp);
}

int accountExists(int acc_no) {
    struct account acc;
    FILE *fp = fopen("bank.dat", "rb");

    if (!fp) return 0;

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.acc_no == acc_no) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}
