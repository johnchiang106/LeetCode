class Solution {
public:
    int trap(vector<int>& h) {
        // edge case: empty input
        if (!h.size()) return 0;
        // support variables
        int i = 0, j = h.size() - 1, maxLeft = h[i], maxRight = h[j], res = 0;
        while (i <= j) {
            // case 1: i points to a bigger element, so we advance j
            if (h[i] > h[j]) {
                if (h[j] > maxRight) maxRight = h[j];
                else res += maxRight - h[j];
                j--;
            }
            // case 2: j points to a bigger/equal element, so we advance i
            else {
                if (h[i] > maxLeft) maxLeft = h[i];
                else res += maxLeft - h[i];
                i++;
            }
        }
        return res;
    }
};