class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(smaller.empty() && larger.empty()){
            smaller.push(num);
            return;
        }
        if(smaller.size() == larger.size()){
            if(num < larger.top()){
                smaller.push(num);
            }
            else{
                smaller.push(larger.top());
                larger.pop();
                larger.push(num);
            }
        }
        else{
            if(num < smaller.top()){
                larger.push(smaller.top());
                smaller.pop();
                smaller.push(num);
            }
            else{
                larger.push(num);
            }
        }
    }
    
    double findMedian() {
        if(smaller.size() > larger.size()) return smaller.top();
        return double(smaller.top()+larger.top())/2;
    }
private:
    priority_queue<int> smaller;
    priority_queue<int, vector<int>, greater<int>> larger;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */