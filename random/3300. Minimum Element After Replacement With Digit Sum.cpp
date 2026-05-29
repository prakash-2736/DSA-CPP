class Solution {
public:
    int sum(int val) {

        int sum = 0;

        while (val > 0) {
            int x = val % 10;
            val /= 10;
            sum += x;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {

        int mini = INT_MAX;

        for (int num : nums) {

            mini = min(mini, sum(num));
        }
        return mini ;
    }
};
