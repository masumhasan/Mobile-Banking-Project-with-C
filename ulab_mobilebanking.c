#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main_exit;
void menu();
void menu2();
void signin();
void depo();
void withdraw();
void close();
void send();
void sendd();
struct
{
    char name[60];
    int id_no;
    int secu;
    long long phone;

    float taka;

} use, upd, check, rem, myid, transaction;

void new_acc()
{
    int choice;
    FILE *ptr;
    ptr = fopen("database.dat", "a+");
account_no:
    printf("\t\t\t==== ADD RECORD  ====");
    printf("\nEnter the ID number:\n");
    scanf("%d", &check.id_no);
    while (fscanf(ptr, "%d %s %d %lld %f\n", &use.id_no, use.name, &use.secu, &use.phone, &use.taka) != EOF)
    {
        if (check.id_no == use.id_no)
        {
            printf("Account no. already in use!\n");

            goto account_no;
        }
    }
    use.id_no = check.id_no;
    printf("\nEnter the username(NO SPACE):\n:");
    scanf("%s", use.name);
    printf("\nEnter the Security PIN:\n:");
    scanf("%d", &use.secu);
    printf("\nEnter the phone number: Include 880\n:");
    scanf("%lld", &use.phone);
    printf("\nEnter Initial deposit:\n BDT:");
    scanf("%f", &use.taka);

    fprintf(ptr, "%d %s %d %lld %f\n", use.id_no, use.name, use.secu, use.phone, use.taka);

    fclose(ptr);
    printf("\nAccount created successfully!\n");
use_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);
    system("cls");
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
        close();
    else
    {
        printf("\nInvalid!\a");
        goto use_invalid;
    }
}

void depo(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("database.dat", "a+");
    newrec = fopen("new.dat", "a+");

    while (fscanf(old, "%d %s %d %lld %f ", &use.id_no, use.name, &use.secu, &use.phone, &use.taka) != EOF)
    {

        if (use.id_no == myid.id_no)
        {
            test = 1;

            printf("Enter the amount you want to deposit BDT: ");
            scanf("%f", &transaction.taka);
            use.taka += transaction.taka;
            fprintf(newrec, "%d %s %d %lld %f\n", use.id_no, use.name, use.secu, use.phone, use.taka);
            printf("\n\nDeposited successfully!");
        }
        else
        {
            fprintf(newrec, "%d %s %d %lld %f\n", use.id_no, use.name, use.secu, use.phone, use.taka);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("database.dat");
    rename("new.dat", "database.dat");
    if (test != 1)
    {
        printf("\n\nRecord not found!!");
    depo_invalid:
        printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 0)
            depo();
        else if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            close();
        else
        {
            printf("\nInvalid!");
            goto depo_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the home menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu2();
        else
            close();
    }
}

void withdraw(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("database.dat", "a+");
    newrec = fopen("new.dat", "a+");

    while (fscanf(old, "%d %s %d %lld %f ", &use.id_no, use.name, &use.secu, &use.phone, &use.taka) != EOF)
    {

        if (use.id_no == myid.id_no)
        {
            test = 1;

            printf("Enter the amount you want to withdraw BDT: ");
            scanf("%f", &transaction.taka);
            use.taka -= transaction.taka;
            fprintf(newrec, "%d %s %d %lld %f \n", use.id_no, use.name, use.secu, use.phone, use.taka);
            printf("\n\nWithdrawn successfully!");
        }
        else
        {
            fprintf(newrec, "%d %s %d %lld %f \n", use.id_no, use.name, use.secu, use.phone, use.taka);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("database.dat");
    rename("new.dat", "database.dat");
    if (test != 1)
    {
        printf("\n\nRecord not found!!");
    withdraw_invalid:
        printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 0)
            withdraw();
        else if (main_exit == 1)
            menu2();
        else if (main_exit == 2)
            close();
        else
        {
            printf("\nInvalid!");
            goto withdraw_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu2();
        else
            close();
    }
}

void send(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("database.dat", "a+");
    newrec = fopen("new.dat", "a+");

    printf("Enter Receivers ID:");
    scanf("%d", &transaction.id_no);
    while (fscanf(old, "%d %s %d %lld %f ", &use.id_no, use.name, &use.secu, &use.phone, &use.taka) != EOF)
    {

        if (use.id_no == transaction.id_no)
        {
            test = 1;

            printf("Enter the amount you SEND BDT: ");
            scanf("%f", &transaction.taka);
            use.taka += transaction.taka;
            fprintf(newrec, "%d %s %d %lld %f\n", use.id_no, use.name, use.secu, use.phone, use.taka);
            printf("\n\nSend Money successfully!");
        }

        else
        {
            fprintf(newrec, "%d %s %d %lld %f \n", use.id_no, use.name, use.secu, use.phone, use.taka);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("database.dat");
    rename("new.dat", "database.dat");
    if (test != 1)
    {
        printf("\n\nRecord not found!!");
    send_invalid:
        printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 0)
            send();
        else if (main_exit == 1)
            menu2();
        else if (main_exit == 2)
            close();
        else
        {
            printf("\nInvalid!");
            goto send_invalid;
        }
    }
    else
    {
        sendd();
    }
}
void sendd(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("database.dat", "a+");
    newrec = fopen("new.dat", "a+");

    while (fscanf(old, "%d %s %d %lld %f", &use.id_no, use.name, &use.secu, &use.phone, &use.taka) != EOF)
    {

        if (use.id_no == myid.id_no)
        {
            test = 1;

            use.taka -= transaction.taka;
            fprintf(newrec, "%d %s %d %lld %f\n", use.id_no, use.name, use.secu, use.phone, use.taka);
        }

        else
        {
            fprintf(newrec, "%d %s %d %lld %f \n", use.id_no, use.name, use.secu, use.phone, use.taka);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("database.dat");
    rename("new.dat", "database.dat");
    if (test != 1)
    {
        printf("\n\nRecord not found!!");
    sendd_invalid:
        printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 0)
            sendd();
        else if (main_exit == 1)
            menu2();
        else if (main_exit == 2)
            close();
        else
        {
            printf("\nInvalid!");
            goto sendd_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the home menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu2();
        else
            close();
    }
}

void see(void)
{
    FILE *ptr;
    int test = 0, rate;
    int choice;
    float time;
    float intrst;
    ptr = fopen("database.dat", "r");

    while (fscanf(ptr, "%d %s %d %lld %f", &use.id_no, use.name, &use.secu, &use.phone, &use.taka) != EOF)
    {
        if (use.id_no == myid.id_no)
        {
            system("cls");
            test = 1;

            printf("\nID NO.:%d\nName:%s\nPIN:%d \nPhone number:%lld \nAmount deposited: BDT: %.2f \n\n", use.id_no, use.name, use.secu, use.phone, use.taka);
        }
    }

    fclose(ptr);
    if (test != 1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
    see_invalid:
        printf("\nEnter 1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu2();
        else if (main_exit == 2)
            close();

        else
        {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
    }
    if (main_exit == 1)
    {
        system("cls");
        menu2();
    }

    else
    {

        system("cls");
        close();
    }
}

void close(void)
{
    printf("\n\n\n\nProject By");
    printf("\nNur Hasan Masum");
    printf("\nFardeen Amin Pranto");
    printf("\nLamia Tabassum Tuba");
}

void menu(void)
{
    int choice;
    system("cls");
    printf("\n\n\t\t\t       ULAB MOBILE BANKING");
    printf("\n\n\n\t\t\t====== WELCOME TO THE MAIN MENU ======");
    printf("\n\n\t\t[1] Sign Up\n\t\t[2] Login\n\t\t[3] Exit\n\n\n\t\t Enter your choice:");
    scanf("%d", &choice);

    system("cls");
    switch (choice)
    {
    case 1:
        new_acc();
        break;

    case 2:
        signin();
        break;
    case 3:
        close();
        break;
    }
}

void signin(void)
{
    printf("\n\n\t\t\t       ULAB MOBILE BANKING");
    printf("\n\n\n\t\t\t===== WELCOME TO THE MAIN MENU =====");
signin_again:
    printf("\n\n\t\t\t       Enter Your ID");
    scanf("%d", &myid.id_no);

    int choice, test = 0;
    FILE *ptr;
    ptr = fopen("database.dat", "a+");

    while (fscanf(ptr, "%d %s %d %lld %f ", &use.id_no, use.name, &use.secu, &use.phone, &use.taka) != EOF)
    {

        if (use.id_no == myid.id_no)
        {
            test = 1;

            printf("Enter PIN: ");
            scanf("%d", &myid.secu);
            if (use.secu == myid.secu)
            {
                fclose(ptr);
                menu2();
            }

            else
                printf("\n\nWrong Pin!!");
            goto signin_again;
        }
    }
    fclose(ptr);
}

void menu2(void)
{
    int choice;
    system("cls");
    printf("\n\n\t\t\t      ==ULAB MOBILE BANKING==");
    printf("\n\n\n\t\t\t====== WELCOME TO THE HOME MENU ======");

    printf("\n\n\t\t[1] Deposite\n\t\t[2] Withdraw\n\t\t[3] Check details\n\t\t[4] Send Money\n\t\t[5] Sign Out\n\n\n\t\t Enter your choice:");
    scanf("%d", &choice);

    system("cls");
    switch (choice)
    {

    case 1:
        depo();
        break;
    case 2:
        withdraw();
        break;

    case 3:
        see();
        break;

    case 4:
        send();
        break;

    case 5:
        menu();
        break;
    }
}
int main()
{
    system("cls");
    menu();
    return 0;
}
