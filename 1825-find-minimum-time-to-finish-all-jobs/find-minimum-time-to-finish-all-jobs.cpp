class Solution {
public:

    void find(int i,vector<int>&arr,vector<int>&jobs,int k,int &ans){

        if(i==jobs.size()){
            int res = 0;
            for(int x : arr) res = max(res,x);

            ans = min(ans,res);

            return;
        }



        for(int j=0;j<k;j++){
            arr[j] += jobs[i];



            if(arr[j] < ans) 
            find(i+1,arr,jobs,k,ans);


            arr[j] -= jobs[i];


            if(arr[j]==0) break; // other workers were empty, so swapping their identities changes nothing
        }
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();

        sort(jobs.rbegin(),jobs.rend());

        vector<int>arr(k,0);

        int ans = INT_MAX;

        find(0,arr,jobs,k,ans);

        return ans;
    }
};