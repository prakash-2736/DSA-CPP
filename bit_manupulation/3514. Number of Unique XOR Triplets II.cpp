class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int max_val = 0;
        for (int num : nums) {
            max_val = max(max_val, num);
        }

        int upper_limit = max_val << 1;
        if (upper_limit == 0)
            upper_limit = 1;

        vector<bool> pair_exists(upper_limit, false);
        for (int a : nums) {
            for (int b : nums) {
                pair_exists[a ^ b] = true;
            }
        }

        vector<bool> triplet_exists(upper_limit, false);
        for (int pair_xor = 0; pair_xor < upper_limit; ++pair_xor) {
            if (pair_exists[pair_xor]) {
                for (int c : nums) {
                    triplet_exists[pair_xor ^ c] = true;
                }
            }
        }

        int unique_triplets_count = 0;
        for (bool exists : triplet_exists) {
            if (exists) {
                unique_triplets_count++;
            }
        }

        return unique_triplets_count;
    }
};
