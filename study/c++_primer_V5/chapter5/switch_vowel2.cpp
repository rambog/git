/*======================================================================
*        filename: switch_vowel2.cpp
*        author: rambogui
*        data: 2018-12-20 21:38:02
======================================================================*/

#include <iostream>

int main(int argc, char *argv[])
{
    char ch;
    unsigned vowelCnt = 0, otherCnt = 0;
    
    while (std::cin >> ch) {
        switch (ch) {
            case 'a': case 'e' : case 'i' : case 'o' : case 'u':
                ++vowelCnt;
                break;
            default:
                ++otherCnt;
                break;
        }
    }

    std::cout << "Number of vowel: " << vowelCnt << std::endl;
    std::cout << "Number of other: " << otherCnt << std::endl;

    return 0;
}
