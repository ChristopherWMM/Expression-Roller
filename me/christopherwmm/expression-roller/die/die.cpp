#include "die.h"

Die::Die(const int sides) {
    this->sides = sides;
    this->result = roll(sides);
}

Die::Die(const Die &die) {
    this->sides = die.getSides();
    this->result = die.getResult();
}

int Die::roll(const int max, const int min) {
    return std::rand() % (max - min + 1) + min;
}

int Die::getSides() const {
    return this->sides;
}

int Die::getResult() const {
    return this->result;
}
