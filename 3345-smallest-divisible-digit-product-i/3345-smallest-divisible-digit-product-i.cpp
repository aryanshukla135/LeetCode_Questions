class Solution {
private:
    int digitprod(int i){
           int prod = 1 ;
           while(i>0){
              int rem = i % 10 ;
              prod *=rem ;
              i /= 10 ;
           }
           return prod ;
    }
public:
    int smallestNumber(int n, int t) {
       
        for(int i = n ; i<=100 ; i++){
            int prod = digitprod(i);
            cout<<prod<<endl;
            if(prod % t == 0 || prod == 0){
                return i;
            }
        }
        return 0 ;
    }
};