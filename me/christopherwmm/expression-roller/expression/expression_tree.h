#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <stack>
#include <sstream>
#include "expression_node.h"
#include "numeric_node.h"
#include "operation_node.h"
#include "roll_node.h"

class ExpressionTree {
    public:
        ExpressionTree();
        ExpressionTree(std::string expression);
        ExpressionTree(ExpressionTree &expressionTree);
        ~ExpressionTree();

        double evaluate() const;
        std::vector<Roll> getRolls();

    private:
        const ExpressionNode* parseExpression(std::string);
        int getOperationPrecedence(char operation);
        void processOperation(char operation);
        void processParenthesis(char parenthesis);
        void buildTree(char operation);

        std::stack<char> operators;
        std::stack<const ExpressionNode *> operands;
        std::vector<Roll> rolls;
        const ExpressionNode *root;
};

#endif
