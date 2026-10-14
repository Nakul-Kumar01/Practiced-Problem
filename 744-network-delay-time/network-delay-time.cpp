class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        

        vector<pair<int,int>>adj[n+1];

        for(auto x : times){
            adj[x[0]].push_back({x[1],x[2]});
        }


        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;


        q.push({0,k});


        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;
        int c = 0;


        while(!q.empty()){
            auto [wt,node] = q.top();
            q.pop();


            if(wt>dist[node]) continue;
            c++;
            if(c==n) break; 

            for(auto [nei,cost] : adj[node]){

                if(wt + cost < dist[nei]){
                    dist[nei] = wt + cost;
                    q.push({dist[nei],nei});
                }
            }
        }

        int maxi = INT_MIN;
        for(int i =1;i<dist.size();i++){
            int x = dist[i];
            if(x == INT_MAX) return -1;
            maxi = max(maxi,x);
        }
        return maxi;
        
    }
};