class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenE = false;

        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];

            if (isdigit(ch)) {
                seenDigit = true;
            } else if (ch == '+' || ch == '-') {
                // Signs can only appear at the beginning or right after 'e' /
                // 'E'
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else if (ch == '.') {
                // Dot is invalid if we already saw a dot or an exponent
                if (seenDot || seenE) {
                    return false;
                }
                seenDot = true;
            } else if (ch == 'e' || ch == 'E') {
                // Exponent is invalid if we already saw 'e' or haven't seen a
                // digit yet
                if (seenE || !seenDigit) {
                    return false;
                }
                seenE = true;
                seenDigit = false; // Reset to ensure digits follow the exponent
            } else {
                // Any other character is strictly invalid
                return false;
            }
        }

        // Must end with a valid digit sequence
        return seenDigit;
    }
};
