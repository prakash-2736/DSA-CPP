class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        int n = fruits.size();
        vector<int> used(n, 0);

        int unplaced = 0;

        for (int fruit : fruits) {

            bool placed = false;

            for (int i = 0; i < n; i++) {

                if (!used[i] && baskets[i] >= fruit) {
                    used[i] = 1;
                    placed = true;
                    break;
                }
            }

            if (!placed)
                unplaced++;
        }

        return unplaced;
    }
};
