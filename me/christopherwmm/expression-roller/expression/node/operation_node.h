#ifndef OPERATION_NODE_H
#define OPERATION_NODE_H

#include "expression_node.h"
#include "roll.h"
#include <iostream>
#include <cmath>

class OperationNode : public ExpressionNode {
    public:
        OperationNode();
        OperationNode(const char operation);
        OperationNode(const char operation, const ExpressionNode *left, const ExpressionNode *right);
        virtual ~OperationNode();

        virtual double getValue() const;
        char getOperation() const;
        void setOperation(const char operation);
        const ExpressionNode* getLeft() const;
        void setLeft(const ExpressionNode *left);
        const ExpressionNode* getRight() const;
        void setRight(const ExpressionNode *right);

    private:
        char operation;
        const ExpressionNode *left;
        const ExpressionNode *right;
};

#endif
