class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        vector<int>arr;

        for(int i=0;i<n;i++){


            int j =0;
            while(j<arr.size()){
                if(arr[j]>= nums[i]){
                    arr[j] = nums[i];
                    break;
                }
                j++;
            }

            if(j==arr.size()) arr.push_back(nums[i]);
            if(arr.size()>=3) return 1;
        }
 return 0;
    } 
};