#pragma once
#include <iostream>
#include<stack>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif


extern const double PI = 3.141592653589793238463;

extern "C" MATHLIBRARY_API int len(string t);
extern "C" MATHLIBRARY_API bool Priority(char a, char b);
extern "C" MATHLIBRARY_API   double Evaluate(string str);
extern "C" MATHLIBRARY_API   string GetExpression(string exp);
extern "C" MATHLIBRARY_API string First(string terms);
extern "C" MATHLIBRARY_API   double Sinus(string str);
extern "C" MATHLIBRARY_API  double Cosnus(string str);
extern "C" MATHLIBRARY_API  double Tangens(string str);
extern "C" MATHLIBRARY_API  double Radical(string str);
extern "C" MATHLIBRARY_API  double Ln(string str);
extern "C" MATHLIBRARY_API  double Lg(string str);
extern "C" MATHLIBRARY_API  double Exponenta(string str);
    // double Exponentiation(string str);


//extern "C" MATHLIBRARY_API int neg(int a);
//extern "C" MATHLIBRARY_API int fuct(int a);