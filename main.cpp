//Author - Dvir Sadon
#include "Editor.h"

int main(int argc, char* argv[])
{
    editor myeditor;
    cout << argc << endl;
    switch (argc) 
    {
        case 1: // If no vars passed
            myeditor = editor();
            break;    

        case 2: // If passed filename
            std::string filename(argv[1]);
            //cout << filename << endl;
            myeditor = editor(filename);
            break;
    }

    myeditor.loop();
    return 0;
}