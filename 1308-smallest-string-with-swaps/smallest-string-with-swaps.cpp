class Solution {
public:

    void dfs(int node,string &s , unordered_map<int,vector<int>>&m,vector<bool>&v, vector<int>&in,string &srt){
        
        v[node] = 1;
        in.push_back(node);
        srt.push_back(s[node]);

        for(int nei : m[node]){
           if(!v[nei]){
            dfs(nei,s,m,v,in,srt);
           }
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();

        // int m = pairs.size();


        vector<bool>v(n) ;
        vector<int>in;
        string srt = "";
        unordered_map<int,vector<int>>m; 

        for(auto x : pairs){
            m[x[0]].push_back(x[1]);
            m[x[1]].push_back(x[0]);
        }      


        for(int i=0;i<n;i++){
            if(!v[i]){
                srt = "";
                in.clear();
                dfs(i,s,m,v,in,srt);

                sort(in.begin(),in.end());
                sort(srt.begin(),srt.end());
                for(auto x: srt) cout<<x<<" ";


                for(int j = 0;j<in.size();j++){
                    s[in[j]] = srt[j];
                }
            }
        }
        return s;
    }
};