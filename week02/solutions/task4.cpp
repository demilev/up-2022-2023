#include <iostream>

int main()
{

    int number;
    std::cin >> number;

    if (number < 1000 || number > 9999)
    {
        std::cout << "Only numbers with four digits are accepted" << std::endl;
    }
    else
    {
        int fourthDigit = number % 10; // % x ни дава последната цифра на числото в x-ична бройна система
        int thirdDigit = (number / 10) % 10; // / x ни дава числото без последната цифра в x-ична бройна система
        int secondDigit = (number / 100) % 10;
        int firstDigit = number / 1000;

        if (firstDigit <= secondDigit && secondDigit <= thirdDigit && thirdDigit <= fourthDigit)
        {
            std::cout << "The digits of " << number << " are sorted" << std::endl;
        }
        else
        {
            std::cout << "The digits of " << number << " are not sorted" << std::endl;
        }
    }

    return 0;
}