
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lastLower[26];
        int firstUpper[26];
        
        for (int i = 0; i < 26; ++i) {
            lastLower[i] = -1;
            firstUpper[i] = -1;
        }
        
        int n = word.length();
        for (int i = 0; i < n; ++i) {
            char c = word[i];
            if (c >= 'a' && c <= 'z') {
                lastLower[c - 'a'] = i;  
            } else {
                int idx = c - 'A';
                if (firstUpper[idx] == -1) {
                    firstUpper[idx] = i; 
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (lastLower[i] != -1 && firstUpper[i] != -1 && lastLower[i] < firstUpper[i]) {
                count++;
            }
        }
        
        return count;
    }
};
