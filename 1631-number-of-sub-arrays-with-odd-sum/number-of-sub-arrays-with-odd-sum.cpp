class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long odd_count= 0;
        long long even_count= 1;
        long long current_sum= 0;
        long long total_odds= 0;
        int MOD= 1e9+7;
        for(int num: arr){
            current_sum+=num;
            if(current_sum%2!=0){
                total_odds= (total_odds+even_count)%MOD;
                odd_count++;
            }else{
                total_odds= (total_odds+odd_count)%MOD;
                even_count++;
            }
        }
        return total_odds;
    }
};