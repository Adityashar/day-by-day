#include<iostream>
#include<vector>
#include "sorting.h"

using namespace std;


void SelectionSortStrategy::sort(vector<int> &input) {
    printf("Strategy: Sorting with %s..\n", this->name.c_str());
}

void BubbleSortStrategy::sort(vector<int> &input) {
    printf("Strategy: Sorting with %s..\n", this->name.c_str());
}
