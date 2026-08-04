class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if((4*cheeseSlices-tomatoSlices)%2!=0){
            return {};
        }
        int x=(4*cheeseSlices-tomatoSlices)/2;
        int total_small=x;
        int total_jumbo=cheeseSlices-total_small;
        if(total_small<0 || total_jumbo<0){
            return {};
        }
        return {total_jumbo, total_small};
    }
};