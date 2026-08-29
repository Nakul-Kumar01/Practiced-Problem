class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();

        unordered_map<char,int>m;
        priority_queue<pair<int,char>>q;


        for(auto x : s) m[x]++;


        for(auto [a,b] : m) q.push({b,a});


        string ans = "";

        auto [a,b] = q.top();
        q.pop();


        ans += b;
        a--;


        
        while(!q.empty()){
            auto [c,d] = q.top();
            q.pop();


            ans += d;
            c--;
            if(a>0){
                q.push({a,b});
            }
            // if(c>0){
                a = c;
                b = d;
            // }
        }

        if(a>0 && ans[ans.size()-1] == b) return "";
        // if(a>0) ans += b;   

        return ans;
    }
};