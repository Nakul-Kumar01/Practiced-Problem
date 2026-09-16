class Solution {
public:

    int find(int i,vector<int>& arr,vector<int>&dp){
        int n = arr.size();
        if(i == arr.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int res = INT_MIN,total = 0;
        for(int j=i;j<min(i+3,n);j++){
            total += arr[j];
            res = max(res, total - find(j+1,arr,dp));
        }

        return dp[i] = res;
    }

    string stoneGameIII(vector<int>& arr) {
        int n = arr.size();

        vector<int>dp(n+1,-1);
        int res = find(0,arr,dp);

        if(res == 0) return "Tie";

        return res < 0 ? "Bob" : "Alice";
    }
};