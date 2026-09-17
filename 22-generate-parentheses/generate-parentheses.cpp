class Solution {
public:
    
    void find(int o,int c,string curr,vector<string> &ans,int n){

        if(o==n && c==n){
          ans.push_back(curr);
          return;
        }
        if(o>n) return;



        if(c+1 > o) return find(o+1,c,curr+"(",ans,n);

         find(o+1,c,curr + "(",ans,n);
          find(o,c+1,curr + ")",ans,n);
    }

    vector<string> generateParenthesis(int n) {
        

        vector<string>ans;
        find(0,0,"",ans,n);

        return ans;
    }
};