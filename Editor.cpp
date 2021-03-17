//Author - Dvir Sadon
#include "Editor.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

editor::editor()
{
    Document newdocument; 
    this->myDocument = newdocument;
}

editor::editor(string filename)
{
    Document newdocument = Document(); 
    this->myDocument = newdocument;
    getFileContent(filename);
}

bool editor::getFileContent(std::string fileName)
{
    std::ifstream in(fileName.c_str());
    if(!in)
        return false;

    std::string str;
    while(std::getline(in, str))
        if(str.size() > 0)
            this->myDocument.doc.push_back(str);

    in.close();
    return true;
}

void editor::loop()
{
    while(true)
    {
        std::string x;
        std::cin >> x;

        char first = x[0];
        string withoutfirst = x.substr(1);
        regex slash(R"/(.*)/");
        regex sub(R"/(.*)/(.*)/");
        regex filewrite("[w]\\s(.*)");
        smatch mymatches;
        switch(first)
        {
            case '+':
                if(is_number(withoutfirst))
                    this->myDocument.plus(stoi(withoutfirst));
                else
                    cout << "?" << endl;
                break;

            case '-':
                if(is_number(withoutfirst))
                    this->myDocument.minus(stoi(withoutfirst));
                else
                    cout << "?" << endl;
                break;

            case '$':
                if(x.length() == 1)
                    this->myDocument.dollar();
                else 
                    cout << "?" << endl;
                break;

            case 'a':
                if(x.length() == 1)
                    this->myDocument.ain();
                else
                    cout << "?" << endl;
                break;

            case 'i':
                if(x.length() == 1)
                    this->myDocument.iin();
                else
                    cout << "?" << endl;
                break;

            case 'c':
                if(x.length() == 1)
                    this->myDocument.cin1();
                else
                    cout << "?" << endl;
                break;

            case 'd':
                if(x.length() == 1)
                    this->myDocument.din();
                else
                    cout << "?" << endl;
                break;

            case '/':
                if(regex_match(x, mymatches, slash))
                    this->myDocument.slashtext(mymatches.str(1));
                else
                    cout << "?" << endl;
                break;

            case 's':
                if(regex_match(x, mymatches, sub))
                    this->myDocument.substitute(mymatches.str(1), mymatches.str(2));
                else 
                    cout << "?" << endl;
                break;

            case 'j':
                if(x.length() == 1)
                    this->myDocument.jin();
                else 
                    cout << "?" << endl;
                break;

            case 'w':
                if(regex_match(x, mymatches, filewrite)) 
                    this->myDocument.writetofile(mymatches.str(1));
                else 
                    cout << "?" << endl;
                break;

            case 'q':
                if(x.length() == 1)
                    this->myDocument.quit();
                else
                    cout << "?" << endl;
                break;
                
            default:
                if(is_number(x))
                    this->myDocument.numbermove(stoi(x));
                else
                    cout << "?" << endl;
                break;
        }
    }
}
bool editor::handleLetters(char first, std::string x)
{
    if(x.length()>1)
    {
        this->myDocument.doc.push_back(x);
        return true;
    }
    return false;
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
