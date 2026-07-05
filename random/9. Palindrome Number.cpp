class Solution {
public:
    bool isPalindrome(int num) {
        if(num < 0 ) return false;
        int originalNum = num;
        long long reversedNum = 0;
        int remainder;

        while (num != 0) {
            remainder = num % 10;
            reversedNum = reversedNum * 10 + remainder;
            num /= 10;
        }

        if (originalNum == reversedNum) {
            return true;
        }

        return false;
    }
};
