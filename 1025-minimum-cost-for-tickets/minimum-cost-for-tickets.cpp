class Solution {
public:

    int find(int i,vector<int>& day, vector<int>& cost,vector<int>&dp){

        if(i>=day.size()) return 0;

        if(dp[i] != -1) return dp[i];


        int res = INT_MAX;

        int in = upper_bound(day.begin(),day.end(),day[i]) - day.begin();
        res = min(res, cost[0] + find(in,day,cost,dp));

         in = upper_bound(day.begin(),day.end(),day[i]+7-1) - day.begin();
        res = min(res,cost[1] + find(in,day,cost,dp));

         in = upper_bound(day.begin(),day.end(),day[i]+30-1) - day.begin();
        res = min(res, cost[2] + find(in,day,cost,dp));

        return dp[i] = res;
    }

    int mincostTickets(vector<int>& day, vector<int>& cost) {
        int n = day.size();

        vector<int>dp(n,-1);
        return find(0,day,cost,dp);
    }
};