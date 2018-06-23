#include "roll_node.h"

RollNode::RollNode() : OperationNode('d') {
    this->roll = Roll();
}

RollNode::RollNode(const int rolls, const int sides) : OperationNode('d') {
    this->roll = Roll(rolls, sides);
}

RollNode::RollNode(const std::string roll) : OperationNode('d') {
    this->roll = Roll(roll);
}

RollNode::RollNode(const Roll roll) : OperationNode('d') {
    this->roll = roll;
}

RollNode::RollNode(const ExpressionNode *left, const ExpressionNode *right) : OperationNode('d', left, right) {
    double leftValue = ((this->getLeft()) ? this->getLeft()->getValue() : 1);
    double rightValue = ((this->getRight()) ? this->getRight()->getValue() : 1);

    const Roll roll(leftValue, rightValue);
    this->roll = roll;
}

double RollNode::getValue() const {
    return roll.getResult();
}

Roll RollNode::getRoll() const {
    return this->roll;
}
