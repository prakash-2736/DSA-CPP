class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();

        string half = s.substr(0, n / 2);

        sort(half.begin(), half.end());

        string first_half = half;

        reverse(half.begin(), half.end());

        if (n % 2 != 0) {
            return first_half + s[n / 2] + half;
        }

        return first_half + half;
    }
};
