class Solution {
public:
 
    int find(int i,int j,string &w1,string &w2,vector<vector<int>>&dp){
        if(i == 0) return j;
        if(j == 0) return i;
//
        if(dp[i][j] != -1) return dp[i][j];

        if(w1[i-1] == w2[j-1]) return dp[i][j] = find(i-1,j-1,w1,w2,dp);


        return dp[i][j] = 1 + min(find(i,j-1,w1,w2,dp),min(find(i-1,j,w1,w2,dp),find(i-1,j-1,w1,w2,dp)));
        
    }
 
    int minDistance(string w1, string w2) {
        int n = w1.size(),m = w2.size();
        if(n==0) return m;
        if(m==0) return n;

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return find(n,m,w1,w2,dp);
    }
};