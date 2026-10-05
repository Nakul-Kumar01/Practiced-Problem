class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int tar) {
        int n = nums.size();

        int l = n-1,r=n-1;
        int s = 0,e =n-1;

        while(s<=e){
            int mid = s + (e-s)/2;

            if(nums[mid] >= tar){
                l = mid;
                e = mid-1;
            }
            else s = mid+1;
        }

        if(n==0 || nums[l] != tar) return {-1,-1};
        s = 0,e =n-1;

        while(s<=e){
            int mid = s + (e-s)/2;

            if(nums[mid] <= tar){
                r = mid;
                s = mid+1;
            }
            else e = mid-1;
        }

        return {l,r};
    }
};