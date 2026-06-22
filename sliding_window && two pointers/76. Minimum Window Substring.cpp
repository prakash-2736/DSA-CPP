class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        string res = "";
        if (m < n)
            return "";
        vector<int> freq(256, 0);
        for (char c : t) {
            freq[c]++;
        }
        // int mini = INT_MAX;
        // for (int i = 0; i < m; i++) {
        //     vector<int> temp = freq;
        //     int c = 0;
        //     for (int j = i; j < m; j++) {              tc : TLE 

        //         if (temp[s[j]] > 0) {

        //             c++;
        //             temp[s[j]]--;
        //         }

        //         if (c == n) {
        //             if (mini > j - i + 1) {
        //                 res = s.substr(i, j - i + 1);
        //                 mini = j - i + 1;
        //                 break;
        //             }
        //         }
        //     }
        // }

        // return res;




       int i = 0, j = 0, c = 0;
        int s_i = -1;
        int len = INT_MAX ;

            while (j < m) {

            if (freq[s[j]] > 0)
                c++;

            freq[s[j]]--;

            while (c == n) {

                if (j - i + 1 < len) {
                    len = j - i + 1;
                    s_i = i;
                }

                freq[s[i]]++;
                if (freq[s[i]] > 0)
                    c--;

                i++;
            }
            j++;
        }
        if (s_i == -1)
            return "";
        return s.substr(s_i, len);
    }
};
