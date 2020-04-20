class Solution {
public:
    double dp[105][105];
    double solve(vector<int>& A,int pos,int left) {
        if(pos>=A.size() || left<0)
            return 0;
        if(left==0)
        {
            double sum=0;
            for(int i=pos;i<A.size();i++)
            {
                sum+=A[i];
            }
            double x=(1.0*sum)/(A.size()-pos);
            dp[pos][left]=x;
            return x;
        }
        if(dp[pos][left]>0)
            return dp[pos][left];
        int i,sum=0;
        for(i=pos;i<A.size();i++)
        {
            sum+=A[i];
            double x=(1.0*sum)/(i+1-pos);
            dp[pos][left]=(double)max(dp[pos][left],x+solve(A,i+1,left-1));
        }
        return dp[pos][left];
    }
    double largestSumOfAverages(vector<int>& A, int K) {
        int n=A.size();
        for(int i=0;i<105;i++)
        {
            for(int j=0;j<105;j++)
                dp[i][j]=0;
        }
        double x= solve(A,0,K-1);
        return x;
    }
};
