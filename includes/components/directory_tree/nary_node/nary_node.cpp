#include "nary_node.h"


Node::Node(string data, vector<shared_ptr<Node>> children)
{
    this->_data = data;
    this->_children = children;
}

Node::~Node(){}