#ifndef TREE_H
#define TREE_H
#include "node.h"
#include "dictionary.h"
#include <vector>

class Tree {
    std::vector<Node*> nodes;
    std::vector<Node*> god;
    public:
    Tree(std::vector<Node*> nodes);
    void setGod(std::vector<Node*> nodes);
    void startTree();
};

Tree createTree();

#endif
