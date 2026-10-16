class Solution {
public:

    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};

    bool valid(int i,int j,int n,int m){
        return i<n && j<m && i>=0 && j>=0;
    }


    void dfs(int i,int j,vector<vector<int>>& arr,vector<vector<bool>>& pac){
        int n = arr.size(),m = arr[0].size();
        pac[i][j] = 1;


        for(int k = 0;k<4;k++){
            if(valid(i+row[k],j + col[k],n,m)  && arr[i][j] <= arr[i+row[k]][j+col[k]] && !pac[i+row[k]][j+col[k]]) dfs(i+row[k],j+col[k],arr,pac);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& arr) {
        int n = arr.size(),m = arr[0].size();

        vector<vector<bool>>pac(n,vector<bool>(m,0));
        vector<vector<bool>>atl(n,vector<bool>(m,0));


        for(int i =0;i<n;i++) if(!pac[i][0]) dfs(i,0,arr,pac);
        for(int j =0;j<m;j++) if(!pac[0][j]) dfs(0,j,arr,pac);
        for(int j =0;j<m;j++) if(!atl[n-1][j]) dfs(n-1,j,arr,atl);
        for(int i =0;i<n;i++) if(!atl[i][m-1]) dfs(i,m-1,arr,atl);


        vector<vector<int>>ans;
        for(int i=0;i<n;i++) for(int j =0;j<m;j++) if(pac[i][j] && atl[i][j]) ans.push_back({i,j});
        return ans;

    }
};