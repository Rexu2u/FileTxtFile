#include <iostream>
#include <fstream>
#include <string.h>

#define VERSION "v.0.0 - RELEASE"

enum mode {OUTPUT, HELP, EXIT};

inline void HandleShowVersion();
inline void ARGCGREATERTHANTWO(bool& check);
inline void HandleMode(mode& mode);
inline void HelpMessage();
inline int GenerateOutputFile();

void StoreInput2Contents(std::string& contents);
bool OpenFile(std::fstream& toOpen, char* path);
mode CheckInputMode();


int main(int argc, char** argv)
{
    mode settedMode = CheckInputMode();

    HandleMode(settedMode);
    return EXIT_SUCCESS;
}

mode CheckInputMode() {
    if (strcmp(__argv[1], "help") == 0)
    {
        return mode::HELP;
    }
    if (strcmp(__argv[1], "exit") == 0)
    {
        return mode::EXIT; 
    }
    return mode::OUTPUT;
}

void StoreInput2Contents(std::string& contents)
{
    for (int i = 2; i < __argc; i++)
    {
        if (strcmp(__argv[i], "\\n") == 0)
        {
            contents.append("\n");
        }
        else {
            std::cout << "Bleh";
            contents.append(__argv[i]);
            contents.append(" ");
        }
        
    }
    
}

inline int GenerateOutputFile()
{
    std::string  contents;
    std::fstream oFile;
    if (OpenFile(oFile, __argv[1]) == 1)
    {
        std::cerr << "Error on opening the output file! \n";
        return 0;
    };

    StoreInput2Contents(contents);
    oFile << contents;
    oFile.close();

    std::cout << "Program closed with no bullshits \n";
    return 1;
}

bool OpenFile(std::fstream& toOpen, char* path)
{
    bool check;
    ARGCGREATERTHANTWO(check);
    toOpen.exceptions(std::ios::goodbit | std::ios::eofbit);

    try {
        toOpen.open(path, std::ios_base::out);
    }
    catch (int ee)
    {
        check = 1;   
    }
    return check;
}

inline void HandleShowVersion()
{
    std::clog << VERSION << " (x64_86-pc) \n Welcome!, To FileTXTFile. \n please use it with responsibility <3 \n";
}

inline void ARGCGREATERTHANTWO(bool& check)
{
    if (__argc < 2) 
    {
        std::cerr << "please pass arg1 = PATH, arg..x == Contents \n";     
        check = 1;
    }
}

inline void HelpMessage()
{
    std::cout << "\"help\" - Superly useful guide manual for newbies. \n"
                  "\"exit\" - Terminates the program (Very very good feature). \n" 
                  "\"argv[1] Path of txt format, argv[...] contents \" - First paramater lets you creates or overwrite an txt file. next parameter \n";
}

inline void HandleMode(mode& themode)
{
    switch (themode)
    {
        case mode::EXIT: exit(EXIT_SUCCESS); break;
        case mode::HELP: HelpMessage(); break;
        case mode::OUTPUT: 
            if (GenerateOutputFile() == 1)
            {
                std::cerr << "Error on output file! \n";
            }
         break;
    }
}