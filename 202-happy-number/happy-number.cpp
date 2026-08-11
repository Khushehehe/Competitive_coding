class Solution {
public:
    int ss(int n){
        int sum=0;
        while(n!=0){
            int d=n%10;
            n=n/10;
            sum+=d*d;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=ss(n);
        int fast=ss(ss(n));
        while(slow!=fast){
            slow=ss(slow);
            fast=ss(ss(fast));
        }
        if(slow==1){
            return true;
        }
        return false;
        // set<int>seen;
        // while(n!=1){
        //     if(seen.count(n)){
        //         return false;
        //     }
        //     seen.insert(n);
        //     int sum=0;
        //     while(n>0){
        //         int digit= n%10;
        //         sum+= digit* digit;
        //         n/=10;
        //     }
        //     n=sum;
        // }
        // return true;
    }
};