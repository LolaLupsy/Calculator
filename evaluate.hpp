#include <iostream>
#include<stack>
#include<string>
#include<sstream>

using namespace std;

class Calculator {
private:
    string exp;
public:

    Calculator(string Expression);
    int lenght(int t);

    bool Priority(char a, char b);

    string GetExpression();

    double Evaluate(string str);
};