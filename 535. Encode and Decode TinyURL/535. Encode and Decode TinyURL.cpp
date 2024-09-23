class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        srand(time(NULL));
        int r = rand();
        mp[r] = longUrl;
        return "https://blabla" + to_string(r);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[stoi(shortUrl.substr(14))];
    }
private:
    unordered_map<int, string> mp;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));