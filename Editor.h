//Author - Dvir Sadon
#pragma once
#include "Editor.h"
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

class editor
{
    public:
        void loop();

    private:
        void handleLetters(char first, std::string x);
};
