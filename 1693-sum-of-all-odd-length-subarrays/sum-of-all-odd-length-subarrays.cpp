class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=0;i<n;i++){
           int s = i+1,e = n-i;

           int c = (s * e + 1)/2;

           ans += c*arr[i];

        }
        return ans;
    }
};