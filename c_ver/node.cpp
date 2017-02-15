#include "node.h"
#include <cstdlib>
#include <iostream>

Node::Node(std::string name, std::map<std::string, double> cpt, std::vector<Node*> parents, std::pair<std::string, std::string> nature) {
    this->name = name;
    this->parents = parents;
    this->cpt = cpt;
    this->nature = nature;
}

std::string Node::getName() {
    return this->name;
}

std::string Node::getStatus() {
    return this->status;
}

std::string Node::translateParent() {
    std::string result;
    for (Node* node: this->parents) {
        result += node->getStatus();
    }
    return result;
}

void Node::setStatus(std::string status) {
    this->status = status;
}

void Node::startRoot() {
    double i = (double) rand() / RAND_MAX;
    double prev = 0;
    for (auto const& x: cpt) {
        if ((i >= prev) && (i <= x.second + prev)) {
            setStatus(x.first);
            return;
        }
        prev += x.second;
    }
}

void Node::startNode() {
    double i = (double) rand() / RAND_MAX;
    if (i <= cpt[translateParent()]) {
        setStatus(nature.first);
    }
    else {
        setStatus(nature.second);
    }
}

