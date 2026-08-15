class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end(), greater<int>());

        int maxi = 0;
        for (int i = 0; i < processorTime.size(); i++) {
            maxi = max(maxi, processorTime[i] + tasks[4 * i]);
        }

        return maxi;
    }
};
