/*======================================================================
*        filename: strquote.cpp
*        author: rambogui
*        data: 2018-11-30 14:37:57
======================================================================*/

#include <iostream>
#include <string>
using namespace std;
string version1(const string &s1, const string &s2);
const string &version2(string &s1, const string &s2);
const string &version3(string &s1, const string &s2);

void foo(string &str);

int main(int argc, char *argv[])
{
    string input;
    string copy;
    string result;

    cout << "Enter a string: ";
    getline(cin, input);
    cout << "Your string as entered: " << input << endl;
    result = version1(input, "***");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    result = version2(input, "###");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    cout << "Resetting original string.\n";
    input = copy;
    result = version3(input, "@@@");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    //foo("I am rambo");

    return 0;
}

string version1(const string &s1, const string &s2)
{
    string temp;
    temp = s2 + s1 + s2;
    return temp;
}

const string &version2(string &s1, const string &s2)
{
    s1 = s2 + s1 + s2;
    return s1;
}

const string &version3(string &s1, const string &s2)
{
    string temp;
    temp = s2+s1+s2;
    return temp;
}

void foo(string &str)
{

}
