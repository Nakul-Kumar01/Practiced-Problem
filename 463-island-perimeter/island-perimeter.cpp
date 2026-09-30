class Solution {
public:

    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool valid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }


    void dfs(int i,int j,vector<vector<int>>& arr,int &ans){
        int n = arr.size(),m = arr[0].size();

        for(int k=0;k<4;k++){
            if(valid(i+row[k],j+col[k],n,m)){
                  if(arr[i+row[k]][j+col[k]] == 0)ans++;
                  else if(arr[i+row[k]][j+col[k]] != -1){
                    arr[i+row[k]][j+col[k]] = -1;
                    dfs(i+row[k],j+col[k],arr,ans);
                  }
            }
            else{
                ans++;
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& arr) {
        int n = arr.size(),m = arr[0].size();


        int ans = 0;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1){
                arr[i][j] = -1;
                dfs(i,j,arr,ans);
                break;
                }
            }
        }
        return ans;
    }
};