class Twitter {
private:
    // userId -> tweets
    // Each tweet is {timestamp, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweets;

    // follower -> people they follow
    unordered_map<int, unordered_set<int>> following;

    int timestamp = 0;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
        
    }
    
    vector<int> getNewsFeed(int userId) {
        // max heap:
        // {timestamp, tweetId, userId, index}
        priority_queue<tuple<int, int, int, int>> pq;

        // The user's own tweets
        if(!tweets[userId].empty()) {
            int index = tweets[userId].size() - 1;
            auto [time, tweetId] = tweets[userId][index];
            pq.push({time, tweetId, userId, index});
        }

        // tweets from people the user follows
        for (int followeeId : following[userId]) {
            if(!tweets[followeeId].empty()) {
                int index = tweets[followeeId].size() - 1;
                auto[time, tweetId] = tweets[followeeId][index];
                pq.push({time, tweetId, followeeId, index});
            }
        }

        vector<int> result;
        while(!pq.empty() && result.size() < 10) {
            auto[time, tweetId, user, index] = pq.top();
            pq.pop();

            result.push_back(tweetId);
            // Move to the next older tweet from this user
            if(index > 0) {
                index --;
                auto[nextTime, nextTweetId] = tweets[user][index];
                pq.push({nextTime, nextTweetId, user, index});
            }
        }

        return result;

    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) {
            return;
        }

        following[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }

};
