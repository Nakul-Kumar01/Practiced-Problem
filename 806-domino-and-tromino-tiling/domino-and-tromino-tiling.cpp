class Solution {
public:
    int numTilings(int n) {
        vector<long long>dp(n+1);
       // here
        dp[1] = 1;
        if(n==1) return 1;
        dp[2] = 2;
        if(n==2) return 2;
        dp[3] = 5;

        for(int i=4;i<=n;i++) dp[i] = (dp[i-1] * 2 + dp[i-3])% 1000000007;
        return dp[n]% 1000000007;
    }
};