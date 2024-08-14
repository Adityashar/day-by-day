#pragma once
#ifndef SORTING_H_
#define SORTING_H_

using namespace std;

// Sorting Strategy Interface
class SortingStrategy {
public:
    string name;
    virtual void sort(vector<int> &input) = 0;
    virtual ~SortingStrategy() {}
};


///////////////////////////
///////////////////////////


// Selection Sort Strategy
class SelectionSortStrategy: public SortingStrategy {
public:
    SelectionSortStrategy() {
        this->name = "Selection";
    }
    void sort(vector<int> &input);
};


// Bubble Sort Strategy
class BubbleSortStrategy: public SortingStrategy {
public:
    BubbleSortStrategy() {
        this->name = "Bubble";
    }
    void sort(vector<int> &input);
};


// Merge Sort Strategy
class MergeSortStrategy: public SortingStrategy {
public:
    MergeSortStrategy() {
        this->name = "Merge";
    }
    void sort(vector<int> &input) {
        printf("Strategy: Sorting with %s..\n", this->name.c_str());
    }
};

#endif