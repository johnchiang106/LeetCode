/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) : list(nestedList) {
        pos.clear();
        pos.push_back(0);
        // list = nestedList;
        NestedInteger it2 = list[0];
        while(!it2.getList()[0].isInteger()){
            it2 = it2.getList()[0];
            pos.push_back(0);
        }
    }
    
    int next() {
        NestedInteger it2 = pos.front();
        int ret;
        for(int layer = 1; layer < pos.size()-1; ++layer){
            it2 = it2.getList()[pos[layer]];
        }
        if(it2.getList()[pos.back()].isInteger()){
            ret = list[pos.back()].getInteger();
        }
        while(++pos.back() >= it2.getList().size()){
            pos.pop_back();
            for(int layer = 0; layer < pos.size()-1; ++layer){
                it2 = it2.getList()[pos[layer]];
            }
        }
        while(!it2.isInteger()){
            it2 = it2.getList()[0];
            pos.push_back(0);
        }
        return ret;
    }
    
    bool hasNext() {
        if(pos.empty() || pos.back() >= list.size())
            return false;
        return true;
    }
private:
    vector<NestedInteger> &list;
    vector<int> pos;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */