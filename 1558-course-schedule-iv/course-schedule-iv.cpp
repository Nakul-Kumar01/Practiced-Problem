class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int>indegree(numCourses,0);

        for(auto& pre:prerequisites){
            adj[pre[0]].push_back(pre[1]);
            indegree[pre[1]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<vector<bool>> isTrue(numCourses,vector<bool>(numCourses,false));

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: adj[node]){
                isTrue[it][node] = true;

                for(int i=0;i<numCourses;i++){
                    if(isTrue[node][i]){
                        isTrue[it][i] = true;
                    }
                }

                indegree[it]--;

                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        vector<bool>ans;

       for (auto &q : queries) {
            ans.push_back(isTrue[q[1]][q[0]]);
        }

        return ans;
    }
};