#ifndef NODE_H
#define NODE_H
#include <string>
#include <map>
#include <vector>
#include <utility>

class Node {
    std::string name;
    std::string status;
    std::map<std::string, double> characters;
    std::vector<Node*> parents;
    std::map<std::string, double> cpt;
    std::pair<std::string, std::string> nature;

    public:
    Node(std::string name, std::map<std::string, double> cpt, std::vector<Node*> parents = std::vector<Node*>(), std::pair<std::string, std::string> nature = std::pair<std::string, std::string>());
    std::string getName();
    std::string getStatus();
    std::string translateParent();
    void startRoot();
    void startNode();
    void setStatus(std::string status);
};
#endif
