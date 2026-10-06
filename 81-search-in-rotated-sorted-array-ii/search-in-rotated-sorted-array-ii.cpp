class Solution {
public:
    bool search(vector<int>& nums, int tar) {
        int n = nums.size();

        int i=0,j=n-1;

        while(i<=j){
            int mid = i + (j-i)/2;

            if(nums[mid] == tar) return 1;
            if(nums[i]==nums[mid] && nums[mid]==nums[j]){
                i++;
                j--;
            }
            else if(nums[mid] < nums[i]){
                if(nums[mid] < tar && tar <= nums[j]) i=mid+1;
                else j = mid-1;
            }
            else{
                if(nums[mid] > tar && tar >= nums[i]) j = mid-1;
                else i=mid+1;
            }
        }
        return 0;
    }
};