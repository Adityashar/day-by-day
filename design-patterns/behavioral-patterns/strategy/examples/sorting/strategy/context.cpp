#include<iostream>
#include<string>
#include "context.h"
#include "sorting.h"

using namespace std;

void SortingContext::SetSortingContext(SortingStrategy *input) {
        this->sorting = input;
        printf("Context: Updated context to %s..\n", input->name.c_str());
    }

string SortingContext::GetSortingContext() {
    return this->sorting->name;
}
