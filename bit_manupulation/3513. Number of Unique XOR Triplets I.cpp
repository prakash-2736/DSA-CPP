class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
       int n = nums.size();
        
        if (n <= 2) {
            return n;
        }
        
        // Find the number of bits needed to represent n
        // std::__lg(n) returns the index of the highest set bit (0-indexed)
        int bit_length = std::__lg(n) + 1;
        
        // The number of unique values is 2^bit_length
        return 1 << bit_length; 
    }
};
