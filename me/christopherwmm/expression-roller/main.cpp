#include <iostream>
#include <Windows.h>
#include "roll.h"
#include "die.h"
#include "expression_tree.h"

/* Prototypes */
std::string toLower(std::string message);

int main(int argc, char *argv[]) {
    // Required to seed the rand() function utilized in all dice.
    std::srand(std::time(NULL));
    bool retry = true;

    do {
        std::cout << "- Please enter an expression: ";
        std::string temp;
        std::getline(std::cin, temp);
        
        if (toLower(temp.substr(0, 4)) == "help") {
            std::cout << std::endl << "------[ Valid Operators ]------" << std::endl;
            std::cout << "X+Y : Adds X to Y." << std::endl;
            std::cout << "   >> Ex: 1+1 = 2" << std::endl << std::endl;
            std::cout << "X-Y : Subtracts X from Y or denotes a negative number." << std::endl;
            std::cout << "   >> Ex: -4-3 = -7" << std::endl;
            std::cout << "   >> Ex: -3 = -3" << std::endl << std::endl;
            std::cout << "X*Y : Multiplies X by Y." << std::endl;
            std::cout << "   >> Ex: 2*3 = 6" << std::endl << std::endl;
            std::cout << "X/Y : Divides X by Y." << std::endl;
            std::cout << "   >> Ex: -4/2 = -2" << std::endl << std::endl;
            std::cout << "X%Y : Mods X by Y." << std::endl;
            std::cout << "   >> Ex: 10%3 = 1" << std::endl << std::endl;
            std::cout << "X^Y : Raises X to the Y power." << std::endl;
            std::cout << "   >> Ex: 2^3 = 8" << std::endl << std::endl;
            std::cout << "XdY : Rolls a Y sided die X times and sums their results." << std::endl;
            std::cout << "   >> Ex: d2 = [1 || 2]" << std::endl;
            std::cout << "   >> Ex: 1d4 = [1 || 2 || 3 || 4]" << std::endl << std::endl;
            continue;
        } else if (toLower(temp.substr(0, 4)) == "quit") {
            std::cout << std::endl << ">> Exiting..." << std::endl;
            retry = false;
        } else {
            std::cout << std::endl;
            ExpressionTree e(temp);
            std::vector<Roll> rolls = e.getRolls();

            for (int x = 0; x < rolls.size(); x++) {
                std::vector<Die> dice = rolls[x].getDice();
                std::cout << "  >> Rolling " << rolls[x].getNumberOfDice() << "d" << rolls[x].getSides() << std::endl;

                for (int y = 0; y < dice.size(); y++) {
                    Sleep(500 / rolls[x].getNumberOfDice());
                    std::cout << "    >> Rolling d" << dice[y].getSides() << " #" << (y + 1) << ": " << dice[y].getResult() << std::endl;
                    Sleep(500 / rolls[x].getNumberOfDice());
                }

                std::cout << std::endl << "    >> Total Roll Result: " << rolls[x].getResult() << std::endl << std::endl;
            }

            std::cout << ">> Total Result: " << e.evaluate() << std::endl << std::endl;
        }
    } while (retry);

    system("PAUSE");
    return EXIT_SUCCESS;
}

std::string toLower(std::string message) {
    std::string lower;

    for (int x = 0; x < message.length(); x++) {
        lower += tolower(message[x]);
    }

    return lower;
}
