#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>

using namespace std;

void printMenu();
void printServiceMenu();
void printNoCupsMenu();
void serviceMenuSelectionProcessing(int choose);
void userMenuSelectionProcessing(int choose);
void getEarnings();
double getBYN();
void makeCoffee(int choose);
void enterServiceMenu();
void openCoffeeBox();
void setCups();

const double PRICE_OF_LATTE = 2.7;
const double PRICE_OF_ESPRESSO = 2.2;
const double PRICE_OF_KAPUCHINO = 2.4;
const string LATTE = "Latte";
const string CAPPUCINO = "Cappuccino";
const string ESPRESSO = "Espresso";
const string COFFE_BOX_NAME = "LEI700";
const int MAX_CUPS = 700;
const int PIN = 7815;
bool isOpen = false;
bool serviceMenuBlocked = false;
int cups = 0;
double earnings = 0.0;
double balance = 0.0;


int main() {
    int userChoice = 0;
    int pin = 0;
    cups = 3;

    while (true)
    {
        if (cups == 0)
        {
            printNoCupsMenu();
        }
        else
        {
            printMenu();
        }
        cout << endl << "Please choose option: ";
        cin >> userChoice;

        userMenuSelectionProcessing(userChoice);
        system("clear");
    }

    return 0;
}

void userMenuSelectionProcessing(int choose)
{
    system("clear");
    if (cups == 0)
    {
        if (choose == 0)
        {
            enterServiceMenu();
        }
    }
    else
    {
        if (choose == 1)
        {
            balance += getBYN();
        }
        else if (choose == 2 or choose == 3 or choose == 4)
        {
            makeCoffee(choose);
        }
        else if (choose == 0)
        {
            enterServiceMenu();
        }
        else
        {
            cout << "ERROR: No such option. " << endl;
            sleep(2);
        }
    }
}

void printNoCupsMenu()
{
    cout << "There is no cups. Please come back later." << endl << endl;
    cout << "0. Service Menu" << endl;
}

void printMenu()
{
    system("clear");
    cout << "Menu" << endl;
    cout << "-----" << endl << endl;
    if (cups <= 3)
    {
        cout << "WARNING: Cups left" << setw(5) << cups << " pcs." << endl<< endl;
    }
    cout << "Balance" << setw(16) << balance << " BYN" << endl << endl;
    cout << "1. Deposit money" << endl;
    cout << "2. Buy Latte" << setw(11) << PRICE_OF_LATTE << " BYN" << endl;
    cout << "3. Buy Espresso" << setw(8) << PRICE_OF_ESPRESSO << " BYN" << endl;
    cout << "4. Buy Cappuccino" << setw(6) << PRICE_OF_KAPUCHINO << " BYN" << endl << endl;
    cout << "0. Service Menu" << endl;
}

double getBYN()
{
    double byn = 0.0;

    system("clear");
    cout << "We accept the following denominations: 2 BYN, 1 BYN, 50 kopecks, 20 kopecks, 10 kopecks" << endl;
    cout << "Please insert coins: ";
    cin >> byn;

    system("clear");
    if (byn == 2.0 or byn == 1.0 or byn == 0.5 or byn == 0.2 or byn == 0.1)
    {
        cout << endl << "You have deposited " << byn << " BYN" << endl;
    }
    else
    {
        cout << endl << "ERROR: You have deposited a denomination we do not accept." << endl;
        byn = 0;
    }

    earnings += byn;
    sleep(2);

    return byn;
}

void makeCoffee(int choose)
{
    string name = "";

    system("clear");
    if (balance < PRICE_OF_ESPRESSO or balance < PRICE_OF_KAPUCHINO or balance < PRICE_OF_LATTE)
    {
        cout << "Please deposit more money!" << endl;
        sleep(2);
    }
    else
    {
        if (choose == 2)
        {
            name = LATTE;
            balance -= PRICE_OF_LATTE;

        }
        else if (choose == 3)
        {
            name = ESPRESSO;
            balance -= PRICE_OF_ESPRESSO;
        }
        else if (choose == 4)
        {
            name = CAPPUCINO;
            balance -= PRICE_OF_KAPUCHINO;
        }
        else
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

void enterServiceMenu()
{
    int pin = 0;
    int counter = 0;
    const int MAX_ATTEMPTS = 3;

    if (serviceMenuBlocked)
    {
        cout << "ERROR: Service menu was blocked." << endl;
        cout << "Contact Support." << endl;
        sleep(3);
        return;
    }

    while(pin != PIN)
    {
        system("clear");
        cout << "Warning, this menu is only for staff" << endl;
        cout << "Enter service PIN code: ";
        cin >> pin;

        if (pin == PIN)
        {
            break;
        }
        system("clear");
        cout << "ERROR: Wrong PIN-code!" << endl;
        counter++;
        cout << MAX_ATTEMPTS - counter << " attempts left" << endl;
        sleep(2);
        if (counter == MAX_ATTEMPTS)
        {
            system("clear");
            cout << "ERROR:You exceeded number of entry attempts." << endl;
            cout << "The Service menu was blocked!" << endl;
            serviceMenuBlocked = true;
            sleep(2);
            return;
        }
    }
    system("clear");
    cout << "SUCCES: You have entered in service menu " << endl;
    sleep(2);
    printServiceMenu();
}

void printServiceMenu()
{
    int choose = 0;

    while(true)
    {
        system("clear");
        cout << endl << COFFE_BOX_NAME << " Service menu" << endl;
        cout << "--------------------" << endl << endl;
        cout << "Cups" << setw(14) << cups << " pcs." << endl;
        cout << "Earnings" << setw(10) << earnings << " BYN" << endl << endl;
        cout << "1. Open Coffee Box" << endl;
        cout << "2. Set cups" << endl;
        cout << "3. Get earnings" << endl;
        cout << endl << "0. EXIT" << endl;

        cout << endl << "Please choose the option [0 - 3]: ";
        cin >> choose;

        if (choose == 0)
        {
            isOpen = false;
            system("clear");
            cout << "Exit from service menu" << endl;
            sleep(2);
            return;
        }
        serviceMenuSelectionProcessing(choose);
    }
}

void serviceMenuSelectionProcessing(int choose)
{
    if (choose == 1)
    {
        openCoffeeBox();
    }
    else if (choose == 2)
    {
        setCups();
    }
    else if (choose == 3)
    {
        system("clear");
        getEarnings();
    }
    else
    {
        cout << endl << "ERROR: No such option." << endl;
        sleep(2);
        system("clear");
    }
}

void openCoffeeBox()
{
    system("clear");
    if (isOpen)
    {
        cout << "The " << COFFE_BOX_NAME << " is already open." << endl;
    } else
    {
        isOpen = true;
        cout << "The " << COFFE_BOX_NAME << " opening" << endl;
    }
    sleep(2);
}

void setCups()
{
    int cupsAmount = 0;

    system("clear");
    if (!isOpen)
    {
        cout << "Coffee Box is closed. You must open the Coffee Box first!" << endl;
    }
    else
    {
        cout << "Cups in the " << COFFE_BOX_NAME << " " << cups << " pcs." << endl;
        cout << "You can set up " << MAX_CUPS - cups << " pcs." << endl;
        cout << "How many cups do you want to set up? ";
        cin >> cupsAmount;

        system("clear");
        if (cupsAmount < 0 or cups + cupsAmount > MAX_CUPS)
        {
            cout << "ERROR: The number of cups in  cannot be greater than " << MAX_CUPS << endl;
        }
        else
        {
            cups += cupsAmount;
            cout << endl << "SUCCESS: You have set up " << cupsAmount << " cups." << endl;
            cout << "Cups in the " << COFFE_BOX_NAME << " " << cups << " pcs." << endl;
        }
    }
    sleep(2);
}

void getEarnings()
{
    system("clear");
    if (!isOpen)
    {
        cout << "ERROR: Coffee Box is closed." << endl;
        cout << "You must open the Coffee Box first!" << endl;
    }
    else
    {
        if (earnings == 0.0)
        {
            cout << "There is no earnings in the Coffee Box." << endl;
        }
        else
        {
            cout << "SUCCESS: You have picked up " << earnings << " BYN" << endl;
            earnings = 0.0;
        }
    }
    sleep(2);
}
