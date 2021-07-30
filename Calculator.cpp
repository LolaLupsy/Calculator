#include <iostream>
#include<stack>
#include<string>
#include<ctype.h>

using namespace std;

class Calculator {
private:
     string exp;
public:
   
    Calculator(string Expression) :exp(Expression) {};
  
    bool Priority(char a, char b) {
        int aW, bW;
        if (a == '*' || a == '/') {
            aW = 2;
        }
        else  aW = 1;
        if (b == '*' || b == '/') {
            bW = 2;
        }
        else bW = 1;
        return aW >= bW;
        
    }

    string GetExpression() {//преобразует из инфикса в постфикс
        string convertStr="";//новая строка
        stack<char>oper;//cтэк для операторов
        for (size_t i = 0;i < exp.length();i++) {
            if (isdigit(exp[i])) {
                convertStr += exp[i];
            }
            else if (exp[i] == '(') {
                oper.push(exp[i]);
            }
            else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*') {
                if (oper.empty() || oper.top() == '(') {
                    oper.push(exp[i]);
                }
                else if (Priority(exp[i], oper.top())) {//помещаем оператор o1 в стек.
                    oper.push(exp[i]);
                }
                else {
                    convertStr += oper.top();
                    oper.pop();
                    oper.push(exp[i]);
                }
            }
            else if (exp[i] == ')') {
                while (oper.top() != '(') {
                    convertStr += oper.top();
                    oper.pop();
                }
                if (oper.top() == '(') { oper.pop();}
            }
           
        }
            while (!oper.empty()) {
                convertStr += oper.top();
                oper.pop();
            }
        return convertStr;
    }

    double Evaluate(string str) {
        int a=0, b=0;
        stack<int>stack;
        for (size_t i = 0;i < str.length();i++) {
             if (isdigit(str[i])) {
                 stack.push(str[i] - 48);
             }
             else if (str[i] == '+') {
                 a = stack.top();
                 stack.pop();
                 b = stack.top();
                 stack.pop();
                 stack.push(a + b);
             }
             else if (str[i] == '-') {
                 a = stack.top();
                 stack.pop();
                 b = stack.top();
                 stack.pop();
                 stack.push(b-a);
             }
             else if (str[i]=='*') {
                 a = stack.top();
                 stack.pop();
                 b = stack.top();
                 stack.pop();
                 stack.push(a*b);
             }
             else if (str[i]=='/') {
                 a = stack.top();
                 stack.pop();
                 b = stack.top();
                 stack.pop();
                 stack.push(b/a);
             }
         }
        return stack.top();
    }
    
};
int main()
{
    string Expression="";
    string PostExpression="";
    
    getline(cin, Expression);
    Calculator equ(Expression);
  
    PostExpression = equ.GetExpression();
    cout << PostExpression<<endl;
    double result=equ.Evaluate(PostExpression);

    cout << result<<endl;
   
}