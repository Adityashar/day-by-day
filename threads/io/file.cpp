#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


string read() {
    fstream fio;
    string line;
    string output;

    fio.open("input/doesNotExist1.txt", ios::in); 
    while (fio) {
        getline(fio, line);
        cout << line << endl;
        output += line + '\n';
    }

    fio.close();

    return output;
}


void write() {
    fstream fio;
    string line;

    fio.open("output/out1.txt", ios::trunc | ios::out);
    if (!fio)
        throw "Bad File";
    
    stringstream ss(read());

    while (getline(ss, line, '\n')) {
        fio << line << endl;
    }

    fio.close();
}


int main() {
    write();
}