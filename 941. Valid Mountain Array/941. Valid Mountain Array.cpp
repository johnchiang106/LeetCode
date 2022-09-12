class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3 || arr[0] >= arr[1])  return false;
        bool inc = true;
        // for(int i = 1; i < arr.size() - 1; i++){
        //     if(arr[i] == arr[i+1])  return false;
        //     else if(inc && arr[i] > arr[i+1]) inc = false;
        //     else if(!inc && arr[i] < arr[i+1])  return false;
        // }
        for (auto it = arr.begin()+1; it != arr.end()-1; ++it){
            if(*it == *(it+1))  return false;
            else if(inc && *it > *(it+1)) inc = false;
            else if(!inc && *it < *(it+1))  return false;
        }
        return !inc;
    }
};