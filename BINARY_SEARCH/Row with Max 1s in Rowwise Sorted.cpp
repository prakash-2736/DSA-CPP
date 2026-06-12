class Solution {
	public:
	// 	int total_sum(vector<int> &a) {
	// 		return accumulate(a.begin(), a.end(), 0);
	// 	}
	int rowWithMax1s(vector<vector<int>> &arr) {
		
		int maxi = 0 ;
		int ans = -1 ;
		
		for (int i = 0 ; i < arr.size() ; i++) {
			int ones = arr[i].end() - lower_bound(arr[i].begin(), arr[i].end(), 1);
			if (ones > maxi) {
				maxi = ones;
				ans = i ;
			}
		}
		
		return ans;
	}
};
