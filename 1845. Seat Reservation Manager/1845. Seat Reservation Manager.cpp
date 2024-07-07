class SeatManager {
public:
    SeatManager(int n) {
        while(n > 0){
            pq.push(n--);
        }
    }
    
    int reserve() {
        int num = pq.top();
        pq.pop();
        return num;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */