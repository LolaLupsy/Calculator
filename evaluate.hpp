#include <iostream>
#include<stack>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;

const double PI = 3.141592653589793238463;

class Calculator {
private:
    string terms;
public:

    Calculator(string Expression);
    int lenght(int t);
    bool Priority(char a, char b);
    double Evaluate(string str);
    string GetExpression(string exp);
    string First();
    double Sinus(string str);
    double Cosnus(string str);
    double Tangens(string str);
    double Radical(string str);
    double Ln(string str);
    double Lg(string str);
    double Exponenta(string str);
   // double Exponentiation(string str);
};