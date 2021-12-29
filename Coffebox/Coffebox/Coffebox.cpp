#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>

using namespace std;

void printServiceMenu();
void serviceMenuSelectionProcessing(int choose);
void openCoffeeBox();
void setCups();
void getEarnings();
void welcome();
void printMenu();
double getBYN();
void makeCoffee(int choose);
double buyLatte(double byn);
double buyEspresso(double byn);
double buyKapuchino(double byn);
int enterServiceMenu(int pin);

const double PRICE_OF_LATTE = 2.7;
const double PRICE_OF_ESPRESSO = 2.2;
const double PRICE_OF_KAPUCHINO = 2.4;
const string LATTE = "Latte";
const string CAPPUCINO = "Cappuccino";
const string ESPRESSO = "Espresso";
const int MAX_CUPS = 700;
const int PIN = 7815;
bool isOpen = false;
int cups = 0;
double earnings = 0.0;
double balance = 0.0;


int main() {
    int userChoice = 0;
    int pin = 0;
    cups = 3;

    welcome();

    while (true)
    {
        cout << endl;
        if (cups == 0)
        {
        cout << "There are no cups in the Coffee Box. Please come back later.";
        }
        else
        {
            printMenu();
            cout << endl << "Please choose option [0-4]: ";
            cin >> userChoice;

            if (userChoice == 1)
            {
                system("clear");
                balance += getBYN();
            }
            else if (userChoice == 2 or userChoice == 3 or userChoice == 4)
            {
                makeCoffee(userChoice);
            }
            else if (userChoice == 0)
            {
                system("clear");
                enterServiceMenu(pin);
            }
            else
            {
                system("clear");
                cout << "ERROR: No such option. " << endl;
            }
        }
    }

    return 0;
}
void welcome()
{
    cout << "Welcome to Coffee box. What coffee do you prefer to order?" << endl;
}

void printMenu()
{
    cout << "Menu" << endl;
    cout << "-----" << endl << endl;
    cout << "Balance" << "\t\t\t" << balance << " BYN" << endl << endl;
    cout << "1. Deposit money" << endl;
    cout << "2. Buy Latte" << "\t\t" << PRICE_OF_LATTE << " BYN" << endl;
    cout << "3. Buy Espresso" << "\t\t" << PRICE_OF_ESPRESSO << " BYN" << endl;
    cout << "4. Buy Cappuccino" << "\t" << PRICE_OF_KAPUCHINO << " BYN" << endl << endl;
    cout << "0. Service Menu" << endl;
}

double getBYN()
{
    double byn = 0.0;

    cout << "We accept the following denominations: 2 BYN, 1 BYN, 50 kopecks, 20 kopecks, 10 kopecks" << endl;
    cout << "Please insert coins: ";
    cin >> byn;

    if (byn == 2)
    {
        cout << endl << "You have deposited " << byn << " BYN" << endl;
    }
    else if (byn == 1)
    {
        cout << endl << "You have deposited " << byn << " BYN" << endl;
    }
    else if (byn == 0.5)
    {
        cout << endl << "You have deposited " << byn << " BYN" << endl;
    }
    else if (byn == 0.2)
    {
        cout << endl << "You have deposited " << byn << " BYN" << endl;
    }
    else if (byn == 0.1)
    {
        cout << endl << "You have deposited " << byn << " BYN" << endl;
    }
    else
    {
        cout << endl << "ERROR: You have deposited a denomination we do not accept." << endl;
        byn = 0;
    }
    earnings += byn;

    return byn;
}

void makeCoffee(int choose)
{
    string name = "";

    system("clear");
    if (balance < PRICE_OF_ESPRESSO or balance < PRICE_OF_KAPUCHINO or balance < PRICE_OF_LATTE)
    {
        cout << "Please deposit more money!" << endl;
    } else
    {
        if (choose == 2)
        {
            name = LATTE;
            balance -= PRICE_OF_LATTE;

        } else if (choose == 3)
        {
            name = ESPRESSO;
            balance -= PRICE_OF_ESPRESSO;
        } else if (choose == 4)
        {
            name = CAPPUCINO;
            balance -= PRICE_OF_KAPUCHINO;
        } else
        {
            cout << endl << "ERROR: No such option." << endl;
        }
        cups--;
        cout << "Your " << name << " is coming, please wait..." << endl;
        sleep(5);
        cout << "Your " << name << " is ready. " << endl;
        cout << "Please take your cup away." << endl;
        sleep(5);
        system("clear");
    }
}

int enterServiceMenu(int pin)
{
    cout << "Warning, this menu is only for staff" << endl;
    cout << "Enter service PIN code: ";
    cin >> pin;

    if (pin == PIN)
    {
        cout << "SUCCES: You have entered in service menu " << endl;
        printServiceMenu();

    }
    else
    {
        cout << "Incorrect PIN code";
    }
    return pin;
}

void printServiceMenu()
{
    int choose = 0;

    while(true)
    {
        cout << endl << "Service menu" << endl;
        cout << "-------------" << endl << endl;
        cout << "Earnings" << "\t\t" << earnings << " BYN" << endl << endl;
        cout << "1. Open Coffee Box" << endl;
        cout << "2. Set cups" << endl;
        cout << "3. Get earnings" << endl;
        cout << endl << "0. EXIT" << endl;

        cout << endl << "Please choose the option [0 - 3]: ";
        cin >> choose;
        if (choose == 0)
        {
            isOpen = false;
            return;
        }
        serviceMenuSelectionProcessing(choose);
        choose = 0;
    }
}

void serviceMenuSelectionProcessing(int choose)
{
    if (choose == 1)
    {
        system("clear");
        openCoffeeBox();
    }
    else if (choose == 2)
    {
        system("clear");
        setCups();
    }
    else if (choose == 3)
    {
        system("clear");
        getEarnings();
    }
    else
    {
        system("clear");
        cout << endl << "ERROR: No such option." << endl;
    }
}

void openCoffeeBox()
{
    if (isOpen)
    {
        cout << "The Coffee box is already open." << endl;
    } else
    {
        isOpen = true;
        cout << "You have opened the Coffee Box." << endl;
    }

}

void setCups()
{
    int cupsAmount = 0;
    if (!isOpen)
    {
        cout << "Coffee Box is closed. You must open the Coffee Box first!" << endl;
    }
    else
    {
        cout << "Cups in the coffee box " << cups << " pcs." << endl;
        cout << "How many cups do you want to set up?  ";
        cin >> cupsAmount;

        if (cupsAmount < 0 or cups + cupsAmount > MAX_CUPS)
        {
            cout << "ERROR: The number of cups cannot be less or greater than 700" << endl;
        }
        else
        {
            cups += cupsAmount;
            cout << "SUCCESS: You have set up " << cupsAmount << " cups." << endl;
            cout << "Cups in the coffee box " << cups << " pcs." << endl;
        }
    }
}

void getEarnings()
{
    if (!isOpen)
    {
        cout << "ERROR: Coffee Box is closed." << endl;
        cout << "You must open the Coffee Box first!" << endl;
    }
    else
    {
        if (earnings == 0.0)
        {
            cout << "There is no earnings in the Coffee Box.";
        }
        else
        {
            cout << "SUCCESS: You have picked up " << earnings << " BYN" << endl;
            earnings = 0.0;
        }
    }
}
