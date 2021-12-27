#include <iostream>

using namespace std;

void printServiceMenu();
void serviceMenuSelectionProcessing(int choose);
void openCoffeeBox();
void setCups();
void getEarnings();
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
const int MAX_CUPS = 700;
const int PIN = 9472;
bool isOpen = false;
int cups = 0;
double earnings = 0.0;
double balance = 0.0;


int main() {
    int userChoice = 0;
    int pin = 0;
    cups = 3;



    welcome();
    cout << endl;

    while (true)
    {
        cout << endl;
        if (cups == 0) {
        cout << "There are no cups in the Coffee Box. Please come back later.";
        return 1;
        } else {
            printMenu();
            cout << endl << "Please choose option [0-5]: ";
            cin >> userChoice;

            if (userChoice == 1)
            {
                balance += getBYN();
            }
            else if (userChoice == 2)
            {
                balance = buyLatte(balance);
            }
            else if (userChoice == 3)
            {
                balance = buyEspresso(balance);
            }
            else if (userChoice == 4)
            {
                balance = buyKapuchino(balance);
            }
            else if (userChoice == 5)
            {
                serviceMenu(pin);
            }
            else if (userChoice == 0)
            {
                break;
            }
            else
            {
                cout << endl << "ERROR: No such option. " << endl;
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
    cout << "5. Service Menu" << endl;
    cout << "0. EXIT" << endl;
}

double getBYN()
{
    double byn = 0.0;

    cout << endl << "We accept the following denominations: 2 BYN, 1 BYN, 50 kopecks, 20 kopecks, 10 kopecks" << endl;
    cout << "Please insert coins: ";
    cin >> byn;

    if (byn == 2)
    {
        byn = 2;
        cout << endl << "You have deposited " << byn << " BYN" << endl;
    }
    else if (byn == 1)
    {
        byn = 1;
        cout << endl << "You have deposited " << byn << " BYN" << endl;
    }
    else if (byn == 0.5)
    {
        byn = 0.5;
        cout << endl << "You have deposited " << byn << " BYN" << endl;
    }
    else if (byn == 0.2)
    {
        byn = 0.2;
        cout << endl << "You have deposited " << byn << " BYN" << endl;
    }
    else if (byn == 0.1)
    {
        byn = 0.1;
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
        cups--;
        cout << endl << "Your Latte is coming, please wait..." << endl;
        cout << "Your Latte is ready. " << endl;
        cout << "Please take your cup away." << endl;
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
        cups--;
        cout << endl << "Your Espresso is coming, please wait..." << endl;
        cout << "Your Espresso is ready. " << endl;
        cout << "Please take your cup away." << endl;
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
        cups--;
        cout << endl << "Your Cappuccino is coming, please wait..." << endl;
        cout << "Your Cappuccino is ready. " << endl;
        cout << "Please take your cup away." << endl;
    }

    return change;
}

int serviceMenu(int pin)
{
    cout << endl <<"Warning, this menu is only for staff" << endl;
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




void printServiceMenu() {
    int choose = 0;

    while(true) {
        cout << endl << "Service menu" << endl;
        cout << "-------------" << endl << endl;
        cout << "Earnings" << "\t\t" << earnings << " BYN" << endl << endl;
        cout << "1. Open Coffee Box" << endl;
        cout << "2. Set cups" << endl;
        cout << "3. Get earnings" << endl;
        cout << endl << "0. EXIT" << endl;

        cout << endl << "Please choose the option [0 - 3]: ";
        cin >> choose;
        if (choose == 0) {
            isOpen = false;
            return;
        }
        serviceMenuSelectionProcessing(choose);
        choose = 0;
    }
}

void serviceMenuSelectionProcessing(int choose) {
    if (choose == 1) {
        openCoffeeBox();
    } else if (choose == 2) {
        setCups();
    } else if (choose == 3) {
        getEarnings();
    } else {
        cout << endl << "ERROR: No such option." << endl;
    }
}

void openCoffeeBox() {
    if (isOpen) {
        cout << endl << "The Coffee box is already open." << endl;
    } else {
        isOpen = true;
        cout << endl << "You have opened the Coffee Box." << endl;
    }

}
void setCups() {
    int cupsAmount = 0;
    if (!isOpen) {
        cout << endl << "Coffee Box is closed. You must open the Coffee Box first!" << endl;
    } else {
        cout << endl << "Cups in the coffee box " << cups << " pcs." << endl;
        cout << "How many cups do you want to set up?  ";
        cin >> cupsAmount;

        if (cupsAmount < 0 or cups + cupsAmount > MAX_CUPS) {
            cout << endl << "ERROR: The number of cups cannot be less or greater than 700" << endl;
        } else {
            cups += cupsAmount;
            cout << endl << "SUCCESS: You have set up " << cupsAmount << " cups." << endl;
            cout << "Cups in the coffee box " << cups << " pcs." << endl;
        }
    }
}

void getEarnings() {
    if (!isOpen) {
        cout << endl << "ERROR: Coffee Box is closed." << endl;
        cout << "You must open the Coffee Box first!" << endl;
    } else {
        if (earnings == 0.0) {
            cout << endl << "There is no earnings in the Coffee Box.";
        } else {
            cout << endl << "SUCCESS: You have picked up " << earnings << " BYN" << endl;
            earnings = 0.0;
        }
    }
}
