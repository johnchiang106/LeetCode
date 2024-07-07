class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), count = 1, ans = 0;
        if(n == 1)  return (k > 0 || nums[0] == 1) ? 1 : 0;
        
        vector<int> vec;    //0101010   0 3 3 4 1   2 2 2 3 1 2 3 4
        if(nums[0] == 1)    vec.push_back(0);
        for(int i = 1; i < n; ++i){
            if(nums[i] != nums[i-1]){
                vec.push_back(count);
                count = 1;
            }
            else    ++count;
        }
        vec.push_back(count);
        for(auto& num: vec) cout<<num<<" ";
        cout<<endl;
        
        n = vec.size();
        int i = 0;
        for(; i < n && k > 0; i += 2){
            k -= vec[i];
        }
        if(k < 0)
            ans = accumulate(vec.begin(),vec.begin()+i-1,0)+k;
        else if(k == 0)
            ans = accumulate(vec.begin(),vec.begin()+i,0);
        else
            return accumulate(vec.begin(),vec.end(),0);
        
        //2 2 2 3 1 2 3 4
        int start = 0, temp = ans;
        cout<<temp<<endl;
        for(int j = 0; i < n;){
            // if(start == 0)  start = j;
            if(k < 0){
                // temp = accumulate(vec.begin()+start,vec.begin()+i-1,0)+k;
                if(j != 0)  temp -= vec[j-1];
                temp -= vec[j];
                j += 2;
                temp += vec[j+1];
                ans = max(ans,temp);
                k += vec[j];
                // start = j;
            }
            else if(k == 0){
                // temp = accumulate(vec.begin()+start,vec.begin()+i,0);
                if(j != 0)  temp -= vec[j-1];
                temp -= vec[j];
                ans = max(ans,temp);
                k += vec[j];
                j += 2;
                temp += vec[j];
                ans = max(ans,temp);
                // start = j;
            }
            else{
                temp += vec[i-1];
                ans = max(ans,temp);
                k -= vec[i];
                i += 2;
            }
            cout<<j<<", "<<i<<", "<<k<<", "<<start<<", "<<temp<<endl;
        }
        return ans;
    }
};