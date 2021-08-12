#include"evaluate.hpp"
#include<cmath>
using namespace std;
int main()
{
  string Expression = "2+54";
  string PostExpression = "";

  // getline(cin, Expression);
   Calculator equ(Expression);
   Expression = equ.First();
   PostExpression = equ.GetExpression(Expression);
   double result = equ.Evaluate(PostExpression);
   cout << PostExpression << endl;
   cout << result << endl;
}