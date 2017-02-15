#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <map>
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
    if (argc < 4) {
        cout << "too few argument" << endl;
        return 1;
    }
    map<string, string> querryList;
    map<string, string> querryCondition;
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
                querryList[result[0]] = result[1];
            } else {
                vector<string> result = SplitString(argv[i], "=");
                
                querryCondition[result[0]] = result[1];
            }

        }


    }
    for (auto const& f: querryList){
        cout << f.first << endl;
        cout << f.second << endl;
    }
  
}
