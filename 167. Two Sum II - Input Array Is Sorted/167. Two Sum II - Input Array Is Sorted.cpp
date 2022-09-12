class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        set<int> numset;
        vector<int>::iterator it, it2;
        for(it = numbers.begin(); it != numbers.end(); ++it){
            if(numset.count(*it))   continue;
            it2 = find(it + 1, numbers.end(), target - *it);
            if(it2 != numbers.end()){
                int index1 = it - numbers.begin() + 1;
                int index2 = it2 - numbers.begin() + 1;
                return vector<int> { index1, index2 };
            }
            numset.insert(*it);
        }
        return vector<int> { 0, 0 };
    }
};