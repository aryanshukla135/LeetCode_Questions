class Solution {
public:
    int convertTime(string current, string correct) {
         int h1 = current[0] - '0';
         int h2 = current[1] - '0';
         int m1 = current[3] - '0';
         int m2 = current[4] - '0';

         int h3 = correct[0] - '0';
         int h4 = correct[1] - '0';
         int m3 = correct[3] - '0';
         int m4 = correct[4] - '0';
       
         int hrs1 = (h1*10 + h2)*60;

         int min1 = m1 *10 + m2 ;
         int total = hrs1 + min1 ;
         int hrs2 = (h3*10 + h4)*60;

         int min2 = m3 *10 + m4 ;
         int target = hrs2 + min2 ;
         int req = target - total;
        
         int sum = 0;
         int cnt =0;
    
             while(req != sum && req-sum >= 60){
                sum += 60 ;
                cnt++;
             }
             while(req != sum && req -sum >= 15){
                sum += 15 ;
                cnt++;
             }
            while(req != sum && req-sum >= 5){
                sum += 5 ;
                cnt++;
             }
             while(req != sum && req-sum >= 1){
                sum += 1 ;
                cnt++;
             }

         return cnt ;

    }
};