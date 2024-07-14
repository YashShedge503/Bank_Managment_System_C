#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define MAX_ACCOUNTS 10 // Maximum number of accounts

typedef struct {
    char name[20];
    int account_number;
    int balance;
    int transaction_count;
} Account;

Account accounts[MAX_ACCOUNTS]; // Array to store accounts

int num_accounts = 0; // Variable to keep track of the number of accounts

void deposit_money(Account *account);
void withdraw_money(Account *account);
void transfer_money(Account *sender, Account *receiver);
void checkDetail(Account *account);
void transaction_details(Account *account);
void menu();

void divider() {
    for (int i = 0; i < 50; i++) {
        printf("-");
    }
}

int main() {
    int ch;
    while (1) {
        menu();
        printf("\nEnter your choice :\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                system("cls");
                deposit_money(&accounts[0]);
                break;
            case 2:
                system("cls");
                withdraw_money(&accounts[0]);
                break;
            case 3:
                system("cls");
                transfer_money(&accounts[0], &accounts[1]);
                break;
            case 4:
                system("cls");
                checkDetail(&accounts[0]);
                break;
            case 5:
                transaction_details(&accounts[0]);
                break;
            case 6:
                system("cls");
                exit(0);
            default:
                printf("**Invalid choice**");
        }
    }

    return 0;
}

void menu() {
    system("cls");
    divider();
    printf("\n\tMENU\n");
    divider();
    printf("\n1.Deposit Money\n");
    printf("2.Withdraw Money\n");
    printf("3.Transfer Money\n");
    printf("4.Account details\n");
    printf("5.Transaction details\n");
    printf("6.Exit\n");
    divider();
}

void deposit_money(Account *account) {
    time_t tm;
    time(&tm);

    printf("**DEPOSITING MONEY**\n");
    divider();

    printf("\nEnter the amount you want to deposit\n");
    scanf("%d", &account->balance);
    account->balance += account->balance;
    printf("*Money Deposited*\n");
    printf("Balance of account : %d\n", account->balance);
    printf("\nRs%d had been deposited to your account \n", account->balance);
    printf("Date/Time of transaction: %s\n", ctime(&tm));
    account->transaction_count++;

    printf("Press any key....\n");
    getch();
}

void withdraw_money(Account *account) {
    time_t tm;
    time(&tm);

    printf("**WITHDRAWING MONEY**\n");
    divider();

    printf("\nEnter the amount you want to withdraw\n");
    scanf("%d", &account->balance);

    if (account->balance < account->balance) {
        printf("*Insufficient balance*\n");
    } else {
        account->balance -= account->balance;
        printf("**Money withdrawn**\n");
        printf("Current balance : %d\n", account->balance);
        printf("\nRs%d had been withdrawn from your account \n", account->balance);
        printf("Date/Time of transaction: %s\n", ctime(&tm));
        account->transaction_count++;
    }

    printf("Press any key....\n");
    getch();
}

void transfer_money(Account *sender, Account *receiver) {
    time_t tm;
    time(&tm);

    printf("**TRANSFERRING MONEY**\n");
    divider();

    printf("\nEnter the amount you want to transfer\n");
    scanf("%d", &sender->balance);

    if (sender->balance < sender->balance) {
        printf("*You have not sufficient balance*\n");
    } else {
        sender->balance -= sender->balance;
        receiver->balance += sender->balance;
        printf("*Money Transferred*\n");
        printf("Current balance of sender: %d\n", sender->balance);
        printf("Current balance of receiver: %d\n", receiver->balance);
        printf("\nRs%d had been transferred from your account to %d\n", sender->balance, receiver->account_number);
        printf("Date/Time of transaction: %s\n", ctime(&tm));
        sender->transaction_count++;
    }

    printf("Press any key....\n");
    getch();
}

void checkDetail(Account *account) {
    printf("ACCOUNT DETAILS\n");
    divider();
    printf("\nName : %s\n", account->name);
    printf("Account No. : %d\n", account->account_number);
    printf("Total balance = %d\n ", account->balance);
    printf("\n%d transactions have been made from your account \n", account->transaction_count);
    printf("Press any key.....");
    getch();
}

void transaction_details(Account *account) {
    system("cls");

    printf("TRANSACTION DETAILS\n");
    divider();
    printf("\n%d transactions have been made from your account \n", account->transaction_count);

    printf("\nPress any key....\n");
    getch();
}