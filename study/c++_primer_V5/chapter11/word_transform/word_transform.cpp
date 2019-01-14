/*======================================================================
*        filename: word_transform.cpp
*        author: rambogui
*        data: 2019-01-11 08:48:36
======================================================================*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <stdexcept>
#include <exception>
#include <fstream>
#include <sstream>

using std::string;
using std::map;
using std::set;
using std::endl;
using std::cout;
using std::cin;
using std::ifstream;
using std::pair;
using std::istringstream;

map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map;
    string key;
    string value;

    while (map_file >> key && getline(map_file, value))
        if (value.size() > 1)
            trans_map[key] = value.substr(1);
        else
            throw std::runtime_error("no rule for " + key);
    
    return trans_map;
}

const string &
transform(const string &s, const map<string, string> &m)
{
    map<string, string>::const_iterator map_it = m.find(s); 
    if (map_it != m.cend())
        return map_it->second;
    else
        return s;
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input, text)) {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word) {
            if (firstword)
                firstword = false;
            else
                cout << " ";
            
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{

    return 0;
}
