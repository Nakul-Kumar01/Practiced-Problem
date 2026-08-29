class Solution {
public:


    long long find(int i,int n,vector<vector<int>>& arr,vector<long long>&dp){

        if(i>=arr.size()) return 0; 

        if(dp[i] != -1) return dp[i];       

        auto in = lower_bound(arr.begin(),arr.end(),vector<int>{arr[i][1], 0, 0}) - arr.begin();

        return dp[i] = max(find(i+1,n,arr,dp),arr[i][2] + arr[i][1]-arr[i][0]  + find(in,n,arr,dp));
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& arr) {
        

        sort(arr.begin(),arr.end());

        vector<long long>dp(arr.size(),-1);
        return find(0,n,arr,dp);
    }
};