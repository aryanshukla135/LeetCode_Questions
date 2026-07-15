class Solution {
void addOne(string &s) {
    int i = s.size() - 1;

    while (i >= 0 && s[i] == '1') {
        s[i] = '0';
        i--;
    }

    if (i >= 0)
        s[i] = '1';
    else
        s = '1' + s;
}
public:
    int numSteps(string s) {
        int n = s.length();

        string x = s ;

        int cnt =0 ;

        while(x != "1"){
           if(x.back() == '0'){
               x.pop_back();
           }else{
               addOne(x);
           }
           cnt++;
        }
        return cnt ;
    }
};
// 4 -> 100
// 2 -> 010
// 16 ->  10000
// 8->    01000

//       16 8 4 2 1
// 12 -> 01100
// 6-> 00110  here we can notice ine thing that for even when it get half all bit is shifted by one 
//  11 ->  01011
//  13 -> 01101 for odd we have noticed one thing that last bit is always 1 
//14 -> 01110
