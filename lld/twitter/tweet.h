#pragma once

class Tweet {
    int id;
    int timestamp;
public:
    Tweet(int _id, int _time): id(_id), timestamp(_time) {}

    int getId() { return id; }
    int getTime() { return timestamp; }
};