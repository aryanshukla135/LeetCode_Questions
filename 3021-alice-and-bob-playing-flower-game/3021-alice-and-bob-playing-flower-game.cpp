class Solution {
public:
    long long flowerGame(int n, int m) {
         int totaleven = m/2 ;
         int totalodd = m - totaleven ;

         long long ans =0 ;

         for(int i =1 ; i<= n; i++){

            if(i&1){
               ans +=totaleven ;
            }else{
               ans +=totalodd ;
            }

         }
       
         return ans ;

        
    }
};
// even + even never odd ;
//even + odd  = odd 
//1 2 3 4 5 6 7 8 9   ->  4 even ans 5 odd 
// totalnumber/2 == even ans rest is odd ;