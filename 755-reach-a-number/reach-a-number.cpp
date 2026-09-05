class Solution {
public:
    int reachNumber(int target) {
        // if you change one move of length x from right to left, your final
        // position decreases by 2x.
        // So from total sum S, you can reach target if:
        //  S - target
        // is even


         target = abs(target);

        int moves = 0;
        int sum = 0;

        while (sum < target || (sum - target) % 2 != 0) {
            moves++;
            sum += moves;
        }

        return moves;
        // return 0;
    }
};