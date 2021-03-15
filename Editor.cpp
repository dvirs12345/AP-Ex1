//Author - Dvir Sadon
#include "Editor.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iostream>
using namespace std;

editor::editor()
{
    Document newdocument; 
    this->myDocument = newdocument;
}

editor::editor(string filename)
{
    
}

bool editor::getFileContent(std::string fileName)
{
    std::ifstream in(fileName.c_str());
    if(!in)
        return false;

    std::string str;
    while (std::getline(in, str))
        if(str.size() > 0)
            this->myDocument.doc.push_back(str);
            
    in.close();
    return true;
}

void editor::loop()
{
    std::string x;
    std::cin >> x;

    char first = x[0];
    switch(first)
    {
        case '+':
            break;
        case '-':
            break;
        case '$':
            break;
        case 'a':
            // if(len>1)
            break;
        case 'i':
            // if(len>1)
            break;
        case '.':
            break;
        case 'c':
            break;
        case 'd':
            // if(len>1)
            break;
        case '/':
            break;
        case 's':
            // if(len>1)
            break;
        case 'j':
            // if(len>1)
            break;
        case 'w':
            // if(len>1)
            break;
        case 'q':
            // if(len>1)
            break;
        default:
            // if(number)
            // else if (string)
            // else
            ;
    }
}
void handleLetters(char first, std::string x)
{
    if(x.length()>1)
    {
        ;
    }
}

