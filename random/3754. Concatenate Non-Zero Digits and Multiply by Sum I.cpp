class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        long res = 0 ;
        long sum = 0 ;


        for(char c : s){
            int a = c - '0';
            if(a > 0){
                res = res * 10 +( c - '0');
                sum += (c - '0');
            }
        }

        long ans = sum * res;

        return ans;
    }
};
