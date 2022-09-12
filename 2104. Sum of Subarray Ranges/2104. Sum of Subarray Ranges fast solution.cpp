class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        stack<int> st, st2;
        vector<int> minPrev(n,-1), minNext(n,n), maxPrev(n,-1), maxNext(n,n);
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            if(!st.empty())
                minPrev[i] = st.top();
            st.push(i);
            
            while(!st2.empty() && nums[st2.top()] <= nums[i])
                st2.pop();
            if(!st2.empty())
                maxPrev[i] = st2.top();
            st2.push(i);
        }
        st = stack<int>(), st2 = st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            if(!st.empty())
                minNext[i] = st.top();
            st.push(i);
            
            while(!st2.empty() && nums[st2.top()] < nums[i])
                st2.pop();
            if(!st2.empty())
                maxNext[i] = st2.top();
            st2.push(i);
        }
        
        for(int i = 0; i < n; i++){
            long long leftMin = i-minPrev[i], rightMin = minNext[i]-i;
            long long leftMax = i-maxPrev[i], rightMax = maxNext[i]-i;
            sum += (leftMax * rightMax - leftMin * rightMin) * nums[i];
        }
        return sum;
    }
};