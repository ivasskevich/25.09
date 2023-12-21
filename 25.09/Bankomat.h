#pragma once
#include <iostream>
#include <string>
using namespace std;

class Bankomat
{
	string res;
	int sum;
	int max;
	int min;
	int id;
	int nominals[6] = { 20, 50, 100, 200, 500, 1000 };
public:
	Bankomat() = default;
	Bankomat(string str, int m, int min_m, int max_m);
	void Print() const;
	string Str(int r) const;
	void GetMoney(int mon);
	int GiveMoney(int amount);
	void SetID(int newID);
};