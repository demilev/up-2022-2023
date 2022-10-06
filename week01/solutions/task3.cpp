#include <iostream>


/*
    Да се напише програма, която определя дали дадено реално число х лежи в интервала [a, b].
    За целта да се използва променлива от тип bool, която да има стойност true, ако x е в интервала и false в противен случай.
*/

int main() {
    
    // деклариране и въвеждане на променливите
    double a, b, x;
    std::cout << "Please input a: ";
    std::cin >> a;

    std::cout << "Please input b: ";
    std::cin >> b;

    std::cout << "Please input x: ";
    std::cin >> x;
	
    // дефиниране на булева променлива, която приема резултата на логически израз
    bool isInInterval = (x >= a && x <= b); 

	if (isInInterval) { 
		std::cout << "x is in [ " << a << "; " << b << " ]" << std::endl; 
	}															 
	else {
		std::cout << "x is not in [ " << a << "; " << b << " ]" << std::endl;
	}

    return 0;
}