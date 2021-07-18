#pragma once
using namespace std;

class Phone
{
	public:

		// constructor with properties
		Phone(char, int, float);

		// data input
		void Input();

		// data printing
		void Print()const;

		// getters
		char getMark()const;

		int getNum()const;

		float getSum()const;

		// setters
		void setMark(char);

		void setNum(int);

		void setSum(float);

	private:
		char mark; // Phone mark
		int num; // Phone Number
		float sum; // Phone sum
};