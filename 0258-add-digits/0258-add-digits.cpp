class Solution {
public:
    int addDigits(int num) {
        int x,y;
        while(num>=10){
            y=0;
        while(num!=0){
            x=num%10;
            y=y+x;
            num=num/10;
        }
        num=y;
        }
        return num;
    }
};