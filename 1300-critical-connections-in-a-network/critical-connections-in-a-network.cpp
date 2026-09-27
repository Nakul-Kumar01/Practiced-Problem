class Solution {
public:

    void find(int node,int par,vector<int>&dis,vector<int>&low,vector<int>adj[],vector<vector<int>>&ans){


        for(auto nei : adj[node]){
            if(nei == par) continue;
            else if(dis[nei] == -1){
                dis[nei] = low[nei] = dis[node] +1;
                find(nei,node,dis,low,adj,ans);
                if(dis[node] < low[nei]) ans.push_back({node,nei});
                low[node] = min(low[node],low[nei]);    
            }
            else{
                low[node] = min(low[node],low[nei]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        
        vector<int>adj[n];
        for(auto x : con){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }


        vector<int>dis(n,-1),low(n,INT_MAX);

        vector<vector<int>>ans;

        dis[0] = 0;
        low[0] = 0;

        find(0,-1,dis,low,adj,ans);
        return ans;
    }
};