class Solution {
public:
    int minOperations(int n) {
        int ans = 0;

        // simple idea : no. of 1 bit in n   -> but we can minimize consicutive 1's by adding 1

        while (n > 0) {

            if (n & 1) {

                if(n & (1<<1)) {
                    n+=1;
                    ans++;
                }
                else ans++;
            }
            n>>=1;
        }
        return ans;
    }
};