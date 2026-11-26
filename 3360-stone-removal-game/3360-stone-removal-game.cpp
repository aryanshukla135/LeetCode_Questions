class Solution {
public:
    bool canAliceWin(int n) {
         int i = 10 ;
         bool temp = true ;

         while(1){
            if(temp){
                if(i > n){
                    return false;
                }
                n -= i ;
                --i;
                temp = !temp ;
            }else{
                if(i > n){
                    return true;
                }
                n -= i ;
                --i;
                temp = !temp ;
            }
         }
        return false;
    }
};