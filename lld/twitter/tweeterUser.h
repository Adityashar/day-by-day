#pragma once

#include <vector>
#include "tweet.h"
#include "user.h"

using namespace std;

class TwitterUser: public User {
    int userId;

    vector<Tweet*> tweets;
    unordered_map<int, User*> followingsMap;
    unordered_map<int, User*> followersMap;

    FeedGeneratorStrategy *generator;
public:
    TwitterUser(int id, int _size): userId(id), User(_size) {
        generator = new MostRecentTweetsStrategy(_size);
    }

    void tweet(Tweet *tweet) {
        tweets.push_back(tweet);
        refreshFeed(tweet); // update my feed and my followers feed
    }

    void follow(User *user) {
        followingsMap[user->userId] = user;
        user->followersMap[userId] = this;
        refreshFeed(followingsMap);
    }

    void unFollow(User *user) {
        followingsMap.erase(user->userId);
        
        refreshFeed(followingsMap);
    }

    void refreshFeed() {
        generator.generate(tweets, followingsMap);
    }

    virtual vector<int> viewFeed() {
        return generator.view();
    } 
}