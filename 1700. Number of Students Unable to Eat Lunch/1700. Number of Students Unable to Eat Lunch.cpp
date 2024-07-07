class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int student1 = count(students.begin(),students.end(),1);
        int student0 = students.size() - student1;
        for(const int& s: sandwiches){
            if(s == 1 && student1 > 0)
                --student1;
            else if(s == 0 && student0 > 0)
                --student0;
            else    return student0+student1;
        }
        return 0;
    }
};