class Solution {
	public:
	bool canPlace(vector<int>& arr, int dis, int cows) {
		
		int c = 1 ;
		int last = arr[0];
		
		for (int i = 1 ; i < arr.size() ; i++) {
			
			if (arr[i] - last >= dis) {
				c++;
				last = arr[i];
			}
		}
		if (c >= cows)
			return true;
		return false;
	}
	int aggressiveCows(vector<int> &arr, int k) {
		sort(arr.begin(), arr.end());
		int l = 1 ;
		
		int h = arr.back() - arr.front();
		int ans = h;
		
		while (l <= h) {
			int mid = (l + h) /2 ;
			
			if (canPlace(arr, mid, k)) {
				ans = mid ;
				l = mid + 1 ;
			}
			else {
				h = mid - 1 ;
			}
			
		}
		return ans;
	}
};
