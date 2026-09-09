class Solution {
public:
    int minFlips(int a, int b, int c) {
        int x = a | b ;
        if(x == c){
            return 0;
        }
        int cnt =0 ;
        while(a != 0 || c != 0 || b != 0){
            int bit1 = a & 1;
            int bit2 = b & 1 ;
            int bit3 =c & 1 ;

            if(bit3 == 0){
                if(bit1==1){
                    cnt++;
                }
                if(bit2 == 1){
                    cnt++;
                }
            }else{
                if(bit1 ==0 && bit2 ==0){
                    cnt++;
                }
            }

            a = a >> 1;
            b = b >> 1 ;
            c = c >> 1 ;
           
        }
        return cnt;
    }
};