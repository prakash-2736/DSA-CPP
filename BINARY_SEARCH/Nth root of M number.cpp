#include <bits/stdc++.h>
using namespace std;

class solution {
   public:
    int findNthrootofM(int n, int m) {
        int low = 1, high = m / n;

        while (low <= high) {
            int mid = low + ((high - low) / 2);

            long long ans = 1;
            for (int i = 0; i < n; i++) {
                ans *= mid;
                if (ans > m)
                    break;
            }

            if (ans == m)
                return mid;

            if (ans < m)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }
};
