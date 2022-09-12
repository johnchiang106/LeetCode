class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        auto j = typed.begin();
        for(auto i = name.begin(); i != name.end(); ++i){
            if(j == typed.end() || *i != *j) return false;
            if(i != name.end()-1 && *i == *(i+1))    ++j;
            else    while(*i == *j)  ++j;
        }
        return j == typed.end();
    }
};