// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "stdlib.h"
#include "string.h"
#include <iostream>
#include "main.h"
#include <sstream>
#include <algorithm>

// constructor with parameters
Phone::Phone(char a, int b, float c) {
	setMark(a);
	setNum(b);
	setSum(c);
}

// data print
void Phone::Print()const {
    cout << "Mark -> " << getMark() << endl;
    cout << "Num -> " << getNum() << endl;
    cout << "Sum -> " << getSum() << endl;
}

// set user data with validation of input values
void Phone::Input() {

	string value;
	// wait for char M input
	cout << "Input mark (single Alphabetical char): " << endl;
	cin >> value;
	while (validateAndSetMark(value) == false) {
		cout << "please input only single alphabetic char: " << endl;
		cin.clear();
		cin >> value;
	}
	cin.clear();

	// wait for valid Num input
	cout << "Input num (Int): " << endl;
	cin >> value;
	while (validateAndSetNum(value) == false) {
		cout << "please input only int from 1 to 2147483647: " << endl;
		cin.clear();
		cin >> value;
	}
	cin.clear();

	// wait for valid Num input
	cout << "Input sum (0 to 1000, with comma separator): " << endl;
	cin >> value;
	while (validateAndSetSum(value) == false) {
		cout << "please input sum from 0 to 1000, with comma separator: " << endl;
		cin.clear();
		cin >> value;
	}
	cin.clear();
}

int main() 
{
	setlocale(LC_ALL, "rus");
	Phone p{ 'I',231029,23.123f }; // define object by contructor
	cout << "Object defined with parameters: " << endl;
	p.Print(); // print out object
	cout << endl;
	Phone* pd = new Phone{ 'N',908123,4512.23f }; // define object by  operator new
	cout << "Object defined by 'new' operator: " << endl;
	pd->Print(); // print out object
	cout << endl;
	delete pd; // clear object from memory
	cout << "Please provide values for next Phone object: " << endl;
	p.Input(); // data input
	cout << "Object defined with provided values: " << endl;
	p.Print();
	cout << endl;
	system("pause");

	return 0;
}

// getters
char Phone::getMark()const {
	return mark;
}

int Phone::getNum()const {
	return num;
}

float Phone::getSum()const {
	return sum;
}

// setters with validation
bool Phone::validateAndSetMark(string value)
{
	if (value.length() != 1) //validate that string contains only 1 char
	{
		return false;
	}
	if (!isalpha(static_cast<unsigned char>(value[0]))) { // validate 1 char is valid alphabetic 
		return false;
	}
	mark = value[0];
	return true;
}

bool Phone::validateAndSetNum(string value)
{
	// check if string is empty or not integer-like
	if (value.empty() || !isStringContainsDigitsOnly(value)) {
		return false;
	}

	// cast string to integer
	std::istringstream issValue(value);
	int castedNumber;
	issValue >> castedNumber;

	// check if cast was succeed and casted number is greater then 0
	if (issValue.fail() || castedNumber <= 0) {
		return false;
	}

	num = castedNumber;
	issValue.clear();

	return true;
}

bool Phone::validateAndSetSum(std::string value)
{
	// check if string is empty or not numeric
	if (value.empty() || !isNumericString(value)) {
		return false;
	}

	float floatedNumber = stof(value);
	if (floatedNumber < 0 || floatedNumber > 1000)
	{
		return false;
	}
	sum = floatedNumber;
	return true;
}

bool Phone::isStringContainsDigitsOnly(const string s)
{
	return(strspn(s.c_str(), "0123456789") == s.size());
}

bool Phone::isNumericString(const string s)
{
	return(strspn(s.c_str(), "-0123456789,") == s.size());
}

// setters
void Phone::setMark(char val) {
	mark = val;
}

void Phone::setNum(int val) {
	num = val;
}

void Phone::setSum(float val) {
	sum = val;
}
