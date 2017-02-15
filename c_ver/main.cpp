#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <utility>
#include <numeric>
#include <thread>
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
    std::transform(num1.begin(), num1.end(), num1.begin(), ::tolower);
    result.push_back(num1);

    string num2 =  str1.substr(pos + 1);
    std::transform(num2.begin(), num2.end(), num2.begin(), ::tolower);
    result.push_back(num2);

    return result;
}

void threads(int iterations, vector<float> *res, int* count, map<string, string> observedCondition, map<string, string> queryList) {
    
    Tree tr = createTree();
    *count = 0;
    for (int i = 0; i < iterations; i++) {
        int countobserved = 0;
        int countquery = 0;
        for (int j = 0; j < 1000; j++){
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
        *count = *count + countobserved;
        res->push_back((float)countquery / countobserved);
    }

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
    int iteration = 0;
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

    vector<float> res1, res2, res3, res4;
    int count1, count2, count3, count4;
    if (iteration < 4) iteration = 4;
    thread firstt(threads, iteration /4, &res1, &count1, observedCondition, queryList);
    thread secondt(threads, iteration/4, &res2, &count2, observedCondition, queryList);
    thread thirdt(threads, iteration/4, &res3, &count3, observedCondition, queryList);
    thread fourtht(threads, iteration/4, &res4, &count4, observedCondition, queryList);
    firstt.join();
    secondt.join();
    thirdt.join();
    fourtht.join();
    res1.insert(res1.end(), res2.begin(), res2.end());
    res1.insert(res1.end(), res3.begin(), res3.end());
    res1.insert(res1.end(), res4.begin(), res4.end());
    double sum = std::accumulate(std::begin(res1), std::end(res1), 0.0);
    double m =  sum / res1.size();

    double accum = 0.0;
    std::for_each (std::begin(res1), std::end(res1), [&](const double d) {
        accum += (d - m) * (d - m);
    });

    double stdev = sqrt(accum / (res1.size()-1));

    int c = count1 + count2 + count3 + count4;
    if (c != 0) {
        cout << "Total number of samples: " << iteration * 1000 << endl;
        cout << "Number of non-rejected samples: " << c << endl;
        cout << "Standard deviation is: " << stdev << endl;

        cout << "Probability of the queried node: " << m << endl;
    }
    else {
        cout << "No node with observed condition found." << endl;
    }
    
}
