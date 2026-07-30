class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();

        int fi =0, ten = 0, twe = 0;

        for (int num : bills) {
            if (num == 5) {
                fi++;
            } 
            else if (num == 10) {

                ten++;
                if (fi >= 1) {
                    fi--;
                } else {
                    return false;
                }
            }

            else if (num == 20) {
                twe++;
                if (ten >= 1 && fi >= 1) {
                    ten--;
                    fi--;
                } else if (fi >= 3) {
                    fi -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
