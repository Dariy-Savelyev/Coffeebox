#include <iostream>

using namespace std;

bool isOpen = false;
int cups = 0;
double earnings = 0.0;

void printServiceMenu();
void serviceMenuSelectionProcessing(int choose);
void openCoffeeBox();
void setCups();
void viewEarnings();
void getEarnings();


int main() {
    cout << "Hello World";
    return 0;
}

void printServiceMenu() {
    int choose = 0;

    while(true) {
        cout << endl << "Service menu" << endl;
        cout << "-------------" << endl << endl;
        cout << "1. Open Coffee Box" << endl;
        cout << "2. Set cups" << endl;
        cout << "3. View earnings" << endl;
        cout << "4. Get earnings" << endl;
        cout << endl << "0. EXIT" << endl;

        cout << endl << "Please choose the option [0 - 4]: ";
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
        viewEarnings();
    } else if (choose == 4) {
        getEarnings();
    } else {
        cout << endl << "ERROR: No such option." << endl;
        cout << "Please input 0 - 4" << endl;
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
    int cupsAmount;
    const int MAX_CUPS = 700;

    cout << "Cups in the coffee box " << cups << " pcs." << endl;
    cout << endl << "How many cups do you want to set up?" << endl;
    cin >> cupsAmount;

    if (cupsAmount < 0 or cups + cupsAmount > MAX_CUPS) {
        cout << "ERROR: The number of cups cannot be negative or greater than 700" << endl;
    } else {
        cups += cupsAmount;
        cout <<  "You have successfully set up " << cupsAmount << " cups." << endl;
        cout << "Cups in the coffee box " << cups << " pcs." << endl;
    }
}
void viewEarnings() {
    cout << endl << "There are " << earnings << " BYN" << endl;
}
void getEarnings() {
    cout << endl << "You have successfully picked up " << earnings << " BYN" << endl;
}
