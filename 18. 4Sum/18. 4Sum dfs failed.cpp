class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        set<vector<int>> s;
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        int a = 0, b = 1, c = 2, d = 3;
        // for(auto& n: nums)
        //     cout<<n<<" ";
        // cout<<endl;
        dfs(a, b, c, d, nums, target, s);
        // for(auto& v: s)
        //     ans.push_back(v);
        return ans;
    }
private:
    void dfs(int a, int b, int c, int d, const vector<int>& nums, const int& target, set<vector<int>>& s){
        // if(a > nums.size() - 4) return;
        // cout<<a<<" "<<b<<" "<<c<<" "<<d<<" ";
        // cout<<nums[a]<<" "<<nums[b]<<" "<<nums[c]<<" "<<nums[d]<<endl;
        int sum = nums[a]+nums[b]+nums[c]+nums[d];
        if(sum == target){
            s.insert({nums[a],nums[b],nums[c],nums[d]});
            // cout<<"+"<<endl;
        }
        else if(sum < target){
            if(d+1 < nums.size()){
                // ++d;
                // while(d+1 < nums.size() && nums[d-1] == nums[d])
                //     ++d;
                // dfs(a, b, c, d, nums, target, s);
                dfs(a, b, c, d+1, nums, target, s);
            }
            if(c+1 < d){
                // ++c;
                // while(c+1 < d && nums[c-1] == nums[c])
                //     ++c;
                // dfs(a, b, c, d, nums, target, s);
                dfs(a, b, c+1, d, nums, target, s);
            }
            if(b+1 < c){
                // ++b;
                // while(b+1 < c && nums[b-1] == nums[b])
                //     ++b;
                // dfs(a, b, c, d, nums, target, s);
                dfs(a, b+1, c, d, nums, target, s);
            }
            if(a+1 < b){
                // ++a;
                // while(a+1 < b && nums[a-1] == nums[a])
                //     ++a;
                // dfs(a, b, c, d, nums, target, s);
                dfs(a+1, b, c, d, nums, target, s);
            }
        }
        return;
    }
};