class Compare{
    public:
    bool operator()(auto &a,auto &b){
        return a.size() < b.size();
    }
};
class Solution {
public:

    bool isprev(string &a,string &b){


        for(int i=0;i<b.size();i++){
            string c = "";
            if(i==0) c = b.substr(1);
            else if(i==b.size()-1) c = b.substr(0,b.size()-1);
            else{
                c = b.substr(0,i) + b.substr(i+1);
            }

            if(c==a) return 1;
        }
        return 0;
    }


    

    int longestStrChain(vector<string>& arr) {
        int n = arr.size();

        vector<int>len(n,1);

        sort(arr.begin(),arr.end(),Compare());

int ans = 1;

        for(int i=1;i<n;i++){
            for(int j = i-1;j>=0;--j){
                if(arr[j].size()+1 == arr[i].size() && isprev(arr[j],arr[i])){
                    if(len[j]+1 > len[i]){
                        len[i] = len[j]+1;
                        ans = max(ans,len[i]);
                    }
                }

                if(arr[j].size() + 1 < arr[i].size()) break;
            }
        }

        return ans;
    }
};