class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int minLength = n + 1;
        string result = "";
        int onesCount = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            if (s[right] == '1') {
                onesCount++;
            }

            while (onesCount == k) {
                if (s[left] == '1') {
                    int currentLength = right - left + 1;

                    if (currentLength < minLength) {
                        minLength = currentLength;
                        result = s.substr(left, currentLength);
                    } else if (currentLength == minLength) {
                        string currentStr = s.substr(left, currentLength);
                        if (currentStr < result) {
                            result = currentStr;
                        }
                    }

                    onesCount--;
                }
                left++;
            }
        }

        return result;
    }
};
