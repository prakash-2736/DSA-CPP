class Solution {
public:
    string processStr(string s) {
        string result = "";

        for (char c : s) {
            if (islower(c)) {
                result += c;
            } else if (c == '*' && result.length() > 0) {
                result.pop_back();
            } else if (c == '#') {
                result += result;
            } else if (c == '%' && result.length() > 1) {
                reverse(result.begin(), result.end());
            }
        }
        return result;
    }
};
