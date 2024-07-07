class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size(), ans = 0;
        vector<bitset<26>> containChar;
        for(auto& str: arr){
            bitset<26> temp;
            bool valid = true;
            for(auto& c: str){
                if(temp.test(c-'a')){
                    valid = false;
                    break;
                }
                temp.set(c-'a');
            }
            if(valid)
                containChar.push_back(temp);
        }
        vector<bitset<26>> concat{bitset<26>()};
        concat.reserve(n);
        for(auto& con: containChar){
            for(int i = concat.size()-1; i >= 0; --i){
                if((concat[i] & con).none()){
                    concat.push_back(concat[i] | con);
                    ans = max(ans, (int)concat.back().count());
                }
            }
        }
        return ans;
    }
};