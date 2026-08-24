class Solution {
public:

    int find(int i,string &s,unordered_set<string>&m,vector<int>&dp){
        if(i>=s.size()) return 0;

        if(dp[i] != -1) return dp[i];
        
        int res = INT_MAX;

        res = min(res,1 + find(i+1,s,m,dp));

        string t = "";
        for(int j=i;j<s.size();j++){
           t += s[j];
           if(m.count(t)){
            res = min(res,find(j+1,s,m,dp));
           }
        }

        return dp[i] = res;
    }

    int minExtraChar(string s, vector<string>& dic) {
        
        int n = s.size();

        unordered_set<string>m;
        for(auto x: dic) m.insert(x);
        
        vector<int>dp(n+1,-1);

        return find(0,s,m,dp);
    }
};