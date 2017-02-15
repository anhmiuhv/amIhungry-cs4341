#include "tree.h"
#include <algorithm>

Tree::Tree(std::vector<Node*> nodes) {
    this->nodes = nodes;
}

void Tree::setGod(std::vector<Node*> nodes) {
    this->god = nodes;
}

void Tree::startTree() {
    for (Node* node: god) {
        node->startRoot();
    }
    for (Node* node: nodes) {
        if (std::find(god.begin(), god.end(), node) == god.end()) {
            node->startNode();
        }
    }
}
