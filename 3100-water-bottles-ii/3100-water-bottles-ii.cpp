class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
         int fullbottle = 0;
         int emptybottle = 0 ;
         int bottledrunk = 0;
         
         bottledrunk += numBottles ;
         numBottles =0 ;
         emptybottle = bottledrunk;

         while(fullbottle + emptybottle >= numExchange){
            if(emptybottle >= numExchange){
                fullbottle++;
                emptybottle -= numExchange;
                numExchange++;
            }else{
                bottledrunk += fullbottle ;
                 emptybottle += fullbottle ;
                 fullbottle = 0 ;
            }
         }
         bottledrunk += fullbottle;
         return bottledrunk;
    }
};