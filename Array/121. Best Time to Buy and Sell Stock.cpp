class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m =  INT_MAX;
        int arr= 0;
        for (int i =0;i < prices.size();i++){
           m = min(m,prices[i]);
            arr = max(arr,prices[i]-m);
        }
        return arr;
    }
};
