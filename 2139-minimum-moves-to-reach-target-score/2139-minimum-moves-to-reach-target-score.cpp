class Solution {
public:
    int minMoves(int target, int maxDoubles) {
          int x = target ;

          int cnt =0 ;
          if(maxDoubles == 0){
                cnt += (x-1);
                return cnt ;
             }

          while(x != 1){
             if(x % 2 != 0){
                x--;
                cnt++;
             }else{
                if(maxDoubles > 0){
                  x /= 2 ;
                  cnt++;
                  maxDoubles--;
                }else{
                    x--;
                    cnt++;
                } 
             }
             if(maxDoubles == 0){
                cnt += (x-1);
                break ;
             }
          }
          return cnt ;
    }
};
// start from end of the target and 
// if you get any integer that is not divisible by 2 then decrement by 1 and 
// if it is divisible by 2 then divide it 