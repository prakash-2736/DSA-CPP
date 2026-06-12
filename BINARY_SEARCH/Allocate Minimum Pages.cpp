class Solution {
	public:
	bool countPages(vector<int>& arr, int pages, int k) {
		
		int c = 1 ;
		int total_pages = 0 ;
		
		for (auto num : arr) {
			
			if (num + total_pages <= pages) {
				total_pages += num ;
			}
			else {
				c++;
				total_pages = num ;
			}
		}
		
		return c <= k;
		
	}
	int findPages(vector<int> &arr, int k) {
		if (arr.size() < k)
			return - 1;
		int l = *max_element(arr.begin(), arr.end());
		int h = accumulate(arr.begin(), arr.end(), 0);
		
		int ans = -1 ;
		
		while (l <= h) {
			
			int mid = (l + h) /2 ;
			
			if (countPages(arr, mid, k)) {
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
