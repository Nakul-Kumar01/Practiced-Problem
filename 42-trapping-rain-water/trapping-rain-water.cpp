class Solution {
public:
    int trap(vector<int>& hei) {
        int n = hei.size();

        int ans = 0,i=1,j= n-2;
        
        int l = hei[0],r = hei[n-1];

        while(i<=j){

            if(l < r){
                ans += l > hei[i] ? l-hei[i] : 0;
                l = max(l,hei[i]);
                i++;
            }
            else{
                ans += r > hei[j] ? r-hei[j] : 0;
                r = max(r,hei[j]);
                j--;
            }
        }
        return ans;
    }
};