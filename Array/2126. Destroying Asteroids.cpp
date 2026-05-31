class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        long sum = mass;
        for (int i = 0; i < arr.size(); i++) {
            if (sum >= arr[i]) {
                sum += arr[i];                                             /// tc : O(nlogn)    sc: o(logn) for stack for sort 
            }
            else return false;
        }

        return true;


 // int maxasteroid = 0;
 //        for(int a : asteroids) {
 //            if(a > maxasteroid) maxasteroid = a;
 //        }
 //        vector<int> freq(maxasteroid + 1, 0);
 //        for(int a : asteroids) {
 //            freq[a]++;
 //        }                                                                          using counting sort tc : Time Complexity: O(N+M)
                                                                                        // N = no. of asteroids, M = maximum mass among all asteroids
                                                                                        // Space Complexity: O(M)
                                                                                                  // array of size M+1
//        long long currentmass = mass;
 //        for(int i = 1; i <= maxasteroid; i++) {
 //            if(freq[i] > 0) {
 //                if(i > currentmass) return false;
 //                currentmass += (long long)i * freq[i];
 //            }
 //        }
 //        return true;


      
    }
};
