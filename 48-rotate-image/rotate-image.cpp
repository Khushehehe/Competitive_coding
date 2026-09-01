class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix[i].size();j++){
                if(i==j){
                    continue;
                }
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        int n=matrix.size()-1;
        int a=0;
        int b=n;
        while(a<b){
            for(int i=0;i<=n;i++){
                swap(matrix[i][a], matrix[i][b]);
            }
            a++;
            b--;
        }
    }
};