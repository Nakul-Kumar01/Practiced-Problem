class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        int n = s.size();

        int cols = n/rows;

        string ans = "";


        for(int col =0;col<cols;col++){
            int i =0,j = col;

            while(i<rows && j < cols){
                ans += s[cols * i + j];
                i++;
                j++;
            }
        }


        while(!ans.empty() && ans.back()==' ') ans.pop_back();
        return ans;
    }
};