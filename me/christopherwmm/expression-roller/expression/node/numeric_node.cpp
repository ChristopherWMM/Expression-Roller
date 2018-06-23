#include "numeric_node.h"

NumericNode::NumericNode() {
    this->value = 0;
}

NumericNode::NumericNode(const double value) {
    this->value = value;
}

double NumericNode::getValue() const {
    return this->value;
}

void NumericNode::setValue(const double value) {
    this->value = value;
}
