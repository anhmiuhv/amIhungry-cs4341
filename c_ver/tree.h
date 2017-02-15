#ifndef TREE_H
#define TREE_H
#include "node.h"
#include "dictionary.h"
#include <vector>
#include <map>

class Tree {
    std::vector<Node*> nodes;
    std::vector<Node*> god;
    public:
    Tree(std::vector<Node*> nodes);
    void setGod(std::vector<Node*> nodes);
    void startTree();
    std::map<std::string, std::string> printTree();
};

Tree createTree();

#endif
