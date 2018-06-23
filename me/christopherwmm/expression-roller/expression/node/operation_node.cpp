#include "operation_node.h"

OperationNode::OperationNode() {
    this->operation = ' ';
    this->left = NULL;
    this->right = NULL;
}

OperationNode::OperationNode(const char operation) {
    this->operation = operation;
    this->left = NULL;
    this->right = NULL;
}

OperationNode::OperationNode(const char operation, const ExpressionNode *left, const ExpressionNode *right) {
    this->operation = operation;
    this->left = left;
    this->right = right;
}

OperationNode::~OperationNode() {
    delete this->left;
    this->left = NULL;

    delete this->right;
    this->right = NULL;
}

double OperationNode::getValue() const {
    double leftValue = ((this->getLeft()) ? this->getLeft()->getValue() : 0);
    double rightValue = ((this->getRight()) ? this->getRight()->getValue() : 0);

    double result = 0;

    switch(this->getOperation()) {
        case '+':
            result = leftValue + rightValue;
            break;

        case '-':
            result = leftValue - rightValue;
            break;

        case '*':
            if (this->getLeft() && this->getRight()) {
                result = leftValue * rightValue;
            } else {
                leftValue = ((this->getLeft()) ? this->getLeft()->getValue() : 1);
                rightValue = ((this->getRight()) ? this->getRight()->getValue() : 1);
                result = leftValue * rightValue;
            }

            break;

        case '/':
            if (this->getLeft() && this->getRight()) {
                result = leftValue / rightValue;
            } else {
                leftValue = ((this->getLeft()) ? this->getLeft()->getValue() : 1);
                rightValue = ((this->getRight()) ? this->getRight()->getValue() : 1);
                result = leftValue / rightValue;
            }

            break;

        case '%':
            if (this->getLeft() && this->getRight()) {
                result = std::abs(std::fmod(leftValue, rightValue));
            } else {
                leftValue = ((this->getLeft()) ? this->getLeft()->getValue() : 1);
                rightValue = ((this->getRight()) ? this->getRight()->getValue() : 1);
                result = std::abs(std::fmod(leftValue, rightValue));
            }

            break;

        case '^':
            if (this->getLeft() && this->getRight()) {
                result = std::pow(leftValue, rightValue);
            } else {
                leftValue = ((this->getLeft()) ? this->getLeft()->getValue() : 1);
                rightValue = ((this->getRight()) ? this->getRight()->getValue() : 1);
                result = std::pow(leftValue, rightValue);
            }

            break;

        default:
            result = 0;
    }

    return result;
}

char OperationNode::getOperation() const {
    return this->operation;
}

void OperationNode::setOperation(const char operation) {
    this->operation = operation;
}

const ExpressionNode* OperationNode::getLeft() const {
    return this->left;
}

void OperationNode::setLeft(const ExpressionNode *left) {
    this->left = left;
}

const ExpressionNode* OperationNode::getRight() const {
    return this->right;
}

void OperationNode::setRight(const ExpressionNode *right) {
    this->right = right;
}
