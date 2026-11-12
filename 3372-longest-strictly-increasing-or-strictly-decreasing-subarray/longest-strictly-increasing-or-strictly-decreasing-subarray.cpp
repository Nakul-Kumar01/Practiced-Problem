class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();


        int ans = 1,s =0,e=1;
        while(e<n){
            if(nums[e] > nums[e-1]) ans = max(ans,e-s+1);
            else s = e;
            e++;
        }

        s = n-1,e=n-2;

        while(e>=0){
            if(nums[e] > nums[e+1]) ans = max(ans,s-e+1);
            else s = e;
            e--;
        }
        return ans;
        
    }
};