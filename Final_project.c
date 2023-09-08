#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main();
void New_Account();
void View();
void Edit();
void Transact();
void Erase();
void See();
void Interest();

typedef struct Data
{
    char name[12];
    unsigned int date;
    unsigned int citizen;
    char address[12];
    char phone[11];
    int deposit;
    int amount;
    int acc_num;
}Acc, Upd,Trans;
Acc a[1000];
int number_clients = 0;

int Menu() {

    int choice;
    printf("------------------------------------------------------------------------------\n");
    printf("MENU\n");
    printf("1.New account\n");
    printf("2.View list\n");
    printf("3.Edit\n");
    printf("4.Transact\n");
    printf("5.Erase(Delete account)\n");
    printf("6.See/Display\n");
    printf("7.Compute Interest\n");
    printf("8.End the Program\n");
    printf("Choose the number of Menu: ");//반복문
    scanf("%d", &choice);
    printf("\n----------------------------------------------------------------------\n");

    switch (choice) {
    case 1:New_Account();
        break;
    case 2:View();
        break;
    case 3:Edit();
        break;
    case 4:Transact();
        break;
    case 5:Erase();
        break;
    case 6:See();
        break;
    case 7:Interest();
        break;
    case 8:{printf("Thank you for using our bank system.\n");
        main();
        break;
    }
    }
    
}

void New_Account() {
    while (1) {
        FILE* client;
        client = fopen("D:\\Account\\information.txt", "a");
        
            printf("Number of saved customers: %d\n", number_clients);
            printf("Enter customer's information\n");
            printf("Name: ");
            scanf("%s", &a[number_clients].name);
            printf("Date of birth: ");
            scanf("%d", &a[number_clients].date);
            printf("Citizenship number: ");
            scanf("%d", &a[number_clients].citizen);
            printf("Address: ");
            scanf("%s", &a[number_clients].address);
            printf("Phone number: ");
            scanf("%s", &a[number_clients].phone);
            printf("Choose one type of deposit account\n");
            printf("1.saving\n");
            printf("2.current\n");
            printf("3.fixed for 1 year\n");
            printf("4.fixed for 2 years\n");
            printf("5.fixed for 3 years\n");
            printf("Deposit type: ");
            scanf("%d", &a[number_clients].deposit);
            printf("Enter the amount of deposit: ");
            scanf("%d", &a[number_clients].amount);
            printf("Enter the account number: ");
            scanf("%d", &a[number_clients].acc_num);
            fprintf(client, "%s %d %d %s %s %d %d %d\n", a[number_clients].name, a[number_clients].date, a[number_clients].citizen, a[number_clients].address, a[number_clients].phone, a[number_clients].deposit, a[number_clients].amount, a[number_clients].acc_num);
        
        int ans;
        number_clients++;
        printf("Do you want to make more accounts?(1.Yes or 2.No)\n");
        scanf("%d", &ans);
        if (ans == 2) {
            fclose(client);
            printf("Account created successfully\n");
            Menu();
        }

    }
}
void View() {
    int i;
    char find_name[20];
        printf("Enter customer's name that you want to view: ");
        scanf("%s", find_name);
        for (i = 0; i < number_clients; i++) {
            if (strcmp(a[i].name, find_name) == 0) {
                printf("Name: %s\n", a[i].name);
                printf("Account number: %d\n", a[i].acc_num);
                printf("Address: %s\n", a[i].address);
                printf("Phone number: %s\n", a[i].phone);
                Menu();
            }
        }

        if (i == 0) {
            printf("No records!");
        }
    
 
}


void Edit() {
    int k;
    char find_name[20];
    Upd a2;
      FILE* update;
    update = fopen("D:\\Account\\information.txt", "wt");
    if (NULL != update) {
        printf("\nEnter the name of the customer whose information you want to change: ");
        scanf("%s", &find_name);
        for (k = 0; k < number_clients; k++) {
            if (strcmp(a[k].name, find_name) == 0) {
                printf("Update customer's information\n");
                printf("Enter the new address: ");
                scanf("%s", a2.address);
                printf("Enter the new phone number: ");
                scanf("%s", a2.phone);
                fprintf(update, "%s %d %d %s %s %d %d %d\n", a[k].name, a[k].date, a[k].citizen, a2.address, a2.phone, a[k].deposit, a[k].amount, a[k].acc_num);
                fclose(update);
              
            }
            else printf("Account %s has no information", find_name);
        }

    }
    Menu();
}

void Transact() {
    Trans a3;
    char find_name[20];
    int choice, i;
    float plus_money;
    float minus_money;
    FILE* money = fopen("D:\\Account\\information.txt", "wt");
    if (money != NULL) {
        printf("Enter customer's name that you want to view: ");
        scanf("%s", find_name);
        for (i = 0; i < number_clients; i++) {
            if (strcmp(a[i].name, find_name) == 0) {
                fscanf(money, "%s Date of birth:%d, Citizen number:%d, Address:%s, Phone number:%s, Type of deposit:%d, Amount:%d,Account number:%d\n", a[i].name, a[i].date, a[i].citizen, a[i].address, a[i].phone, a[i].deposit, a[i].amount, a[i].acc_num);
                printf("Would you like to deposit or withdraw client's money?(1.Deposit, 2.Withdraw\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("Enter the amount of money to deposit: ");
                    scanf("%f", &plus_money);
                    a3.amount = a[i].amount + plus_money;
                }
                else {
                    printf("Enter the amount of money to withdraw: ");
                    scanf("%f", &minus_money);
                    a3.amount = a[i].amount - minus_money;
                }
                
                fprintf(money, "%s %d %d %s %s %d %d %d\n", a[i].name, a[i].date, a[i].citizen, a[i].address, a[i].phone, a[i].deposit, a3.amount, a[i].acc_num);
            
            }
            else printf("No Information!");
        }

    }
    else {
        printf("File openning error!");
    }
    
    fclose(money);
    Menu();

}

int main() {
    int* pass = (int*)malloc(sizeof(int));
    int i = 12211545;

    printf("Welcome to INHA BANK\n");

    if (*pass != NULL) {
        while (1) {
            printf("Enter your password : ");
            scanf("%d",pass);

            if (*pass == i) {
                Menu();
                free(pass); // pass 변수를 아래에서 사용함에도 동적해제를 해버리면 안됩니다.
                break;
            }
            else
                printf("Wrong password\n");
        }
    }
    else {
        printf("Memory allocation error!");
    }
    return 0;
}

void Erase() {
    char find_name[20];
    int i;
    FILE*cancel=fopen("D:\\Account\\information.txt", "wt");
    if (NULL != cancel) {
        printf("Enter costomer's name to delete Account: ");
        scanf("%s", find_name);
        for (i = 0; i < number_clients; i++) {
            if (strcmp(a[i].name, find_name) == 0) {
                fprintf(cancel,"0",a[i]);
            }
            else {
                printf("No records!");
            }
        }
        fclose(cancel);
        printf("Account deleted successfully\n");
    }
    Menu();
}

void See() {
    char find_name[20];
    int i;
    float interest;
   
        printf("Enter costomer's name to see Account Information: ");
        scanf("%s", find_name);
        for (i = 0; i < number_clients; i++) {
            if (strcmp(a[i].name, find_name) == 0) {
                switch (a[i].deposit) {
                case 1: {
                    interest = 0; break;
                }
                case 2: {
                    interest = 0; break;
                }
                case 3: {
                    interest = 0.09 * a[i].amount; break;
                }
                case 4: {
                    interest = 0.09 * 2 * a[i].amount; break;
                }
                case 5: {
                    interest = 0.09 * 3 * a[i].amount; break;
                }
                }
                printf("Name: %s\n", a[i].name);
                printf("Date of birth: %d\n", a[i].date);
                printf("Citizenship number: %d\n", a[i].citizen);
                printf("Address: %s\n", a[i].address);
                printf("Phone number: %s\n", a[i].phone);
                printf("Type of account: ");
                switch (a[i].deposit) {
                case 1: printf("saving\n"); break;
                case 2: printf("current\n"); break;
                case 3: printf("fixed for 1 year\n"); break;
                case 4: printf("fixed for 2 years\n"); break;
                case 5: printf("fixed for 3 years\n"); break;
                }
                printf("Amount of interest: %f\n", interest);

            }
        }
    

Menu();
}

void Interest() {
    char find_name[20];
    int i;
    float interest;
        printf("Enter costomer's name to see interest amount: ");
        scanf("%s", find_name);
        for (i = 0; i < number_clients; i++) {
            if (strcmp(a[i].name, find_name) == 0) {
                switch (a[i].deposit) {
                case 1: {
                    interest = 0; break;
                }
                case 2: {
                    interest = 0; break;
                }
                case 3: {
                    interest = 0.09 * a[i].amount; break;
                }
                case 4: {
                    interest = 0.09 * 2 * a[i].amount; break;
                }
                case 5: {
                    interest = 0.09 * 3 * a[i].amount; break;
                }
                }
                printf("Interest rate: 9 percent\n");
                printf("Amount of interest: %f\n", interest);

            }

        }
    
    Menu();
}