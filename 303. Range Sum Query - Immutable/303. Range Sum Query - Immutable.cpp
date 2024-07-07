class NumArray {
public:
    NumArray(vector<int>& nums) {
        arr = nums;
    }
    
    int sumRange(int left, int right) {
        return accumulate(arr.begin()+left,arr.begin()+right+1,0);
    }
private:
    vector<int> arr;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */