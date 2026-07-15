class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd=n*n;
        int sumEven=n*(n+1);
        int x=min(sumOdd, sumEven);
        for(int i=x; i>=1; i--){
            if(sumOdd%i==0 && sumEven%i==0){
                return i;
            }
        }
        return 1;
    }
};