/*======================================================================
*        filename: switch1.cpp
*        author: rambogui
*        data: 2018-12-20 21:25:19
======================================================================*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    std::string linestr;

    getline(std::cin, linestr);
    std::string::const_iterator iter = linestr.begin();

    while (iter != linestr.end()) {
        switch (*iter++) {
            case 'a':
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'i':
            case 'I':
                ++iCnt;
                break;
            case 'o':
            case 'O':
                ++oCnt;
                break;
            case 'u':
            case 'U':
                ++uCnt;
                break;
            default:
                break;
        }
    }

    std::cout << "Number of vowel a: \t" << aCnt << std::endl;
    std::cout << "Number of vowel e: \t" << eCnt << std::endl;
    std::cout << "Number of vowel i: \t" << iCnt << std::endl;
    std::cout << "Number of vowel o: \t" << oCnt << std::endl;
    std::cout << "Number of vowel u: \t" << uCnt << std::endl;
    return 0;
}
