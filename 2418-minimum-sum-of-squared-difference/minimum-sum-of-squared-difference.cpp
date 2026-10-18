class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        long long k = k1 + k2;

        long long l  =0,r = 0;

        vector<long long>dif(n,0);
        long long s =0;


        for(int i=0;i<n;i++){
            dif[i] = abs(nums1[i]-nums2[i]);
            r = max(r,dif[i]);
            s += dif[i];
        }

        if(s <= k) return 0;
        long long mid = 0;

        while(l<=r){
             mid = l + (r-l)/2;


            long long c  = 0;
            for(int i=0;i<n;i++){
                c += max((long long)0, dif[i]-mid);
            }


            if(c>k) l = mid+1;
            else if(c<=k) r= mid-1;
        }
 int threshold = l;
        long long remaining = k;

        for (int d : dif) {
            remaining -= max(0, d - threshold);
        }

        long long result = 0;

        for (int d : dif) {
            d = min(d, threshold);

            if (d == threshold && remaining > 0) {
                d--;
                remaining--;
            }

            result += 1LL * d * d;
        }

        return result;
    }
};