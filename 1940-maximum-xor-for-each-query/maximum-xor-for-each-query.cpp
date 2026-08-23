class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorSum = 0;
        
        // XOR of all elements
        for (int num : nums) {
            xorSum ^= num;
        }

        int mask = (1 << maximumBit) - 1;

        vector<int> ans;
        
        // Process queries
        for (int i = nums.size() - 1; i >= 0; i--) {
            
            // Best k to make xorSum maximum
            ans.push_back(xorSum ^ mask);
            
            // Remove last element
            xorSum ^= nums[i];
        }

        return ans;
    }
};