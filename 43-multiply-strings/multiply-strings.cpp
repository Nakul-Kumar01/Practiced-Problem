class Solution {
public:
    string multiply(string n1, string n2) {
        int n = n1.size(),m = n2.size();


        vector<int>arr(n+m,0);
       
        for(int j = m-1;j>=0;--j){
            for(int i = n-1;i>=0;--i){
               int mul = ((n1[i]-'0')  * (n2[j]-'0') );

               int sum = mul + arr[j + i + 1];

               arr[j + i + 1] = sum % 10;

               arr[j+i] += sum/10;
            }
        }


        int k =0;
        for (;k<arr.size();k++) if(arr[k]!=0) break;

        string ans = "";

        for(int i = arr.size()-1;i>=k;--i){
            ans = to_string(arr[i]) + ans;
        }
        return ans == "" ? "0" : ans;
    }
};