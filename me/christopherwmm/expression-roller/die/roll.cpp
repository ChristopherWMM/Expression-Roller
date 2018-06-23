#include "roll.h"
#include <iostream>

Roll::Roll() {
    Die die(1);
    this->dice.push_back(die);
}

Roll::Roll(const int rolls, const int sides) {
    std::vector<Die> dice;
    
    int temp = rolls;
    
    if (temp < 1) {
        temp = 1;
    }

    for (int x = 0; x < temp; x++) {
        Die die(sides);
        dice.push_back(die);
    }

    setDice(dice);
}

Roll::Roll(const std::string dice) {
    setDice(parseRollFormula(dice));
}

Roll::Roll(const std::vector<Die> dice) {
    setDice(dice);
}

Roll::Roll(const Roll &roll) {
    setDice(roll.getDice());
}

int Roll::getNumberOfDice() const {
    return numberOfDice;
}

std::vector<Die> Roll::parseRollFormula(std::string rollFormula) {
    if (rollFormula.length() < 2) {
        std::cout << "Error: Not enough information in this formula." << std::endl;
        InvalidDieNumberException e;
        throw e;
    }

    std::string rolls;
    std::string sides;
    bool d = false;

    for (int x = 0; x < rollFormula.length(); x++) {
        if (isspace(rollFormula[x])) {
            continue;
        }

        if (rollFormula[x] == 'd' || rollFormula[x] == 'D')
        {
            if (!d) {
                d = true;
            } else {
                std::cout << "Error: Multiple D's in this formula." << std::endl;
                InvalidDieNumberException e;
                throw e;
            }
        } else if (isdigit(rollFormula[x])) {
            if (!d) {
               rolls += rollFormula[x];
            } else {
                sides += rollFormula[x];
            }
        } else {
            InvalidDieNumberException e;
            throw e;
        }
    }

    if (sides.length() < 1) {
        std::cout << "Error: Invalid number of sides in this formula." << std::endl;
        InvalidDieNumberException e;
        throw e;
    }

    int numRolls = atoi(rolls.c_str());
    int numSides = atoi(sides.c_str());
    std::vector<Die> dice;

    if (numRolls < 1) {
        numRolls = 1;
    }

    for (int x = 0; x < numRolls; x++) {
        Die die(numSides);
        dice.push_back(die);
    }

    return dice;
};

void Roll::setNumberOfDice(const int numberOfDice) {
    if (numberOfDice < 1) {
        InvalidDieNumberException e;
        throw e;
    }

    this->numberOfDice = numberOfDice;
}

int Roll::getSides() const {
    return sides;
}

void Roll::setSides(const int sides) {
    for (int x = 0; x < newDice.size(); x++) {
        if (newDice[x].getSides() != sides) {
            InconsistentDieSidesException e;
            throw e;
        }
    }

    this->sides = sides;
}

int Roll::getRangeMax() const {
    return this->rangeMax;
}

void Roll::setRangeMax(const int rangeMax) {
    this->rangeMax = rangeMax;
}

int Roll::getRangeMin() const {
    return this->rangeMin;
}

void Roll::setRangeMin(const int rangeMin) {
    this->rangeMin = rangeMin;
}

int Roll::getResult() const {
    int result = 0;

    for (int x = 0; x < this->dice.size(); x++) {
        result += getDice()[x].getResult();
    }

    return result;
}

std::vector<Die> Roll::getDice() const {
    return this->dice;
}

void Roll::setDice(const std::vector<Die> dice) {
    this->newDice = dice;

    setNumberOfDice(dice.size());
    setSides(dice[0].getSides());
    setRangeMax(dice.size() * dice[0].getSides());
    setRangeMin(dice.size());

    this->dice = dice;
}
