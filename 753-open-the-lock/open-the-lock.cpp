class Solution {
public:
    int openLock(vector<string>& de, string tar) {
        if (tar == "0000")
            return 0;

        unordered_set<string> s(de.begin(), de.end());

        unordered_map<char, vector<char>> m;
        m['0'] = {'1', '9'};
        m['1'] = {'2', '0'};
        m['2'] = {'3', '1'};
        m['3'] = {'2', '4'};
        m['4'] = {'5', '3'};
        m['5'] = {'6', '4'};
        m['6'] = {'7', '5'};
        m['7'] = {'8', '6'};
        m['8'] = {'9', '7'};
        m['9'] = {'0', '8'};

        queue<string> q;
        q.push("0000");

        if (s.count("0000"))
            return -1;
        int ans = 0;

        unordered_set<string>v;
        v.insert("0000");

        while (!q.empty()) {
            int nn = q.size();
            ans++;
            while (nn--) {
                string node = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    string nei = node;
                    for (auto c : m[node[i]]) {
                        nei[i] = c;

                        if (nei == tar) return ans;
                        else if(s.count(nei) || v.count(nei)) continue;
                        else{
                            v.insert(nei);
                            q.push(nei);
                        }
                    }
                }
            }
        }
        return -1;
    }
};