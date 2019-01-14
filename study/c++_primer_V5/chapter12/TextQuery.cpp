/*======================================================================
*        filename: TextQuery.cpp
*        author: rambogui
*        data: 2019-01-14 16:05:57
======================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <map>
#include <set>

using std::string;
using std::vector;
using std::shared_ptr;
using std::map;
using std::set;
using std::ifstream;
using std::istringstream;
using std::ostream;
using std::endl;
using std::cout;
using std::cin;

class QueryResult;
class TextQuery {
public:
    typedef vector<string>::size_type line_no;
    TextQuery(ifstream &);
    QueryResult query(const std::string &) const;

private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
    string text;
    while (getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word) {
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult
TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

class QueryResult {
friend ostream& print(ostream &, const QueryResult &);
public:
    QueryResult(string &, shared_ptr<set<TextQuery::line_no>> p,
        shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) { }
private:
    string sought;
    shared_ptr<set<QueryResult::line_no>> lines;
    shared_ptr<vector<string>> file;
};

ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " ";

    for (auto num : *qr.lines) 
        os << "\t(line " << num + 1 << ")"
            << *(qr.file->begin() + num) << endl;
    return os;
}

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);

    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}

int main(int argc, char *argv[])
{

    return 0;
}
