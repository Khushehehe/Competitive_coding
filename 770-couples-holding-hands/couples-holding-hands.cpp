class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        vector<int> numToIndex(n);
        for(int i=0;i<n;i++){
            numToIndex[row[i]]=i;
        }
        int minSwaps=0;
        for(int i=0;i<n;i+=2){
            if(row[i]%2==0){
                if(row[i+1]==row[i]+1){
                    continue;
                }
                int neededIndex=numToIndex[row[i]+1];
                int other= row[i+1];
                swap(row[i+1], row[neededIndex]);
                numToIndex[row[i]+1]= i + 1;
                numToIndex[other]= neededIndex;
                minSwaps++;
            }else{
                if(row[i+1]==row[i]-1){
                    continue;
                }
                int neededIndex= numToIndex[row[i]-1];
                int other=row[i+1];
                swap(row[i+1], row[neededIndex]);
                numToIndex[row[i]-1]= i+1;
                numToIndex[other]= neededIndex;
                minSwaps++;
            }
        }
        return minSwaps;
    }
};