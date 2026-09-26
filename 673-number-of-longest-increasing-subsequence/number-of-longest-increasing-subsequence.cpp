class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n= arr.size();


        vector<int>len(n,1),c(n,1);

       int ans = 0,maxi = 1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;--j){
                if(arr[i] > arr[j]){
                   if(len[j] + 1 > len[i]){
                    len[i] =len[j] + 1;
                    c[i] = c[j];
                    maxi = max(maxi,len[i]);
                   }
                   else if(len[j] + 1 == len[i]){
                    c[i] += c[j];
                   }
                }
            }
        }


        for( int i=0;i<n;i++) if(len[i]==maxi) ans += c[i];
        return ans;
    }
};