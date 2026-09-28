class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        

        vector<pair<int,int>>adj[n];

        for(auto x :f){
            adj[x[0]].push_back({x[1],x[2]});
        }

        vector<int>dist(n,INT_MAX);
        dist[src] = 0;


        k++;

        queue<pair<int,int>>q;
        int ans = INT_MAX;
        q.push({0,src});

        while(!q.empty() && k>0){
            int nn = q.size();

            k--;
            while(nn--){
                auto [cost ,node] = q.front();
                q.pop();

                // if(dist[node] < cost) continue;


                for(auto [nei,wt] : adj[node]){
                    if(nei == dst){
                        ans = min(ans,cost + wt);
                    }
                    else if(dist[nei] > cost + wt){
                        dist[nei] = cost + wt;
                        q.push({cost + wt,nei});
                    }
                }
            }
        }

        return ans==INT_MAX ? -1 : ans;
    }
};