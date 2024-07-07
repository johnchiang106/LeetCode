class Solution {
public:
    string originalDigits(string s) {
        // zero, one, two, three, four, five, six, seven, eight, nine
        // z->0, w->2, u->4, x->6, g->8
        // one, three, five, seven, nine
        // o->1, t->3, f->5, s->7
        // nine
        // i->9
        
        int digits[10] = {0};
        
        for(char& c: s){
            if(c == 'z')    digits[0]++;
            else if(c == 'w')    digits[2]++;
            else if(c == 'u')    digits[4]++;
            else if(c == 'x')    digits[6]++;
            else if(c == 'g')    digits[8]++;
            else if(c == 'o')    digits[1]++;
            else if(c == 't')    digits[3]++;
            else if(c == 'f')    digits[5]++;
            else if(c == 's')    digits[7]++;
            else if(c == 'i')    digits[9]++;
        }
        if(digits[1] > 0)   digits[1] -= digits[0] + digits[2] + digits[4]; //o
        if(digits[3] > 0)   digits[3] -= digits[2] + digits[8]; //t
        if(digits[5] > 0)   digits[5] -= digits[4]; //f
        if(digits[7] > 0)   digits[7] -= digits[6]; //s
        if(digits[9] > 0)   digits[9] -= digits[5] + digits[6] + digits[8]; //i
        
        string ans = "";
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < digits[i]; j++)
                ans += to_string(i);
        return ans;
    }
};