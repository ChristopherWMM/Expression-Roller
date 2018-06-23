#include "expression_tree.h"

ExpressionTree::ExpressionTree(std::string expression) {
    this->root = parseExpression(expression);
}

ExpressionTree::~ExpressionTree() {
    delete this->root;
    this->root = NULL;
}

const ExpressionNode* ExpressionTree::parseExpression(std::string expression) {
    std::stringstream parser(expression);
    char currentCharacter;

    while (parser >> currentCharacter) {
        if (isspace(currentCharacter)) {
            continue;
        }

        switch (tolower(currentCharacter)) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
            case 'd':
                processOperation(currentCharacter);
                break;

            case '(':
            case ')':
                processParenthesis(currentCharacter);
                break;

            default:
                if (!isdigit(currentCharacter) && currentCharacter != '.') {
                    continue;
                }

                parser.putback(currentCharacter);

                double leftNumber;
                parser >> leftNumber;

                NumericNode *number = new NumericNode(leftNumber);
                operands.push(number);
        }
    }

    while (operators.size() > 0) {
        buildTree(operators.top());
        operators.pop();
    }

    return ((operands.size() > 0) ? operands.top() : NULL);
}

int ExpressionTree::getOperationPrecedence(char operation) {
    enum {
        LOWEST, LOW, NORMAL, HIGHEST
    };

    int precedence = LOWEST;

    switch (operation) {
        case ')':
        case '(':
            precedence = LOWEST;
            break;

        case '+':
        case '-':
            precedence = LOW;
            break;

        case '*':
        case '/':
        case '%':
            precedence = NORMAL;
            break;

        case 'd':
        case '^':
            precedence = HIGHEST;
            break;
    }

    return precedence;
}

void ExpressionTree::processOperation(char operation) {
    int precedence = getOperationPrecedence(operation);

    while (operators.size() > 0 && precedence <= getOperationPrecedence(operators.top())) {
        buildTree(operators.top());
        operators.pop();
    }

    operators.push(operation);
}

void ExpressionTree::processParenthesis(char parenthesis) {
    if (parenthesis == ')') {
        while (operators.size() > 0 && operators.top() != '(') {
            buildTree(operators.top());
            operators.pop();
        }

        if (operators.size() > 0) {
            operators.pop();
        }
    } else if (parenthesis == '(') {
        operators.push(parenthesis);
    } else {
        return;
    }
}

void ExpressionTree::buildTree(char operation) {
    const ExpressionNode *right = NULL;
    const ExpressionNode *left = NULL;

    if (operands.size() > 0) {
        right = operands.top();
        operands.pop();
    }

    if (operands.size() > 0) {
        left = operands.top();
        operands.pop();
    }

    OperationNode *root = new OperationNode(operators.top(), left, right);

    if (operation == 'd' || operation == 'D') {
        root = new RollNode(left, right);
        rolls.push_back(static_cast<const RollNode *>(root)->getRoll());
    }

    operands.push(root);
}

double ExpressionTree::evaluate() const {
    return ((this->root) ? this->root->getValue() : 0);
}

std::vector<Roll> ExpressionTree::getRolls() {
    return this->rolls;
}
