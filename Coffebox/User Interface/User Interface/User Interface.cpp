#include <iostream>

using namespace std;

void welcome();
void printMenu();
double getBYN();
double buyLatte(double byn);
double buyEspresso(double byn);
double buyKapuchino(double byn);
int serviceMenu(int pin);

const double PRICE_OF_LATTE = 2.0;
const double PRICE_OF_ESPRESSO = 1.5;
const double PRICE_OF_KAPUCHINO = 3.3;
const int PIN = 9472;

int main()
{
    int userChoice = 0;
    int pin = 0;
    double byn = 0.0;
    double temp = 0.0;


    welcome();
    cout << endl;

    while (true)
    {
        cout << endl;
        printMenu();
        cout << endl << "Please choose option: ";
        cin >> userChoice;

        if (userChoice == 1) 
        {
            byn += getBYN();
            cout << "You have inserted " << byn << " BYN" << endl;
        }
        else if (userChoice == 2) 
        {
            byn = buyLatte(byn);
        }
        else if (userChoice == 3)
        {
            byn = buyEspresso(byn);
        }
        else if (userChoice == 4)
        {
            byn = buyKapuchino(byn);
        }
        else if (userChoice == 5) 
        {
            break;
        }
        else if (userChoice == 0) 
        {
            serviceMenu(pin);
        }
        else
        {
            cout << endl << "ERROR: No such option. " << endl;
            cout << "Please input only from 1 to 5. " << endl;
        }
    }
    
    return 0;
}

void welcome()
{
    cout << "Welcome to Coffebox. What would you like to get?";
}

void printMenu()
{
    cout << "User Menu" << endl;
    cout << "1. Deposit money" << endl;
    cout << "2. Buy Latte - " << PRICE_OF_LATTE << " BYN" << endl;
    cout << "3. Buy Espresso - " << PRICE_OF_ESPRESSO << " BYN" << endl;
    cout << "4. Buy Kapuchino - " << PRICE_OF_KAPUCHINO << " BYN" << endl;
    cout << "5. EXIT" << endl;
    cout << "0. Service Menu" << endl;
}

double getBYN()
{
    double byn = 0.0;
    
    cout << endl << "Insert coins: ";
    cin >> byn;

    if (byn == 2)
    {
        byn = 2;
    }
    else if (byn == 1)
    {
        byn = 1;
    }
    else if (byn == 0.5)
    {
        byn = 0.5;
    }
    else if (byn == 0.2)
    {
        byn = 0.2;
    }
    else if (byn == 0.1)
    {
        byn = 0.1;
    }
    else
    {
        cout << "You can only insert coins: 2 BYN, 1 BYN, 50 pennies, 20 pennies, 10 pennies" << endl;
        byn = 0;
    }

    return byn;
}

double buyLatte(double byn)
{
    double change = 0.0;

    if (PRICE_OF_LATTE > byn)
    {
        cout << endl << "Please deposit more money!" << endl;
    }
    else
    {   
        change = byn - PRICE_OF_LATTE;
        cout << endl << "Here is your Latte " << endl;
        cout << "You have " << change << " BYN left" << endl;
    }

    return change;
}

double buyEspresso(double byn)
{
    double change = 0.0;

    if (PRICE_OF_ESPRESSO > byn)
    {
        cout << endl << "Please deposit more money!" << endl;
    }
    else
    {
        change = byn - PRICE_OF_ESPRESSO;
        cout << endl << "Here is your Espresso " << endl;
        cout << "You have " << change << " BYN left" << endl;
    }

    return change;
}

double buyKapuchino(double byn)
{
    double change = 0.0;

    if (PRICE_OF_KAPUCHINO > byn)
    {
        cout << endl << "Please deposit more money!" << endl;
    }
    else
    {
        change = byn - PRICE_OF_KAPUCHINO;
        cout << endl << "Here is your KAPUCHINO " << endl;
        cout << "You have " << change << " BYN left" << endl;
    }

    return change;
}

int serviceMenu(int pin)
{
    cout << endl <<"Warning, these menu is only for staff" << endl;
    cout << "Enter service PIN code: ";
    cin >> pin;

    if (pin == PIN)
    {
        cout << "You have entered service menu "; // объединение с другой часть проекта
    }
    else
    {
        cout << "Incorrect PIN code";
    }
    return pin;
}