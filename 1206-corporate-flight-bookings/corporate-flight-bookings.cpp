class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& book, int n) {
        
        int m = book.size();

        vector<int>arr(n+2,0);

        for(auto x : book){
            arr[x[0]] += x[2];
            arr[x[1]+1] -= x[2];
        }

        vector<int>ans;

        int s = 0;

        for(int i=1;i<=n;i++){
            s+= arr[i];
            ans.push_back(s);
        }
        return ans;
    }
};