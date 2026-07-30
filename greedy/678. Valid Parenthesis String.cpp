class Solution {
public:
    bool checkValidString(string s) {
        int l = 0;
        int h = 0;
        for (char c : s) {
            if (c == '(') {
                l++;
                h++;
            } else if (c == ')') {
                l--;
                h--;
            } else if (c == '*') {
                l--;
                h++;
            }

            if (l == -1)
                l = 0;
            if (h == -1)
                return false;
        }

        if (l == 0)
            return true;
        return false;
    }
};
