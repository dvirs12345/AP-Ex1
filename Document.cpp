//Author - Dvir Sadon
#include "Document.h"
#include <iostream>
#include <fstream>

Document::Document()
{
    std::vector<std::string> doc;
    this->current = 0;
    this->doc = doc;
}

Document::Document(std::vector<std::string> doc)
{
    this->current = 0;
    this->doc = doc;
}

void Document::addline(string line)
{
    this->doc.emplace(this->doc.begin()+this->current,line);
    this->current++;
}

void Document::numbermove(int num)
{
    if((this->doc.size() <= num || num < 0) && num != 0)
        cout << "?" << endl;
    else
        this->current = num;
}

void Document::plus(int num)
{
    if(num+this->current > this->doc.size())
        cout << "?" << endl;
    
    else
        this->current = this->current+num;
}

void Document::minus(int num)
{
    if(this->current-num <= 0)
        cout << "?" << endl;
    
    else
        this->current = this->current-num;
}

void Document::dollar()
{
    this->current = this->doc.size()-1;
}

void Document::ain()
{
    string x;
    getline(cin, x);
    cout << this->current << endl;
    while(x.compare(".") != 0)
    {
        if(!x.empty())
            this->addline(x);
        getline(cin, x);
    }
}

void Document::iin()
{
    string x;
    getline(cin, x);

    while(x.compare(".") != 0)
    {
        if(this->current == 0 && !x.empty())
            this->addline(x);
        else
        {
            if(this->current > 0)
                this->current--;
            if(!x.empty())
                this->addline(x);
        }
        
        this->current++;
        getline(cin, x);
    }

    if(this->current>=this->doc.size())
        this->current--;
}

void Document::cin1()
{
    this->din();
    this->ain();
}

void Document::din()
{
    this->doc.erase(this->doc.begin() + this->current);
    this->current--;
}

void Document::slashtext(string text)
{
    bool flag = false;
    for(vector<string>::iterator nth = this->doc.begin() + this->current; nth != this->doc.end(); ++nth) // From current till the end
    {
        if((*nth).find(text) != string::npos)
        {
            flag = true;
            current = nth-this->doc.begin();
            break;
        }
    }
        
    if(!flag) // Did not find in the first loop
    {
        for(vector<string>::iterator nth = this->doc.begin(); nth != this->doc.begin() + this->current; ++nth)// From start to current
        {
            if((*nth).find(text) != string::npos)
            {
                flag = true;
                this->current = nth-this->doc.begin();
                break;
            }
        }
    }
}

void Document::substitute(string old, string newone)
{
    // auto myindex = this->doc[this->current].find(old, 0);
    newone = newone.substr(0, newone.size()-1);
    this->doc.at(this->current).replace(this->doc.at(this->current).find(old), old.size(), newone);       
}

void Document::jin()
{
    string nextone = this->doc[this->current+1];
    this->doc[this->current] = this->doc[this->current] + " " + nextone; 
    // Remove the next row?!
    this->current++;
    this->din();
}

void Document::writetofile(string filename)
{
    std::ofstream f(filename);
    for(vector<string>::const_iterator i = this->doc.begin(); i != this->doc.end(); ++i)
        f << *i << '\n';
}

void Document::quit()
{
    exit(EXIT_SUCCESS);
}

    