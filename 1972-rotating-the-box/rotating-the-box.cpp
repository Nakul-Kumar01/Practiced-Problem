class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& bg) {

        int n = bg.size(), m = bg[0].size();

        // apply gravity firsst
        // then rotate
        
        vector<vector<char>>ans(m,vector<char>(n,'.'));

        for(int i=n-1;i>=0;--i){
            int pos = m-1;

            for(int j=m-1;j>=0;--j){
                if(bg[i][j] == '#'){
                    // bg[i][pos] = '#';
                    // bg[i][j] = '.';
                    swap(bg[i][pos], bg[i][j]);  // swap hi krna yaha
                    pos = pos-1;
                }
                else if(bg[i][j] == '*') pos = j-1;
            }
        }
        for(int i=0;i<n;i++)
            for(int j =0;j<m;j++) cout<<bg[i][j]<<" ";


        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
               ans[j][n-i-1] = bg[i][j];
            }
        }
        return ans;

    }
};