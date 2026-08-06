class Solution {
public:
    int digitPRo(int n){
        int p = 1 ;
        while(n >0){
            p *= (n % 10 );
            n /= 10 ;
        }
        return p ;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(digitPRo(n) % t == 0){
                return n ;
            }
            n++ ;
        }

        return -1 ;
    }
};
