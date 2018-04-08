#ifndef lpclib_utility_h
#define lpclib_utility_h
#include <string>
using namespace std;

void Pause(double seconds);
string IntToString(int num);
string DoubleToString(double num);
int StringToInt(string str);
double StringToDouble(string str);
string ConvertToLowercase(string str);
string ConvertToUppercase(string str);
void Error(string msg);

#endif /* lpclib_utility_h */
