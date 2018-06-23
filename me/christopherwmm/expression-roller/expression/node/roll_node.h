#ifndef ROLL_NODE_H
#define ROLL_NODE_H

#include "operation_node.h"
#include "roll.h"

class RollNode : public OperationNode {
    public:
        RollNode();
        RollNode(const int rolls, const int sides);
        RollNode(const std::string roll);
        RollNode(const Roll roll);
        RollNode(const ExpressionNode *left, const ExpressionNode *right);

        virtual double getValue() const;
        Roll getRoll() const;

    private:
        Roll roll;
};

#endif
