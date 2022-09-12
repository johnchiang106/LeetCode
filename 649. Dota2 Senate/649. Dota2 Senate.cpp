class Solution {
public:
    string predictPartyVictory(string senate) {
        string next = "", cur = senate;
        bool lastR;
        int ban = 0;
        while(ban < cur.size()){
            for(char& c: cur){
                if(ban != 0 && lastR != (c == 'R')) --ban;
                else{
                    if(ban == 0)    lastR = (c == 'R');
                    next.append(1,c);
                    ++ban;
                }
            }
            cur = next;
            next.clear();
        }
        return lastR ? "Radiant" : "Dire";
    }
};