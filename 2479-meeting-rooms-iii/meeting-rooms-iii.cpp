class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& arr) {

        int m = arr.size();

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            q;
        priority_queue<int, vector<int>, greater<int>> free;

        for (int i = 0; i < n; i++)
            free.push(i);

        vector<int> c(n, 0);

        sort(arr.begin(), arr.end());

        long long t = 0;
        for (auto x : arr) {
            t = max(t, (long long)x[0]);

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

            q.push({t + x[1]-x[0],free.top()});
            c[free.top()]++;
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