class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        int startY = min(stoi(date1.substr(0,4)), stoi(date2.substr(0,4)));
        
        return abs(days(date1,startY) - days(date2,startY));
    }
    int days(string& date, int& startY){
        int y, m, d, ans = 0;
        y = stoi(date.substr(0,4));
        m = stoi(date.substr(5,2));
        d = stoi(date.substr(8,2));
        
        for(int i = startY; i < y; ++i)
            ans += isLeapYear(i) ? 366 : 365;
        
        vector<int> dofm ({0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334});
        if(isLeapYear(y) && m > 2) ++ans;
        
        return ans+dofm[m-1]+d;
    }
    bool isLeapYear(int& year){
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};