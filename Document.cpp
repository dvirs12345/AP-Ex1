//Author - Dvir Sadon
#include "Document.h"
#include <iostream>
#include <fstream>

Document::Document()
{
    std::vector<std::string> doc;
    this->current=0;
    this->doc = doc;
}

Document::Document(std::vector<std::string> doc)
{
    this->current = 0;
    this->doc = doc;
}

void Document::addline(string line)
{
    ;
}

void Document::numbermove(int num)
{
    if(this->doc.size() <= num || num == 0)
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
    cin >> x;

    while(x.compare(".") != 0)
    {
        this->addline(x);
        cin >> x;
    }
}

void Document::iin()
{
    ;
}

void Document::cin1()
{
    ;
}

void Document::din()
{
    this->doc.erase(this->doc.begin() + this->current);
    // What is the currnt place after removing?
    //this->current-=1;
}

void Document::slashtext(string text)
{
    bool flag = false;
    for(vector<string>::iterator nth = this->doc.begin() + this->current; nth != this->doc.end(); ++nth) // From current till the end
    {
        if((*nth).compare(text) == 0)
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
            if((*nth).compare(text) == 0)
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
    auto myindex = this->doc[this->current].find(old, 0);
    this->doc[this->current].replace(myindex, old.length(), newone);        
}

void Document::jin()
{
    string nextone = this->doc[this->current+1];
    this->doc[this->current] = this->doc[this->current] + " " + nextone; 
    // Remove the next row?!
    // this->current+=1;
    // this->din();
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

    