#include"evaluate.hpp"

Calculator::Calculator(string Expression) :exp(Expression) {};

int Calculator::lenght(int t) {
    int count = 0;
    while (t != 0) {
        t /= 10;
        count++;
    }
    return count;
}

bool Calculator::Priority(char a, char b) {
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

string Calculator::GetExpression() {
    string convertStr = "";
    stack<char>oper;
    for (size_t i = 0;i < exp.length();i++) {
        if (isdigit(exp[i])) {
            convertStr += exp[i];
            while (isdigit(exp[++i])) {
                convertStr += exp[i];
            }
            convertStr += " ";
            --i;
        }
        else if (exp[i] == '(') {
            oper.push(exp[i]);
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*') {
            if (oper.empty() || oper.top() == '(') {
                oper.push(exp[i]);
            }
            else if (Priority(exp[i], oper.top())) {
                oper.push(exp[i]);
            }
            else {
                convertStr += oper.top();
                convertStr = " ";
                oper.pop();
                oper.push(exp[i]);
            }
        }
        else if (exp[i] == ')') {
            while (oper.top() != '(') {
                convertStr += oper.top();
                convertStr += " ";
                oper.pop();
            }
            if (oper.top() == '(') { oper.pop(); }
        }

    }
    while (!oper.empty()) {
        convertStr += oper.top();
        convertStr += "";
        oper.pop();
    }

    return convertStr;
}
double Calculator::Evaluate(string str) {
    int a = 0, b = 0, t = 0;
    stringstream ss;
    ss << str;
    stack<int>stack;
    for (size_t i = 0;i < str.length();i++) {
        if (isdigit(str[i])) {
            ss >> t;
            i = i + lenght(t);
            stack.push(t);

        }
        if (str[i] == ' ') {
            ;
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
            stack.push(b - a);
        }
        else if (str[i] == '*') {
            a = stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();
            stack.push(a * b);
        }
        else if (str[i] == '/') {
            a = stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();
            stack.push(b / a);
        }
    }
    return stack.top();
}

