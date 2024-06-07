class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int i = 0, j = 0, count = 0, n = buses.size(), n2 = passengers.size();
        while(i < n){
            count = 0;
            while(passengers[j] <= buses[i] && count < capacity){
                 ++count;
                 if(++j == n2){
                    if(i < n-1)
                        return buses[n-1];
                    i = n;
                    break;
                 }
            }
            ++i;
        }
        if(j == 0)
            return min(passengers[0] - 1, buses[n-1]);
        --j;
        if(count < capacity && passengers[j] != buses[n-1]){
            return buses[n-1];
        }
        while(j > 0 && passengers[j-1] == passengers[j]-1)   --j;
        return passengers[j] - 1;
    }
};