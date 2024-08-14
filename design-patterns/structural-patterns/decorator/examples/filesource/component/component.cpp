#include<iostream>
#include "component.h"

using namespace std;


string FileComponent::read() {
    printf("Reading: FileName = '%s', FileData = '%s'\n", this->fileName.c_str(), this->data.c_str());
    return data;
}

void FileComponent::write(string data) {
    printf("Writing: FileName = '%s', FileData = '%s'\n", this->fileName.c_str(), data.c_str());
    this->data = data;
}