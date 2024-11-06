



class FeedGeneratorStrategy {
public:
    virtual void generate() = 0;
    virtual vector<int> view() = 0;
};

class MostRecentTweetsStrategy {
    queue<int> feed;
    int maxSize;
public:
    MostRecentTweetsStrategy(int _size): maxSize(_size) { }

    virtual void generate() {

    }

    virtual vector<int> view() {

    }
};



class Twitter {
    int feedSize;
    long time;

    unordered_map<int, User*> users;
public:
    Twitter() {
        feedSize = 10, time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;

        if (users.find(userId) == users.end()) {
            users[userId] = new TwitterUser(userId, feedSize);
        }

        users[userId].tweet(new Tweet(tweetId, time));
    }
    
    vector<int> getNewsFeed(int userId) {
        time++;
        return users[userId].viewFeed();
    }
    
    void follow(int followerId, int followeeId) {
        time++;
        if (users.find(followeeId) == users.end()) {
            users[followeeId] = new TwitterUser(followeeId, feedSize);
        }
        
        users[followerId].follow(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        time++;
        if (users.find(followeeId) == users.end()) {
            return;
        }
        
        users[followerId].unFollow(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */