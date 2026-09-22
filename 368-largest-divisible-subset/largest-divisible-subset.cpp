class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();


        sort(arr.begin(),arr.end());

        vector<int>dp(n,1);
        vector<int>par(n,-1);

        int li=0;

        for(int i=0;i<n;i++){
           
           for(int j=i-1;j>=0;--j){
            if((arr[i] % arr[j]==0) && dp[i] < dp[j]+1){
               dp[i] = dp[j]+1;

               par[i] = j;


               if(dp[li] < dp[i]) li = i;
            }
           }
        }

        vector<int>ans;

        while(li != -1){
            ans.push_back(arr[li]);
            li = par[li];
        }
        return ans;
    }
};