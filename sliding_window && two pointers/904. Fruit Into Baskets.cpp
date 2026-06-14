class Solution {
public:
    int totalFruit(vector<int>& arr) {
        // int l = 0;
        // unordered_map<int,int> mp;
        // int n = arr.size();
        // int ans = 0 ;
        // for (int r = 0; r < n; r++) {

        //     mp[arr[r]]++;

        //     while (mp.size() > 2) {

        //         mp[arr[l]]--;

        //         if (mp[arr[l]] == 0)
        //             mp.erase(arr[l]);

        //         l++;
        //     }

        //     ans = max(ans, r - l + 1);
        // }
        // return ans;
        int maxlen = 0;
        int lastfruit = -1;
        int secondlastfruit = -1;
        int currcount = 0;
        int lastfruitstreak = 0;

        for (int fruit : arr) {

            if (fruit == lastfruit || fruit == secondlastfruit) {
                currcount++;
            } else {
                currcount = lastfruitstreak + 1;
            }

            if (fruit == lastfruit) {
                lastfruitstreak++;
            } else {
                lastfruitstreak = 1;
                secondlastfruit = lastfruit;
                lastfruit = fruit;
            }

            maxlen = max(maxlen, currcount);
        }

        return maxlen;
    }
};
