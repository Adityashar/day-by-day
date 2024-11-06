#include <iostream>
#include "iterator/iterator.h"
#include "collection/collection.h"

using namespace std;


// Driver Code
int main () {

    ICollection *org = new OrganisationCollection();

    /*
                             ABC
                DFC          FDC         DFE
            FHG     FGA  GBC    GBA
                    FHE
    
    
    */

    org->add("ABC", "ABC");
    org->add("DFC", "ABC");
    org->add("FDC", "ABC");
    org->add("DFE", "ABC");
    org->add("FHG", "DFC");
    org->add("FGA", "DFC");
    org->add("FHE", "FGA");
    org->add("GBC", "FDC");
    org->add("GBA", "FDC");
    
    IIterator *iterable = org->getIterator();

    while (iterable->hasNext()) {
        PersonObject *p = iterable->next();

        cout<<p->getName()<<" "<<p->getParent()<<endl;
    }

    return 0;
}