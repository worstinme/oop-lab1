// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "stdlib.h"
#include "string.h"
#include <iostream>
#include "main.h"


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

void Phone::Input() {
	char m;
	int n;
	float s;
	cout << "Input mark: ";
	cin >> m;
	setMark(m);
	cout << "Input num: ";
	cin >> n;
	setNum(n);
	cout << "Input sum: ";
	cin >> s;
	setSum(s);
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

// setters
void Phone::setMark(char val)
{
	mark = val;
}

void Phone::setNum(int val) {
	num = val;
}

void Phone::setSum(float val) {
	sum = val;
}
