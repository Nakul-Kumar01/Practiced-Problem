class Solution {
public:

    int find(int i,vector<int>&arr,int k,unordered_map<int,int>&m){
       if(i== arr.size()) return 1;


       int res = find(i+1,arr,k,m);

       if(m[arr[i]-k] == 0 && m[arr[i]+k] == 0){
           m[arr[i]]++;
           res += find(i+1,arr,k,m);
           m[arr[i]]--;
       }

       return res;
    }

    int beautifulSubsets(vector<int>& arr, int k) {
        unordered_map<int,int>m;
        return find(0,arr,k,m)-1;
    }
};