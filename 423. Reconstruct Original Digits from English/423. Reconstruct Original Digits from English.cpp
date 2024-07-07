class Solution {
public:
    string originalDigits(string s) {
        // zero, one, two, three, four, five, six, seven, eight, nine
        // z->0, w->2, x->6, g->8
        // one, three, four, five, seven, nine
        // t->three, s->7
        // one, four, five, nine
        // r->four, v->five
        // one, nine
        // o->one, i->nine
        
        // e,g,f,i,h,o,n,s,r,u,t ,w ,v ,x ,z
        // 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14
        
        m.insert({'e',0});
        m.insert({'g',0});
        m.insert({'f',0});
        m.insert({'i',0});
        m.insert({'h',0});
        m.insert({'o',0});
        m.insert({'n',0});
        m.insert({'s',0});
        m.insert({'r',0});
        m.insert({'u',0});
        m.insert({'t',0});
        m.insert({'w',0});
        m.insert({'v',0});
        m.insert({'x',0});
        m.insert({'z',0});
        
        for(char& c: s){
            if(c == 'z')    digits[0]++;
            else if(c == 'w')    digits[2]++;
            else if(c == 'x')    digits[6]++;
            else if(c == 'g')    digits[8]++;
        }
        for(char c: "zero") m[c] += digits[0];
        for(char c: "two") m[c] += digits[2];
        for(char c: "six") m[c] += digits[6];
        for(char c: "eight") m[c] += digits[8];
        clearString(s);
        
        for(char& c: s){
            if(c == 't')    digits[3]++;
            else if(c == 's')    digits[7]++;
        }
        for(char c: "three") m[c] += digits[3];
        for(char c: "seven") m[c] += digits[7];
        clearString(s);
        
        for(char& c: s){
            if(c == 'r')    digits[4]++;
            else if(c == 'v')    digits[5]++;
        }
        for(char c: "four") m[c] += digits[4];
        for(char c: "five") m[c] += digits[5];
        clearString(s);
        
        for(char& c: s){
            if(c == 'o')    digits[1]++;
            else if(c == 'i')    digits[9]++;
        }
        
        string ans = "";
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < digits[i]; j++){
                ans += to_string(i);
            }
        }
        return ans;
    }
private:
    int digits[10] = {0};
    map<char,int> m;
    void clearString(string& s){
        for(auto it = s.begin(); it != s.end(); ++it){
            if(m[*it] > 0){
                m[*it]--;
                *it = '-';
            }
        }
    }
};

//         m['z'] += digits[0];
//         m['e'] += digits[0];
//         m['r'] += digits[0];
//         m['o'] += digits[0];
        
//         chars[10] += digits[2];
//         chars[11] += digits[2];
//         chars[5] += digits[2];
        
//         chars[7] += digits[6];
//         chars[3] += digits[6];
//         chars[13] += digits[6];
        
//         chars[0] += digits[8];
//         chars[3] += digits[8];
//         chars[1] += digits[8];
//         chars[4] += digits[8];
//         chars[10] += digits[8];