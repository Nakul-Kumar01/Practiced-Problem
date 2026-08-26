class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();

        int l = 0,r = 0;

        unordered_map<int,int>m;
        for(int x : t) m[x]++;
        int d = m.size();

        int ans = INT_MAX;
        int k = -1;

        while(r<n){
            m[s[r]]--;
            if(m[s[r]] == 0) d--;

            while(d==0){
                // ans = min(ans,r-l+1);
                if(r-l+1 < ans){
                    ans = r-l+1;
                    k = l;
                }

                m[s[l]]++;
                if(m[s[l]] == 1) d++;
                l++;
            }

            r++;
        }
        if(k == -1) return "";
        return s.substr(k,ans);
    }
};