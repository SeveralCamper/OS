#include <iostream>
#include <fstream>

int main() {
    std::fstream fout;
    fout.open("info.txt");
    fout << system("whoami >> info.txt");
    fout.close();
    
    return 0;
}