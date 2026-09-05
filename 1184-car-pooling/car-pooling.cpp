class Compare{
    public:


    bool operator()(auto a,auto b){
        return a[1] < b[1];
    }
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& arr, int cap) {
        int n = arr.size();


        sort(arr.begin(),arr.end(),Compare());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;

        int d = 0,c=0;
        for(auto x : arr){
            d = max(d,x[1]);

            while(!q.empty() && q.top().first <= d){
                  c -= q.top().second;

                  q.pop();
            }


            c += x[0];
            if(c > cap) return 0;
            q.push({x[2],x[0]});
        }
        return 1;
    }
};