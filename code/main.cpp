#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{   
    std::cout << "Hello, World! \n";
    std::ofstream txtFile(argv[1]);
    
    for (int i = 2; i < argc; i++)
    {
        txtFile << argv[i] << " ";
    }


    return 0;
}