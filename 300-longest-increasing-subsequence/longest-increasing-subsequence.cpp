class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        int s = 0, e = 0, m;

        int ind = 0;
        arr.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            s = 0, e = arr.size()-1;
            ind = -1;
            while (s <= e) {
                m = s + (e - s) / 2;
                if (arr[m] >= nums[i]) {
                    ind = m;
                    e = m-1;
                } else
                    s = m + 1;
            }

            if(ind == -1) arr.push_back(nums[i]);
            else arr[ind] = nums[i];
        }

        return arr.size();
    }
};