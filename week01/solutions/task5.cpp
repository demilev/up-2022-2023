#include <iostream>


/*
    Да се напише програма, която разменя и извежда стойностите на две цели числа без да използва помощна променлива.
*/

int main() {
    /* всичко е отново по шаблон */
    
    int firstNumber, secondNumber;

	std::cout << "Enter first number: ";
	std::cin >> firstNumber;

	std::cout << "Enter second number: ";
	std::cin >> secondNumber;

	firstNumber = firstNumber + secondNumber; 
	secondNumber = firstNumber - secondNumber;
	firstNumber = firstNumber - secondNumber;

	/* 
		Проследете сами стойностите на двете променливи
	   	и се убедете, че наистна накрая ще имат разменени
	   	стойности.
	*/

	std::cout << "First number is now: " << firstNumber << ", and second number is: " << secondNumber << std::endl;
	return 0;
}