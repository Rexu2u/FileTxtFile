#include <iostream>
#include <fstream>
#include <string.h>

#define VERSION "v.0.0 - RELEASE"
#define ALPHA
#ifdef ALPHA
int main(int argc, char** argv)
{
    std::cout << VERSION << " (x64_86-pc) \n Welcome!, To FileTXTFile. \n please use it with responsibility <3 \n";
    std::fstream oFile;
    oFile.exceptions(std::ios::goodbit | std::ios::eofbit);
    if (argc < 2) 
    {
        std::cout << "please pass arg1 = PATH, arg..x == Contents \n";      exit( EXIT_FAILURE);
    }

    oFile.open(argv[1], std::ios::out | std::ios::binary);
    
    if (oFile.fail())
    {
        std::cout << "Failed to read and create file! something went wrong :(";     exit( EXIT_FAILURE);
    }

    std::string contents;

    for (int i = 2; i < argc; i++)
    {

        if (strcmp(argv[i], "\\n") == 0)
        {
            contents.append("\n");
        }
        else{

            contents.append(argv[i]);
            contents.append(" ");
        }
    }
    oFile << contents;

    oFile.close();


    return EXIT_SUCCESS;
}
#endif
