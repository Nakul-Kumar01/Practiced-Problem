class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        
        vector<int>adj[n];

        vector<int>in(n,0);

        for(auto x : pre){
            adj[x[1]].push_back(x[0]);
            in[x[0]]++;
        }


        queue<int>q;
        for(int i=0;i<n;i++) if(in[i]==0) q.push(i);
        int c = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            c++;


            for(auto nei : adj[node]){

                in[nei]--;
                if(in[nei]==0) q.push(nei);
            }

        }

        return n == c;
    }
};