#include"evaluate.hpp"
using namespace std;
int main()
{
    string Expression = "";
    string PostExpression = "";
    int t=0, k = 0;
;
   getline(cin, Expression);
    Calculator equ(Expression);
    PostExpression = equ.GetExpression();
    cout << PostExpression << endl;
    double result = equ.Evaluate(PostExpression);

    cout << result << endl;

}