class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        set<int> numset;
        vector<int>::iterator i;
        set<int>::iterator j, k;
        for(i = numbers.begin(); i != numbers.end(); ++i){
            numset.insert(*i);
        }
        for(j = numset.begin(); j != numset.end(); ++j){
            k = find(j, numset.end(), target - *j);
            if(k != numset.end()){
                i = find(numbers.begin(), numbers.end(), *j);
                int index1 = i - numbers.begin() + 1;
                int index2 = find(i + 1, numbers.end(), *k) - numbers.begin() + 1;
                return vector<int> { index1, index2 };
            }
        }
        return vector<int> { 0, 0 };
    }
};