class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& que) {
        

        vector<vector<bool>>arr(n,vector<bool>(n,0));


        for(auto x  : pre){
            arr[x[1]][x[0]] = 1;

            for(int i=0;i<arr[0].size();i++){
                if(arr[x[0]][i]) arr[x[1]][i] = 1;
            }

            for(int i=0;i<arr.size();i++){
                if(arr[i][x[1]]) arr[i][x[0]] = 1;
            }
        }

vector<bool>ans;
        for(auto x : que){
           ans.push_back(arr[x[1]][x[0]]);
        }
        return ans;
    }
};