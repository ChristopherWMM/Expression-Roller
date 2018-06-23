#ifndef NUMERIC_NODE_H
#define NUMERIC_NODE_H

#include "expression_node.h"

class NumericNode : public ExpressionNode {
    public:
        NumericNode();
        NumericNode(const double value);

        virtual double getValue() const;
        virtual void setValue(const double value);

    private:
        double value;
};

#endif
