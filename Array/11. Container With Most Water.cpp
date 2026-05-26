class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        int maxWater = 0;
        int water = 0;
        while (left < right) {
            water = (right - left) * min(arr[left], arr[right]);
            maxWater = max(maxWater, water);

            if (arr[left] < arr[right])
                left++;
            else
                right--;
        }
        return maxWater;
    }
};
