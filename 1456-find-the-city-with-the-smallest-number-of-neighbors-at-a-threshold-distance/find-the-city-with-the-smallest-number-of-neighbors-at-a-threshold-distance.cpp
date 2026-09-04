class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& ed, int dt) {
        

        vector<vector<int>>arr(n,vector<int>(n,INT_MAX));

        for(int i=0;i<n;i++) arr[i][i] = 0;

        for(auto e : ed){
            arr[e[0]][e[1]] = e[2];
            arr[e[1]][e[0]] = e[2];
        }


        for(int k = 0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(arr[i][k] != INT_MAX && arr[k][j] != INT_MAX){
                        arr[i][j] = min(arr[i][j],arr[i][k] + arr[k][j]);
                    }
                }
            }
        }

        int ans = 0,m =n;
        for(int i=0;i<n;i++){
            int t = 0;
            for(int j =0;j<n;j++){
              if(arr[i][j] <=dt) t++;
            }

            if(t<=m){
                m = t;
                ans = i;
            }
        }
        return ans;
    }
};