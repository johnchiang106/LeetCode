class Solution {
public:
	int romanToInt(string s) {

		int previous = 0, now, ans = 0;
		for (string::iterator it = s.begin(); it != s.end(); ++it) {
			switch (*it) {
				case 'I': now = 1; break;
				case 'V': now = 5; break;
				case 'X': now = 10; break;
				case 'L': now = 50; break;
				case 'C': now = 100; break;
				case 'D': now = 500; break;
				case 'M': now = 1000; break;
				default: return 0;
			}
			ans += now;
			if (previous < now) {
				ans -= previous*2;
			}
			previous = now;
		}
		return ans;
	}
};