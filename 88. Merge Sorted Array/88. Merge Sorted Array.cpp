class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0)  return;
        int i = 0, j = 0, index = 0;
        vector<int> n1(nums1.begin(), nums1.begin() + m);
        while(i < m && j < n)
            nums1[index++] = n1[i] <= nums2[j] ? n1[i++] : nums2[j++];
        while(i < m)    nums1[index++] = n1[i++];
        while(j < n)    nums1[index++] = nums2[j++];
    }
};