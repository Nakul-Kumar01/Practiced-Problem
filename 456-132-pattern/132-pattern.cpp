class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();


        int sec = INT_MIN;

        stack<int>s;

        for(int i = n-1;i>=0 ;--i){

            if(sec>nums[i]) return 1;

            
            while(!s.empty() && nums[i] > s.top()){
                 sec = s.top();
                 s.pop();
            }
            s.push(nums[i]);
        }
        return 0;
    }
};