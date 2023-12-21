#include <iostream>
#include <string>
#include "Bankomat.h"
using namespace std;

int main() {
    Bankomat atm1("ATM-XX1", 1000, 10, 5000);
    atm1.SetID(1930);
    atm1.Print();
    cout << atm1.Str(atm1.GiveMoney(200)) << endl;
    cout << endl;
    atm1.GetMoney(500);
    cout << atm1.Str(atm1.GiveMoney(500)) << endl;
    atm1.SetID(222);
    atm1.Print();
}