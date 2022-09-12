class Solution {
public:
    string predictPartyVictory(string senate) {
        // R = true表示本輪循環結束後，字符串裡依然有R。D同理
        bool R = true, D = true;
        // 當flag大於0時，R在D前出現，R可以消滅D。當flag小於0時，D在R前出現，D可以消滅R
        int flag = 0;
        while (R && D) { // 一旦R或者D為false，就結束循環，說明本輪結束後只剩下R或者D了
            R = false;
            D = false;
            for (int i = 0; i < senate.size(); i++) {
                if (senate[i] == 'R') {
                    if (flag < 0) senate[i] = 0; // 消滅R，R此時為false
                    else R = true; // 如果沒被消滅，本輪循環結束有R
                    flag++;
                }
                if (senate[i] == 'D') {
                    if (flag > 0) senate[i] = 0;
                    else D = true;
                    flag--;
                }
            }
        }
        // 循環結束之後，R和D只能有一個為true
        return R == true ? "Radiant" : "Dire";
    }
};