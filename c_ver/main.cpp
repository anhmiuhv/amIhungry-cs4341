#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <map>
#include "tree.h"
using namespace std;
inline bool isInteger(const std::string & s)
{
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

    char * p ;
    strtol(s.c_str(), &p, 10) ;

    return (*p == 0) ;
}

vector<string> SplitString(const char* str,const char* d) {
    vector<string> result;
    string str1(str);
    std::size_t pos = str1.find(d);
    string num1 = str1.substr(0, pos);
    result.push_back(num1);
    string num2 =  str1.substr(pos + 1);
    result.push_back(num2);
    return result;
}

int main(int argc, char** argv){
    srand (time(NULL));
    if (argc < 4) {
        cout << "too few argument" << endl;
        return 1;
    }
    map<string, string> queryList;
    map<string, string> observedCondition;
    bool first = true;
    int iteration;
    for (int i = 1; i < argc; i++){
        if (isInteger(argv[i]) && first == true){
            first = false;
            iteration = atoi(argv[i]);

        } else if (isInteger(argv[i]) && first == false){

            cout << "wrong command";
            return 1;
        } else {
            if (first) {
                vector<string> result = SplitString(argv[i], "=");
                queryList[result[0]] = result[1];
            } else {
                vector<string> result = SplitString(argv[i], "=");
                
                observedCondition[result[0]] = result[1];
            }

        }


    }
   // for (auto const& f: observedCondition){
   //     cout << f.first << endl;
   //     cout << f.second << endl;
   // }
    int countobserved = 0;
    int countquery = 0;
    Tree tr = createTree();
    
    for (int i = 0; i < iteration; i++) {
        bool isobserved = true; 
        tr.startTree();
        map<string, string> result = tr.printTree();
        for (auto const &x: observedCondition) {
            if (x.second != result[x.first])
                isobserved = false;
        }
        if (isobserved) {
            countobserved++;
            for (auto const &x: queryList) {
                if (x.second == result[x.first])
                    countquery++;
            }
        }
    }
    if (countobserved != 0) {
        cout << "Probability of the queried node: " << ((double) countquery / countobserved) << endl;
    }
    else {
        cout << "No node with observed condition found." << endl;
    }
  
}
