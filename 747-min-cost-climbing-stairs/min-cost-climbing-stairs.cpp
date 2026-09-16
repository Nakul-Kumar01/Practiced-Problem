class Solution {
public:

    int find(int i,vector<int>& arr,vector<int>&dp){

        if(i<=1) return 0;
        if(dp[i] != -1) return dp[i];

        return dp[i] = min(arr[i-1] + find(i-1,arr,dp), arr[i-2] + find(i-2,arr,dp));
    }


    int minCostClimbingStairs(vector<int>& arr) {
        int n = arr.size();

        if(n<=2){
            if(n==1) return arr[0];
            else return min(arr[0],arr[1]);
        }
        
        vector<int>dp(n+1,-1);

        return find(n,arr,dp);
    }
};