class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int, int> map;
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            if (map.find(arr[i]) == map.end()) {
                map[arr[i]] = i;
            }
        }
        for (int& n: arr) {
            n = map[n];
        }
        return nums;
    }
};