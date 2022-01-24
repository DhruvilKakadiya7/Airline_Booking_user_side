#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int permenent = 0;
void menu(void);
struct
{
    char name[60], password[20];
    int age, acc_no;
    char address[60];
    double aadharcard_no;
    double phone;
    float amt;
    int seat1, seat2;

} add, check, transect;
void signup(void);
void close()
{
    system("cls");
    printf("\n\n\t\t\t\tThanks For visit our System :) ");
    printf("\nOwner : \n\n\t 1.Dhruvil Kakadiya \n\t 2.Harsh Dobariya \n\t 3.Kirtan Bhad");
}

void loading()
{
    for (int j = 0; j < 100000000; j++)
        ;
}
void login_for_continue()
{
    FILE *ptr;
retry:
    ptr = fopen("scan.dat", "r");

    system("cls");
    printf("\n\n\n\t\t\t\tWELCOME TO OUR SYSTEM\n\n PLEASE LOGIN TO CONTINUE : ");
    printf("\n\n\tEnter Your Account Number : ");
    getchar();
    scanf("%d", &check.acc_no);
    getchar();
    int temp = 0;
    while (fscanf(ptr, "%d %s %d %s %lf %lf %f %s\n", &add.acc_no, add.name, &add.age, add.address, &add.aadharcard_no, &add.phone, &add.amt, &add.password) != EOF)
    {
        if (add.acc_no == check.acc_no)
        {
            permenent = add.acc_no;
            temp = 1;
            printf("\n\n\tEnter Password : ");
            gets(check.password);

            if (strcmpi(check.password, add.password) == 0)
            {
                temp = 1;
                printf("\n\n\tLOGIN SUCCESSFULLY!!!");
                permenent = add.acc_no;
                printf("\n\tLOADING ");
                for (int i = 0; i < 6; i++)
                {
                    loading();
                    printf(". ");
                }
                fclose(ptr);
                menu();
            }
            else
            {
                printf("\n\n\tWRONG PASSWORD!!!");
                int a;
            retry4:
                printf("\n\n\tPlease enter Your choice . : ");
                printf("\n\t1.Retry");
                printf("\n\t2.Signup");
                printf("\n\t3.Exit");
                printf("\n\tENter your Choice : ");
                scanf("%d", &a);
                if (a == 1)
                    goto retry;
                else if (a == 0)
                {
                    fclose(ptr);
                    close();
                }
                else
                {
                    printf("\n\n\tWrong Choice....");
                    goto retry4;
                }
            }
        }
    }
    fclose(ptr);
    if (temp == 0)
    {
        printf("\n\n\tNo Data Found !!!");
        int a;
    retry3:
        printf("\n\n\tEnter 1 to Signup or 0 to retry : ");
        scanf("%d", &a);
        if (a == 1)
            signup();
        else if (a == 0)
            goto retry;
        else
        {
            printf("\n\n\tWrong Choice....");
            goto retry3;
        }
    }
}

void signup()
{
    FILE *ptr;

    ptr = fopen("scan.dat", "a+");
account_no:
    system("cls");
    printf("\t\t\t\t\t ADD scan ");
    printf("\nEnter the account number: ");
    scanf("%d", &check.acc_no);
    while (fscanf(ptr, "%d %s %d %s %lf %lf %f %s\n", &add.acc_no, add.name, &add.age, add.address, &add.aadharcard_no, &add.phone, &add.amt, &add.password) != EOF)
    {
        if (check.acc_no == add.acc_no)
        {
            printf("Account no. already in use!");
            loading();
            goto account_no;
        }
    }
    add.acc_no = check.acc_no;
    printf("\nEnter the name: ");
    scanf("%s", &add.name);
    printf("\nEnter the age: ");
    scanf("%d", &add.age);
    printf("\nEnter the address: ");
    scanf("%s", &add.address);
    printf("\nEnter the Aadharcard number: ");
    scanf("%lf", &add.aadharcard_no);
    printf("\nEnter the phone number: ");
    scanf("%lf", &add.phone);
    printf("\nEnter the amount to deposit: Rs.");
    scanf("%f", &add.amt);
    printf("\nCreate a Password : ");
    scanf("%s", &check.password);
    strcpy(add.password, check.password);
    fprintf(ptr, "%d %s %d %s %lf %lf %f %s\n", add.acc_no, add.name, add.age, add.address, add.aadharcard_no, add.phone, add.amt, add.password);

    fclose(ptr);
    printf("\nAccount created successfully!");
    login_for_continue();
}

void login()
{
retry:
    system("cls");
    int temp = 0;
    printf("\n\n\tPlease Enter 1 to continue or 0 to exit : ");
    scanf("%d", &temp);
    if (temp == 1)
    {

        system("cls");
        printf("\n\n\t1.Login\n\t2.Singup");
        printf("\n\n\n\tEnter your Choice(1 or 2) : ");
        int a;
        scanf("%d", &a);
        if (a == 1)
        {
            login_for_continue();
        }
        else if (a == 2)
        {
            signup();
        }
        else
        {
            printf("\nWrong Choice.....");
            goto retry;
        }
    }
    else if (temp == 0)
        close();
    else
    {
        printf("\nWrong Choice.....");
        goto retry;
    }
}

void mumbai()
{
    FILE *st, *mum;
seat1:
    st = fopen("mumbai.dat", "a+");
    mum = fopen("seat1.dat", "a+");
    int temp1 = 0, seatf = 0, seat1 = 0;
    printf("\n\n\tEnter Your Seat Choice (from 1 to 30) : ");
    scanf("%d", &check.seat1);
    if(check.seat1>30 || check.seat1<1)
    {
        printf("\n\n\tOnly Enter seat between 1 to 30 !!!");
        getch();
        goto seat1;
    }
    while (fscanf(mum, "%d\n", &seat1) != EOF)
    {
        if (seat1 == check.seat1)
        {
            seatf = 1;
            printf("\n\n\tSorry :( , Seat is Full. Please Choose Another one.");
            goto seat1;
        }
    }
    if (seatf == 0)
    {

        fprintf(mum, "%d\n", check.seat1);

        fprintf(st, "%d %s %d %s %lf %lf %f %s %d\n", permenent, add.name, add.age, add.address, add.aadharcard_no, add.phone, add.amt, add.password, check.seat1);
    }
    fclose(st);
    fclose(mum);
}

void delhi()
{
    FILE *st, *del;
seat2:
    st = fopen("delhi.dat", "a+");
    del = fopen("seat2.dat", "a+");
    int temp1 = 0, seatf = 0, seat1 = 0;
    printf("\n\n\tEnter Your Seat Choice (from 1 to 30) : ");
    scanf("%d", &check.seat1);
    if(check.seat1>30 || check.seat1<1)
    {
        printf("\n\n\tOnly Enter seat between 1 to 30 !!!");
        getch();
        goto seat2;
    }
    while (fscanf(del, "%d\n", &seat1) != EOF)
    {
        if (seat1 == check.seat1)
        {
            seatf = 1;
            printf("\n\n\tSorry :( , Seat is Full. Please Choose Another one.");
            goto seat2;
        }
    }
    if (seatf == 0)
    {

        fprintf(del, "%d\n", check.seat1);

        fprintf(st, "%d %s %d %s %lf %lf %f %s %d\n", permenent, add.name, add.age, add.address, add.aadharcard_no, add.phone, add.amt, add.password, check.seat1);
    }
    fclose(st);
    fclose(del);
}

void Book()
{
    int temp = 0, choice;
    FILE *edit, *old;
open:
    old = fopen("scan.dat", "r");
    edit = fopen("edit.dat", "w");
    system("cls");
    printf("\n\n\t\t\t Here is a List of Flights :::");
    printf("\n\n\t1. Ahemdabad -> Mumbai        Price :- Rs.3500  ");
    printf("\n\n\t2. Ahemdabad -> Delhi         Price :- Rs.6000  ");
    
    while (fscanf(old, "%d %s %d %s %lf %lf %f %s\n", &add.acc_no, add.name, &add.age, add.address, &add.aadharcard_no, &add.phone, &add.amt, &add.password) != EOF)
    {
        if (add.acc_no == permenent)
        {
            printf("\n\n\tYou have Rs.%.2f", add.amt);
            getch();
            if (add.amt < 6000)
            {
                printf("\n\n\tYou don't have sufficient Balance !!!");
                printf("\n\nEnter 1 to Deposite money or 0 to Main menu : ");
                scanf("%d", &choice);
                if (choice == 1)
                {
                    printf("\n\n\tEnter Amount you want to deposite : ");
                    scanf("%f", &transect.amt);
                    add.amt = add.amt + transect.amt;
                    printf("\n\n\tNow you have Rs.%.2f", add.amt);
                    fprintf(edit, "%d %s %d %s %lf %lf %f %s\n", add.acc_no, add.name, add.age, add.address, add.aadharcard_no, add.phone, add.amt, add.password);
                    printf("\n\n\tAmount deposited Successfulluy :)");
                }
                if (choice == 0)
                {
                    fclose(old);
                    fclose(edit);
                    menu();
                }
            }
            else
            {
                printf("\n\n\tEnter Your FLight No. (either 1 or 2) : ");
                scanf("%d", &temp);
                if (temp == 1)
                {
                    add.amt -= 3500;
                    fprintf(edit, "%d %s %d %s %lf %lf %f %s\n", add.acc_no, add.name, add.age, add.address, add.aadharcard_no, add.phone, add.amt, add.password);

                    mumbai();
                    printf("\n\n\tFlight booked Successfully !!!");
                }
                else if (temp == 2)
                {
                    add.amt -= 6000;
                    fprintf(edit, "%d %s %d %s %lf %lf %f %s\n", add.acc_no, add.name, add.age, add.address, add.aadharcard_no, add.phone, add.amt, add.password);

                    delhi();
                    printf("\n\n\tFlight booked Successfully !!!");
                }
            }
        }
        else
            fprintf(edit, "%d %s %d %s %lf %lf %f %s\n", add.acc_no, add.name, add.age, add.address, add.aadharcard_no, add.phone, add.amt, add.password);
    }
    fclose(old);
    fclose(edit);
    remove("scan.dat");
    rename("edit.dat", "scan.dat");
    getch();
    menu();
}

void List()
{
retry8:
    system("cls");
    printf("\n\n\t\t\t Here is a List of Flights :::");
    printf("\n\n\t1. Ahemdabad -> Mumbai ");
    printf("\n\n\t2. Ahemdabad -> Delhi ");
    int a;
    printf("\n\nPlease Select your choicie : \n\n\t1.Go to Main Menu \n\t2.Go to Ticket Booking \n\t3.Exit");

    printf("\n\n\n\tPlease Enter Your Choice between 1 to 3 : ");
    scanf("%d", &a);
    if (a == 1)
        menu();
    else if (a == 2)
        Book();
    else if (a == 3)
        close();
    else
        goto retry8;
}

void status()
{
    FILE *ptr1, *ptr2;
    ptr1 = fopen("mumbai.dat", "r");
    ptr2 = fopen("delhi.dat", "r");
    system("cls");
    while (fscanf(ptr1, "%d %s %d %s %lf %lf %f %s %d\n", &add.acc_no, add.name, &add.age, add.address, &add.aadharcard_no, &add.phone, &add.amt, &add.password, &add.seat1) != EOF)
    {
        if (add.acc_no == permenent)
        {
            printf("\n\n\tAccount No. = %d", add.acc_no);
            printf("\n\tName : %s", add.name);
            printf("\n\tAge : %d", add.age);
            printf("\n\tMObile No. : %lf", add.phone);
            printf("\n\tAadhar Card no. : %lf", add.aadharcard_no);
            printf("\n\tDestination : Mumbai");
            printf("\n\tSeat no. : %d", add.seat1);
        }
    }
    while (fscanf(ptr2, "%d %s %d %s %lf %lf %f %s %d\n", &add.acc_no, add.name, &add.age, add.address, &add.aadharcard_no, &add.phone, &add.amt, &add.password, &add.seat2) != EOF)
    {
        if (add.acc_no == permenent)
        {
            printf("\n\n\tAccount No. = %d", add.acc_no);
            printf("\n\tName : %s", add.name);
            printf("\n\tAge : %d", add.age);
            printf("\n\t MObile No. : %lf", add.phone);
            printf("\n\tAadhar Card no. : %lf", add.aadharcard_no);
            printf("\n\t Destination : Delhi");
            printf("\n\tSeat no. : %d", add.seat2);
        }
    }
    fclose(ptr1);
    fclose(ptr2);
    printf("\n\n\tENter any key to continue...");
    getch();
    menu();
}

void menu()
{
    system("cls");
    system("color 9");
    printf("\n\n\t\t\t: Welcome to the Airline Booking System : ");
    printf("\n\n\tPlease Select your Choice : \n\n\t1.List of FLight\n\t2.Ticket Booking \n\t3.Your Booking status \n\t4.Exit ");
default_1:
    printf("\n\n\n\tEnter Your Choice between 1 to 4 : ");
    int a;
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        List();
        break;
    case 2:
        Book();
        break;
    case 3:
        status();
        break;
    case 4:
        close();
        break;
    default:
        goto default_1;
        break;
    }
}
int main()
{
    system("color C"); 
    system("cls");     
    add.seat1 = 0, add.seat2 = 0;
    printf("\n\n\t\t\t\t\t: WELCOME TO THE AIRLINE BOOKING SYSTEM : ");
    printf("\n\n\n\t Press any Key to coninue ");
    getchar();
    login();
    getch();
    return 0;
}
