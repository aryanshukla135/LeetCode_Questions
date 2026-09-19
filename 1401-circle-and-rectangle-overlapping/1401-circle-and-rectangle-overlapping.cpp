class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
         int closex = max(x1,min(x2,xCenter));
         int closey = max(y1,min(y2,yCenter));

         double x = xCenter - closex;
         double y = yCenter - closey;

         double d = sqrt(x*x + y*y);

         return d <=radius;
    }
};