class Solution {
public:

    int find(int s,int e,vector<int>&arr,vector<vector<int>>&dp){

        if(s + 1 >=e) return 0;

        if(dp[s][e] != -1) return dp[s][e];

        int res = INT_MAX;
        for(int i=s+1;i<e;i++){
               res = min(res, arr[e]-arr[s] + find(s,i,arr,dp) + find(i,e,arr,dp));
        }

        return dp[s][e] =res;
    }

    int minCost(int n, vector<int>& arr) {
        int m = arr.size();
        arr.push_back(0);
        arr.push_back(n);

        sort(arr.begin(),arr.end());

        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),-1));
        
        return find(0,arr.size()-1,arr,dp);
    }
};