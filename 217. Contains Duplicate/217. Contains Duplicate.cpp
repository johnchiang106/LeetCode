class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int& n: nums){
            if(s.count(n))  return true;
            s.insert(n);
        }
        return false;
    }
private:
    unordered_set<int> s;
};