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
    {
        if(str.size() > 0)
        {
            this->myDocument.doc.push_back(str);
        }
    }

    this->myDocument.dollar();
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
        
        string withoutfirst = x.substr(1, x.size());
        string twowordsdivided;
        string oldword;
        string newWord;
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
                this->myDocument.slashtext(x.substr(1, x.size()-2));
                break;

            case 's':
                twowordsdivided = x.substr(2, x.size()-2);
                oldword = twowordsdivided.substr(0, twowordsdivided.find("/"));
                newWord = twowordsdivided.substr(twowordsdivided.find("/")+1, twowordsdivided.size()-2);
                this->myDocument.substitute(oldword, newWord);
                break;

            case 'j':
                if(x.length() == 1)
                    this->myDocument.jin();
                else 
                    cout << "?" << endl;
                break;

            case 'w':
                if(!x.empty())
                {
                    string name;
                    cin >> name;
                    this->myDocument.writetofile(name);
                }
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
                    this->myDocument.numbermove(stoi(x)-1);
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

bool editor::is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
