class Twitter {
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        ans.reserve(10);
        for(auto it = posts.rbegin(); ans.size() < 10 && it != posts.rend(); ++it){
            if(it->first == userId || 
            following[userId].find(it->first) != following[userId].end()){
                ans.push_back(it->second);
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
        
    }
    vector<pair<int,int>> posts;
    unordered_map<int, unordered_set<int>> following;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */