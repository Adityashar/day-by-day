#pragma once

#include <vector>

class User {
    int feedSize;
public:
    User(int size): feedSize(size) { }
    void setFeedSize(int size) { feedSize = size; }

    virtual std::vector<int> viewFeed() = 0;
};