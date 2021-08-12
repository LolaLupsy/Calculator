#include"evaluate.hpp"

Calculator::Calculator(string Expression) :terms(Expression) {};

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
    else if (a == '^')aW = 3;
    else  aW = 1;
    if (b == '*' || b == '/') {
        bW = 2;
    }
    else if (b == '^')bW = 3;
    else bW = 1;
    return aW >= bW;

}

double Calculator::Sinus(string str) {
    string postStr = GetExpression(str);
    double inteRes = Evaluate(postStr);
    double sinus = sin(inteRes*PI/180);
    return sinus;
}

double Calculator::Cosnus(string str) {
    string postStr = GetExpression(str);
    double inteRes = Evaluate(postStr);
    double cosnus = cos(inteRes * PI / 180);
    return cosnus;
}

double Calculator::Tangens(string str) {
    string postStr = GetExpression(str);
    double inteRes = Evaluate(postStr);
    double tangens = tan(inteRes * PI / 180);
    return tangens;
}

double Calculator::Radical(string str) {
    string postStr = GetExpression(str);
    double inteRes = Evaluate(postStr);
    double sq = sqrt(inteRes);
    return sq;
}

double Calculator::Ln(string str) {
    string postStr = GetExpression(str);
    double inteRes = Evaluate(postStr);
    double ln = log(inteRes);
    return ln;
}

double Calculator::Lg(string str) {
    string postStr = GetExpression(str);
    double inteRes = Evaluate(postStr);
    double lg = log10(inteRes);
    return lg;
}

double Calculator::Exponenta(string str) {
    string postStr = GetExpression(str);
    double inteRes = Evaluate(postStr);
    double expon = exp(inteRes);
    return expon;
}

string Calculator::First() {
    string newExp = "";
    string medium = "";
    string inter1 = "";
    string st = "";
    string power = "";
    stringstream ss;
    char step,step2;
    double inter = 0;
    for (size_t i = 0;i < terms.length();i++) {
        if (terms[i] == 's' || terms[i] == 'c' || terms[i] == 'l'||terms[i]=='t'||terms[i]=='e') {
        step = terms[i];
        step2 = terms[i + 1];
        while (terms[++i] >= 97 && terms[i] <= 122) ;
            if (terms[i] == '(') {
                while (terms[++i] != ')') { medium += terms[i]; }
            }
            switch (step) {
                case 's':
                {
                    if (step2 == 'i')
                        inter = Sinus(medium);
                    if (step2 == 'q') inter=Radical(medium);
                }
                    break;
                case 'c':
                {
                    if (step2 == 'o') inter = Cosnus(medium);
                    if (step2 == 't') inter = 1/Tangens(medium);

                }
                    break;
                case 'l':
                {
                    if (step2 == 'n') inter = Ln(medium);
                    if (step2 == 'g') inter = Lg(medium); 
                }
                    break;
                case 't': 
                {
                    inter = Tangens(medium);
                }
                    break;
                case 'e':
                {
                    inter = Exponenta(medium);
                }
                default:
                    break;
                }
              ss << inter;
              ss >> inter1;
              newExp += inter1;
              ss.str("");
              inter1="";
    
        } /*
else  if (terms[i] == '^') {
            newExp += terms[i];    
            if (terms[++i] == '(') {
                while (terms[++i] != ')') { medium += terms[i]; }
            }
            power = GetExpression(medium);
            inter = Evaluate(power);
            ss << inter;
            ss >> inter1;
            newExp += inter1;
            ss.str("");
            inter1 = "";
        }*/
        else {
            newExp += terms[i];
        }
    }
    return newExp;//получу строку только с числами и операторами
}

string Calculator::GetExpression(string exp) {//функция преобразует в постфиксное 
    string convertStr = "";
    stack<char>oper;
    for (size_t i = 0;i < exp.length();i++) {
        if (isdigit(exp[i])) {
            convertStr += exp[i];
            while (isdigit(exp[++i])||exp[i]=='.') {
                convertStr += exp[i];
            }
            convertStr += " ";
            --i;
        }
        else if (exp[i] == '(') {
            oper.push(exp[i]);
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*'||exp[i]=='^') {
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

    return convertStr;//получаю конвертируемую строку (постфиксное выражение)
}

double Calculator::Evaluate(string str) { // считается постфиксное выражение
    double a = 0.0, b = 0.0, t= 0.0;
    string len;
    stringstream ss;
    stringstream tt;
    ss << str;
    stack<double>stack;
    for (size_t i = 0;str[i]!='\0';i++) {
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
            stack.push(b-a);
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
        else if (str[i] == '^') {
            a = stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();
            stack.push(pow(a, b));
        }
    }
    return stack.top();//получаю результат
}