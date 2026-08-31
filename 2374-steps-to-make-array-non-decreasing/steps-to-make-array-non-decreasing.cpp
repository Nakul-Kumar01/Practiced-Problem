class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();

        stack<pair<int,int>>s;
        int ans = 0;

        for(int x : nums){

            int step = 0;

            while(!s.empty() && s.top().first <= x){
                step = max(step, s.top().second);
                s.pop();
            }

            if(s.empty()) step = 0;
            else step++;


            ans = max(ans,step);
            s.push({x,step});
        }
        return ans;
    }
};