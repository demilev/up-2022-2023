#include <iostream>

/*

    Да се напише програма, която въвежда координатите на точка от равнината и извежда на кой квадрант принадлежи тя. 
    Да се разгледа и случая, в който точката съвпада с началото на координатната система (т.е. да извежда: „Точката е (0, 0)").
*/
int main() {

    // Отново декларираме и въвеждам стойността на променливите.
	// Нещо, което ще се прави в почти всяка задача.

    double x, y;
    std::cout << "Please input x: ";
    std::cin >> x;

    std::cout << "Please input y: ";
    std::cin >> y;

    /*
        Тази задача може да се реши по много начини:

        1) Единични if конструкции, които обхождат всички възможни сценарии:

            if (x > 0 && y > 0) {
                std::cout << "The point is in the I quadrant" << std::endl;
            }
            if (x < 0 && y > 0) {
                std::cout << "The point is in the II quadrant" << std::endl;
            }
            if (x < 0 && y < 0) {
                std::cout << "The point is in the III quadrant" << std::endl;
            }
            if (x > 0 && y < 0) {
                std::cout << "The point is in the IV quadrant" << std::endl;
            }
            if (x == 0 && y == 0) {
                std::cout << "The point is (0, 0)" << std::endl;
            }
            if (x == 0 && y != 0) {
                std::cout << "The point is on the x-axis" << std::endl;
            }
            if (x != 0 && y == 0) {
                std::cout << "The point is on the y-axis" << std::endl;
            }

        2) Вложени if-else конструкции:

            if (x > 0) {
                if (y > 0) {
                    std::cout << "The point is in the I quadrant" << std::endl;
                }
                if (y < 0)  {
                    std::cout << "The point is in the IV quadrant" << std::endl;
                }
                if (y == 0)  {
                    std::cout << "The point is on the x-axis" << std::endl;
                }
            } else {
                if (x < 0) {
                    if(y > 0) {
                        std::cout << "The point is in the II quadrant" << std::endl;
                    }
                    if(y < 0) {
                        std::cout << "The point is in the III quadrant" << std::endl;
                    }
                    if(y == 0) {
                        std::cout << "The point is on the x-axis" << std::endl;
                    }
                } else {
                    if(y == 0) {
                        std::cout << "The point is (0, 0)" << std::endl;
                    } else {
                        std::cout << "The point is on the y-axis" << std::endl;
                    }
                }
            }

        3) Конструкиця if - else if - else:

            if (x > 0) {
                if (y > 0) {
                    std::cout << "The point is in the I quadrant" << std::endl;
                }
                if (y < 0)  {
                    std::cout << "The point is in the IV quadrant" << std::endl;
                }
                if (y == 0)  {
                    std::cout << "The point is on the x-axis" << std::endl;
                }
            } else if (x < 0) {
                if(y > 0) {
                    std::cout << "The point is in the II quadrant" << std::endl;
                }
                if(y < 0) {
                    std::cout << "The point is in the III quadrant" << std::endl;
                }
                if(y == 0) {
                    std::cout << "The point is on the x-axis" << std::endl;
                }
            } else {
                if(y == 0) {
                    std::cout << "The point is (0, 0)" << std::endl;
                } else {
                    std::cout << "The point is on the y-axis" << std::endl;
                }
            }
    */

	if (x > 0 && y > 0) {
        std::cout << "The point is in the I quadrant" << std::endl;
    }
    if (x < 0 && y > 0) {
        std::cout << "The point is in the II quadrant" << std::endl;
    }
    if (x < 0 && y < 0) {
        std::cout << "The point is in the III quadrant" << std::endl;
    }
    if (x > 0 && y < 0) {
        std::cout << "The point is in the IV quadrant" << std::endl;
    }
    if (x == 0 && y == 0) {
        std::cout << "The point is (0, 0)" << std::endl;
    }
    if (x == 0 && y != 0) {
        std::cout << "The point is on the x-axis" << std::endl;
    }
    if (x != 0 && y == 0) {
        std::cout << "The point is on the y-axis" << std::endl;
    }

    return 0;
}