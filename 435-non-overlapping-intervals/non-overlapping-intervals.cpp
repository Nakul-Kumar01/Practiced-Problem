class Compare{
    public:
    bool operator()(auto a,auto b){
        return a[1] < b[1];
    }
};
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        int n = in.size();


        sort(in.begin(),in.end(),Compare());


        int prev = INT_MIN;
        int c = 0;

        for(auto x : in){
            if(prev <= x[0]){
               c++;
               prev = x[1];
            }
        }
        return n - c;
    }

};