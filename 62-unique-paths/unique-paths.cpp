class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>arr(n,1);
//
        for(int i=m-2;i>=0;--i){
            for(int j = n-2;j>=0;--j){
                arr[j] = arr[j+1] + arr[j];
            }
        }
        return arr[0];
    }
};