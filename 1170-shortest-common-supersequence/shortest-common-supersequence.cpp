class Solution {
public:

    int find(int i,int j,string &s1, string &s2,vector<vector<int>>&dp){

        if(i==0 || j==0) return 0;

        if(dp[i][j] != -1) return dp[i][j];


        if(s1[i-1]==s2[j-1]) return dp[i][j] = 1 + find(i-1,j-1,s1,s2,dp);

        return dp[i][j] = max(find(i-1,j,s1,s2,dp), find(i,j-1,s1,s2,dp));
    }

    string shortestCommonSupersequence(string s1, string s2) {
        // form lcs table
        // then start building string
        int n = s1.size(),m = s2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        find(n,m,s1,s2,dp);

        int i=n,j=m;
        string ans = "";
        while(i>0 && j>0){
            if(s1[i-1] == s2[j-1]){
                ans += s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans += s1[i-1];
                i--;
            }
            else{
                ans += s2[j-1];
                j--;
            }
        }

        while(i>0) ans+= s1[i-- -1];
        while(j>0) ans+= s2[j-- -1];

        reverse(ans.begin(),ans.end());
        return ans;
    }
};