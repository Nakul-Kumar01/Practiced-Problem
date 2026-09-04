class Solution {
public:
    string smallestNumber(string str) {
        int n = str.size();

        stack<string> s;
        // s.push("1");

        string ans = "";

        int num = 1;

        for(int i=0;i<=n;i++){
            s.push(to_string(num));

            if(i == n || str[i]=='I'){
                while(!s.empty()){
                    ans += (s.top());
                    s.pop();
                }
            }

            num++;
        }
        return ans;
    }
};