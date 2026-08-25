class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 2; i++) {

            // avoid duplicate first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // since array is sorted, no zero sum possible after this
            if (nums[i] > 0)
                break;

            int l = i + 1;
            int r = n - 1;

            while (l < r) {

                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});

                    l++;
                    r--;

                    // skip duplicate left values
                    while (l < r && nums[l] == nums[l - 1])
                        l++;

                    // skip duplicate right values
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
                else if (sum < 0) {
                    l++;   // need larger sum
                }
                else {
                    r--;   // need smaller sum
                }
            }
        }

        return ans;
    }
};