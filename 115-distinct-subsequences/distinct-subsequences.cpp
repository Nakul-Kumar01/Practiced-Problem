class Solution {
public:

    int find(int i,int j,string &s,string &t,vector<vector<int>>&dp){

        if(j==0) return 1;
        if(i==0) return 0;

        if(dp[i][j] != -1) return dp[i][j];


        if(s[i-1]==t[j-1]) return dp[i][j] = find(i-1,j-1,s,t,dp) + find(i-1,j,s,t,dp);

        return dp[i][j] = find(i-1,j,s,t,dp);
    }

    int numDistinct(string s, string t) {

        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        
        return find(s.size(),t.size(),s,t,dp);
    }
};