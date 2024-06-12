class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        ans.reserve(nums.size());
        vector<string> vec;
        vec.reserve(nums.size());
        for(int& num: nums){
            vec.push_back(to_string(num));
        }
        sort(vec.begin(), vec.end(), [](const string& a, const string& b){
            return a+b > b+a;
        });
        if(vec[0] == "0")    return "0";
        for(string& num: vec){
            ans += num;
        }
        return ans;
    }
};


/*
98
989

98989
98998

98
98989

9898989
9898998

12
121

12121
12112

*/