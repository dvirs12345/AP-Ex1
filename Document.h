//Author - Dvir Sadon
#pragma once
#include <string>
#include <vector>
using namespace std;

class Document
{
    public:

        /* Variables */
        std::vector<std::string> doc; // The document vector.
        int current; // The current place we are looking at in the vector. 

        /* Constructors */
        Document();
        Document(std::vector<std::string> doc);

        /* Functions */
        void addline(string line);

        void numbermove(int num);

        void plus(int num);

        void minus(int num);

        void dollar();

        void ain();

        void iin();

        void cin1();

        void din();

        void slashtext(string text);

        void substitute(string old, string newone);

        void jin();

        void writetofile(string filename);

        void quit();
};