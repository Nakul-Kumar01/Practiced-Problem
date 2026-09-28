class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& arr) {

        priority_queue<long long,vector<long long>,greater<long long>> free;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            q;

        for (int i = 0; i < n; i++)
            free.push(i);

        long long t = 0;

        sort(arr.begin(), arr.end());

        vector<int> c(n, 0);

        for (auto x : arr) {
            long long a = x[0],b = x[1];
            t = max(t, a);

            while (!q.empty() && q.top().first <= t) {
                free.push(q.top().second);
                q.pop();
            }

            if (free.empty()) {
                t = q.top().first;
                while (!q.empty() && q.top().first <= t) {
                    free.push(q.top().second);
                    q.pop();
                }
            }
            
            c[free.top()]++;
            q.push({t+(b-a),free.top()});
            free.pop();
        }

        int maxi = 0;
        int ans = 0;

        for(int i=0;i<n;i++){
            if(maxi < c[i]){
                maxi = c[i];
                ans = i;
            }
        }
        return ans;
    }
};