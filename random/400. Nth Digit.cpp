class Solution {
public:
    int findNthDigit(int n) {
        long long a = 9;
        int b = 1;
        int l = 1;
        while (n > a * l) {
            n = n - a * l;
            l++;
            b = b * 10;
            a = a * 10;
        }
        b = b + (n - 1) / l;
        string s = to_string(b);
        return s[(n - 1) % l] - '0';
    }
};
