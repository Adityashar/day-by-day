#include<iostream>
#include<vector>
#include "strategy/context.h"
using namespace std;


int main() {

    printf("Client: Initialising the client for 'Sorting Strategy' Example.. \n");

    printf("Client: Initialising the SortingContext with MergeSortStrategy\n");
    SortingContext ctx(new MergeSortStrategy());
    
    vector<int> dummy = {3,4,1,2,5};

    ctx.sorting->sort(dummy);

    ctx.SetSortingContext(new SelectionSortStrategy());
    ctx.GetSortingContext();
    ctx.sorting->sort(dummy);
    
    ctx.SetSortingContext(new BubbleSortStrategy());
    ctx.GetSortingContext();
    ctx.sorting->sort(dummy);

    return 0;
}