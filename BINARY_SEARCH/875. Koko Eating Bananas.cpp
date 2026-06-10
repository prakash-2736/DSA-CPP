// class Solution {
// public:
//     bool canEatwithKcapacity(vector<int>& piles, int capacity, int hours) {

//         for (int i = 0; i < piles.size(); i++) {
//             if (hours <= 0) {
//                 return false;
//             }
//             int banana = piles[i];
//             int hourItEat = (banana + capacity - 1) / capacity;
//             hours -= hourItEat;
//         }
//         return hours >= 0;
//     }
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int max = *max_element(piles.begin(), piles.end());
//         int l = 1;
//         int hi = max;

//         while (l < hi) {
//             int mid = l + ( ( hi - l) / 2) ;

//             if(canEatwithKcapacity(piles,mid,h)){
//                 hi = mid ;
//             }
//             else{
//                 l = mid+1 ;
//             }
//         }

//         return l ;
//     }
// };
class Solution {
public:
    long long solve(int speed, vector<int>& arr) {
        long long hours = 0;
        for (int x : arr) {
            hours += (x + speed - 1LL) / speed;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& arr, int k) {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hours = solve(mid, arr);
            if (hours <= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
