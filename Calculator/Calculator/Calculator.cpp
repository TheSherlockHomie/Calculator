// Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <limits>

void keepConsoleOpen();
int main()
{
	int result, rightValue, leftValue = 0;
	char op;
	std::cout << "Enter an expression  ('+' , '-' , '*' and '/' supported)" << std::endl;
	std::cin >> leftValue >> op >> rightValue;             //Read input like 1 + 3
	std::cin.get();

	{                                                      //Calculation
		if (op == '+')
			result = leftValue + rightValue;
		else if (op == '-')
			result = leftValue - rightValue;
		else if (op == '*')
			result = leftValue * rightValue;
		else if (op == '/')
			if(rightValue == 0)
				std::cerr << "Divisor can't be 0!" << std::endl;
			else
			result = leftValue / rightValue;				
		else
		{
			std::cerr << "Invalid Operator!" << std::endl;
			keepConsoleOpen();
			return 1;
		}
	}
	
	std::cout << " = " << result << std::endl;             //Output result

	keepConsoleOpen();
	return 0;
}

void keepConsoleOpen()
{                                                      //To keep console window open until 'Enter' key is pressed
	std::cout << "Press enter to exit..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}