#include "Bankomat.h"
#include <iostream>
#include <string>
using namespace std;

Bankomat::Bankomat(string str, int m, int min_m, int max_m) : res(str), sum(m), min(min_m), max(max_m), id(0) {}

void Bankomat::Print() const
{
    cout << "Bankomat\n";
    cout << "id: " << id << endl;
    cout << "Value ATM: " << sum << endl;
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << endl << endl;
}

string Bankomat::Str(int r) const {
    return to_string(r);
}

void Bankomat::GetMoney(int mon) {
    bool validNominal = false;
    for (int i = 0; i < 6; i++) {
        if (mon == nominals[i]) {
            validNominal = true;
            break;
        }
    }

    if (validNominal) {
        if (sum + mon <= max) {
            sum += mon;
            cout << "Added " << mon << " UAH.\n";
            cout << "Current balance: " << sum << " UAH.\n";
        }
        else {
            cout << "Sucsessfull\n";
        }
    }
    else {
        cout << "Problem.\n";
    }
}


int Bankomat::GiveMoney(int amount) {
    if (amount >= min && amount <= max && amount <= sum) {
        bool validNominal = false;
        for (int i = 0; i < 6; i++) {
            if (amount == nominals[i]) {
                validNominal = true;
                break;
            }
        }

        if (validNominal) {
            if (amount % 10 == 0) {
                sum -= amount;
                cout << "Issuance of such amount: " << amount << " UAH.\n";
                cout << "Current balance: " << sum << " UAH.\n";
                return amount;
            }
            else {
                cout << "The amount to be withdrawn must be a multiple of 10 UAH!\n";
                return -1;
            }
        }
        else {
            cout << "Invalid banknote denomination. Unable to withdraw " << amount << " UAH from ATM.\n";
            return -1;
        }
    }
    else {
        cout << "Unable to withdraw " << amount << " UAH from ATM.\n";
        return -1;
    }
}

void Bankomat::SetID(int id) {
    this->id = id;
}
