class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.length();

        long long c = 0;
        int i = 0;
        while (i < n) {

            if (s1[i] == '0' && s2[i] == '1') {

                i++;
                c++;
            } else if (s1[i] == '1' && s2[i] == '0') {

                int j = i;

                while (j < n && s1[j] == '1' && s2[j] == '0')
                    j++;
                int l = j- i ;
                if(l ==1 && n  == 1){
                    return -1;
                } 

                c += (long long)(l /2) * 1 + ( long long )(l % 2) * 2 ;
                i = j;
                    
            }
            else{
                i++;
            }
        }

        return (int) c;
    }
};
