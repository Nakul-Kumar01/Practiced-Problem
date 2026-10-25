class Solution {
public:


    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};


    bool valid(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
 

    void dfs(int i,int j,vector<vector<int>>&arr,int id,unordered_map<int,int>&mm){
        int n = arr.size(),m = arr[0].size();


        for(int k=0;k<4;k++){
            if(valid(i + row[k],j+col[k],n,m) && arr[i+row[k]][j+col[k]]==1){
                mm[id]++;
                arr[i+row[k]][j+col[k]] = id;
                dfs(i+row[k],j+col[k],arr,id,mm);
            }
        }
    }

    int largestIsland(vector<vector<int>>& arr) {
        int n = arr.size(),mm = arr[0].size();

        int id = 2;
        int maxi = 0;

        unordered_map<int,int>m;

        for(int i=0;i<n;i++){
            for(int j = 0;j<mm;j++){
                if(arr[i][j]==1){
                    arr[i][j] = id;
                    m[id] = 1;
                    dfs(i,j,arr,id,m);
                    maxi = max(maxi,m[id]);
                    id++;
                }
            }
        }

        int ans = 0;


        for(int i=0;i<n;i++){
            for(int j=0;j<mm;j++){
                if(arr[i][j]==0){
                   unordered_set<int>s;
                   int t = 0;
                   
                   for(int k=0;k<4;k++){
                    if(valid(i + row[k],j+col[k],n,mm) && arr[i+row[k]][j+col[k]] >1 && !s.count(arr[i+row[k]][j+col[k]])){
                       t += m[arr[i+row[k]][j+col[k]]];
                       s.insert(arr[i+row[k]][j+col[k]]);
                    }
                   }

                   ans = max(ans,t + 1);
                }
            }
        }
        return ans==0 ? maxi:ans;
    }
};