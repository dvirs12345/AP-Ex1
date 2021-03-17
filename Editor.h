//Author - Dvir Sadon
#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
#include "Document.h"
using namespace std;

class editor
{
    public:
        /* Variables */
        Document myDocument;

        /* Constructors */
        editor();
        editor(string filename);

        /* Functions */
        void loop();
        // void file_to_vector(std::string fileName);

    private:
        bool handleLetters(char first, std::string x);
        bool getFileContent(std::string fileName);
        bool is_number(const std::string& s);
};
