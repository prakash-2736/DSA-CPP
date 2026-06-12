class Solution {
	public:
	bool countTime(vector<int>& arr, int times, int k) {
		
		int c = 1 ;
		int total_time = 0 ;
		
		for (auto num : arr) {
			
			if (num + total_time <= times) {
				total_time += num ;
			}
			else {
				c++;
				total_time = num ;
			}
		}
		
		return c <= k;
	}
	int minTime(vector<int>& arr, int k) {
		if (arr.size() < k)
			return - 1;
		int l = *max_element(arr.begin(), arr.end());
		int h = accumulate(arr.begin(), arr.end(), 0);
		
		int ans = -1 ;
		
		while (l <= h) {
			
			int mid = (l + h) /2 ;
			
			if (countTime(arr, mid, k)) {
				ans = mid ;
				h = mid - 1 ;
			}
			else {
				l = mid + 1 ;
			}
		}
		return ans; 
		
	}
};
