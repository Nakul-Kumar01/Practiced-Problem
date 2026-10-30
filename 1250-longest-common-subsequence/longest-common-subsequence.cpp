class Solution {
public:

    int find(int i,int j,string &t1, string &t2,vector<vector<int>>&dp){

        if(i == 0 || j==0) return 0;

        if(dp[i][j] != -1) return dp[i][j];


        if(t1[i-1] == t2[j-1]) return dp[i][j] = 1 + find(i-1,j-1,t1,t2,dp);


        return dp[i][j] = max(find(i-1,j,t1,t2,dp),find(i,j-1,t1,t2,dp));


    }
 
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size(),m = t2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return find(n,m,t1,t2,dp);


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t1[i-1] == t2[j-1])  dp[i][j] = 1 + dp[i-1][j-1];


                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};