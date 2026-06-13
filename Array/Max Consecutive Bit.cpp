class Solution {
	public:
	int maxConsecBits(vector<int> &arr) {
		int c0 = 0 ;
		int c1 = 0 ;
		int max_len = 0 ;
		for (int ar : arr) {
			
			if (ar == 0) {
				c0++;
				c1 = 0;
			} if (ar == 1) {
				c1++;
				c0 = 0 ;
			}
			
			max_len = max(max_len, max(c0, c1));
		}
		return max_len;
	}
};
