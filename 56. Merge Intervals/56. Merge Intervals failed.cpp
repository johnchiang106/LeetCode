class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1)   return intervals;

        vector<int> v;
        v.push_back(intervals[0][0]);
        v.push_back(intervals[0][1]);
        // for(auto& n: v)
        //   cout<<n<<" ";
        // cout<<endl;
        for(auto i = 1; i < intervals.size(); ++i){
        int pos1, pos2;
        pos1 = searchInsert(v, intervals[i][0]);
        pos2 = searchInsert(v, intervals[i][1]);
        if(pos1 % 2 == 0 && pos2 % 2 == 0){
            if(pos1 == pos2){
                if(v[pos1] == intervals[i][1])
                    v[pos1] = intervals[i][0];
                else{
                    v.insert(v.begin() + pos1, intervals[i][1]);
                    v.insert(v.begin() + pos1, intervals[i][0]);
                }
            }
            else{
                v[pos1] = intervals[i][0];
                v[pos2-1] = intervals[i][1];
                if(pos1 + 2 != pos2){
                    v.erase(v.begin()+pos1+1, v.begin()+pos2-1);
                }
            }
        }
        else if(pos1 % 2 == 0 && pos2 % 2 == 1){
            v.erase(v.begin()+pos1, v.begin()+pos2);
            v.insert(v.begin() + pos1, intervals[i][0]);
        }
        else if(pos1 % 2 == 1 && pos2 % 2 == 0){
            v.erase(v.begin()+pos1, v.begin()+pos2);
            v.insert(v.begin() + pos1, intervals[i][1]);
        }
        else if(pos1 != pos2){
            v.erase(v.begin()+pos1, v.begin()+pos2);
        }

        // for(auto& n: v)
        //   cout<<n<<" ";
        // cout<<endl;
        }
        vector<vector<int>> ans;
        for(int i = 0; i < v.size(); i += 2){
            ans.push_back({v[i],v[i+1]});
        }
        return ans;
    }
private:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};