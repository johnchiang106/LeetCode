class Solution {
public:
	int romanToInt(string s) {
		map<char, int> rNum;
		rNum['I'] = 1;
		rNum['V'] = 5;
		rNum['X'] = 10;
		rNum['L'] = 50;
		rNum['C'] = 100;
		rNum['D'] = 500;
		rNum['M'] = 1000;

		int previous = 0, now, ans = 0;
		for (string::iterator it = s.begin(); it != s.end(); ++it) {
			now = rNum.find(*it)->second;
			if (previous >= now) {
				ans += previous;
				previous = now;
			}
			else {
				previous = now - previous;
			}
		}
		ans += previous;
		return ans;
	}
};