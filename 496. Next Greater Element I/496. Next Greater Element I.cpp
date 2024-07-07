class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        stack<int> st;
        unordered_map<int, int> umap;
        
        for(auto& n :nums2){
            while(!st.empty() && n > st.top()){
                umap[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }
        
        ans.reserve(nums1.size());
        for(auto& n :nums1)
            if(umap.find(n) != umap.end())
                ans.push_back(umap[n]);
            else
                ans.push_back(-1);
        
        return ans;
    }
};