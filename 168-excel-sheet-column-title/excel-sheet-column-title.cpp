class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";

        while (n > 0) {
            if (n % 26 == 0) {
                ans = "Z" + ans;
                n = (n-1)/26;
            } else {
                string t = "";
                t += ((n % 26) - 1) + 'A';
                ans = t + ans;
                n /= 26;
            }
        }
        return ans;
    }
};