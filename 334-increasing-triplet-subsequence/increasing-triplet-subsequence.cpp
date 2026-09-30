class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        vector<int>arr;

        for(int i=0;i<n;i++){


            int in = lower_bound(arr.begin(),arr.end(),nums[i]) - arr.begin();

            if(in == arr.size()) arr.push_back(nums[i]);
            else arr[in] = nums[i];

            if(arr.size()>=3) return 1;
        }
 return 0;
    } 
};