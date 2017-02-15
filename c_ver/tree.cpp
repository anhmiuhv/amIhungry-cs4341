#include "tree.h"
#include "dictionary.h"
#include <algorithm>
#include <iostream>

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

std::map<std::string, std::string> Tree::printTree() {
    std::map<std::string, std::string> result;
    for (Node* node: nodes) {
        result.emplace(node->getName(), node->getStatus());
    }
}

Tree createTree() {
    // std::map<std::string, double> dictHumidity;
    // std::map<std::string, double> dictTemp;
    // std::map<std::string, double> dictDay;
    // std::map<std::string, double> dictIcyTrue;
    // std::map<std::string, double> dictSnowTrue;
    // std::map<std::string, double> dictCloudTrue;
    // std::map<std::string, double> dictExamTrue;
    // std::map<std::string, double> dictStressTrue;
    initDicts();
    Node *humidityNode = new Node("humidity",dictHumidity);
    Node *tempNode = new Node("temperature",dictTemp);
    Node *dayNode = new Node("day",dictDay);

    std::pair<std::string, std::string> truefalse("true", "false");
    std::vector<Node*> x;
    x.push_back(humidityNode);
    x.push_back(tempNode);
    Node *icyNode = new Node("icy",dictIcyTrue,x,truefalse);
    Node *snowNode = new Node("snow",dictSnowTrue,x,truefalse);
    x.clear();
    x.push_back(snowNode);
    Node *cloudyNode = new Node("cloudy",dictCloudTrue,x,truefalse);
    x.push_back(dayNode);
    Node *examNode = new Node("exam",dictExamTrue,x,truefalse);
    x.clear();
    x.push_back(snowNode);
    x.push_back(examNode);
    truefalse = std::pair<std::string, std::string>("high", "low");
    Node *stressNode = new Node("stress",dictStressTrue,x,truefalse);
    std::vector<Node*> nodes;
    nodes.push_back(humidityNode);
    nodes.push_back(tempNode);
    nodes.push_back(dayNode);
    nodes.push_back(icyNode);
    nodes.push_back(snowNode);
    nodes.push_back(cloudyNode);
    nodes.push_back(examNode);
    nodes.push_back(stressNode);
    Tree tr(nodes);
    x.clear();
    x.push_back(humidityNode);
    x.push_back(tempNode);
    x.push_back(dayNode);
    tr.setGod(x);
    return tr;

}
