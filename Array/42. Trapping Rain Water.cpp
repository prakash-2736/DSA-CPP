class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> suff(n);
        
        suff[n-1] = arr[n-1];

        for(int i = n-2 ; i>=0 ; i--){
            suff[i] = max(suff[i+1] , arr[i]);
        }
        int left_max = INT_MIN ;
        int water = 0;
        for(int i =0 ; i< n ; i++){
         left_max = max(left_max , arr[i]);

         if(arr[i] < min(left_max , suff[i])){
            water += min(left_max , suff[i]) - arr[i];
         }   
        }

        return water ;

      // int left_max =0;
      //  int right_max = 0 ;
      //   int left  =0 , right = n-1;


      //   while(left < right){

      //       if(left_max <= right_max){


      //           if(arr[left] > left_max) left_max = arr[left] ;
      //           else{
      //               water += left_max - arr[left];
      //               left++;
      //           }

      //       }
      //       else{
      //             if(arr[right] > right_max) right_max = arr[left] ;
      //           else{
      //               water += right_max - arr[right];
      //               right--;
      //           }
 
      //       }
      //   }
      //   return water;
    }
};
