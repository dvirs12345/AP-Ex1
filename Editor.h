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
        void file_to_vector();

    private:
        void handleLetters(char first, std::string x);
        bool getFileContent(std::string fileName);
};
