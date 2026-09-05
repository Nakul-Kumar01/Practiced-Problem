class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();

        unordered_map<int,int>m;

        for(int i=0;i<n;i++){
            if(arr[i] < 0) arr[i] = (arr[i] % k)+ k;

            if(arr[i] % k == 0){
                if(m.count(0)){
                    m[0]--;
                    if(m[0]==0) m.erase(0);
                }
                else m[0]++;
            }
            else{
                if(m.count(k - (arr[i]%k))){
                    m[k - (arr[i]%k)]--;
                    if(m[k - (arr[i]%k)]==0) m.erase(k - (arr[i]%k));
                } 

                else m[arr[i]%k]++;
            }
        }
        return m.size() == 0;
    }
};