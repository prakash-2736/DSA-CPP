class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> result;

        int min_len = to_string(low).length();
        int max_len = to_string(high).length();

        for (int len = min_len; len <= max_len; ++len) {
            for (int start = 0; start <= 9 - len; ++start) {
                string sub = digits.substr(start, len);
                int num = stoi(sub);

                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        return result;
    }
};
