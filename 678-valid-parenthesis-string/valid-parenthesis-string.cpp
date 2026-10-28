class Solution {
public:

    bool find(int i,int t,string &s,vector<vector<int>>&dp){
       
       if(i==s.size()) return t==0;

       if(t < 0) return 0;

       if(dp[i][t] != -1) return dp[i][t];

       if(s[i]=='*') return dp[i][t] = find(i+1,t+1,s,dp) || find(i+1,t,s,dp) || find(i+1,t-1,s,dp);

       if(s[i] == '(') return dp[i][t]= find(i+1,t+1,s,dp);

       return dp[i][t]= find(i+1,t-1,s,dp);

    }

    bool checkValidString(string s) {
        int n = s.size();

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return find(0,0,s,dp);
    }
};