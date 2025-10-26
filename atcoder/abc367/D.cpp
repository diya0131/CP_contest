#define ll long long
class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        ll n=board.size(), m=board[0].size(), i, j, ma, k, a, b, c, d, t, res=INT_MIN;
        ll ma1[n][m], ma2[n][m];
        // *__
        // __*
        // _*_
        for(i=0;i<n;i++){
            ma=INT_MIN;
            for(j=0;j<m;j++){
               
                k=board[i][j];
                ma=max(ma, k);
                ma1[i][j]=ma;
            }
        }
        for(i=1;i<n;i++){
            for(j=0;j<m;j++){
                ma1[i][j]=max(ma1[i][j], ma1[i-1][j]);
            }
        }
        ll mar[n][m], mac[n][m];
        
        for(i=0;i<n;i++){
            ma=INT_MIN;
            for(j=m-1;j>=0;j--){
                mar[i][j]=ma;
                ma=max(ma, 0LL+board[i][j]);
            }
        }
        for(i=0;i<m;i++){
            ma=INT_MIN;
            for(j=n-1;j>=0;j--){
                mac[j][i]=ma;
                ma=max(ma, 0LL+board[j][i]);
                
            }
        }
        
        // for(i=0;i<n;i++){
        //     ma=INT_MIN;
        //     for(j=0;j<m;j++){
        //         cout<<mac[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(i=1;i<n-1;i++){
            for(j=1;j<m-1;j++){
                res=max(res, 0LL+ma1[i-1][j-1]+mar[i][j]+mac[i][j]);
            }
        }
        //---------------
        // __*
        // *__
        // _*_
        for(i=0;i<n;i++){
            ma=INT_MIN;
            for(j=m-1;j>=0;j--){
                k=board[i][j];
                ma=max(ma, k);
                ma1[i][j]=ma;
            }
        }
        for(i=1;i<n;i++){
            for(j=0;j<m;j++){
                ma1[i][j]=max(ma1[i][j], ma1[i-1][j]);
            }
        }
       
        
        for(i=0;i<n;i++){
            ma=INT_MIN;
            for(j=0;j<m;j++){
                mar[i][j]=ma;
                ma=max(ma, 0LL+board[i][j]);
            }
        }
        for(i=0;i<m;i++){
            ma=INT_MIN;
            for(j=n-1;j>=0;j--){
                mac[j][i]=ma;
                ma=max(ma, 0LL+board[j][i]);
                
            }
        }
        
        for(i=1;i<n-1;i++){
            for(j=1;j<m-1;j++){
                res=max(res, 0LL+ma1[i-1][j+1]+mar[i][j]+mac[i][j]);
            }
        }
        //----------
        // _*_
        // __*
        // *__
        for(i=0;i<n;i++){
            ma=INT_MIN;
            for(j=0;j<m;j++){
                k=board[i][j];
                ma=max(ma, k);
                ma1[i][j]=ma;
            }
        }
        for(i=n-2;i>=0;i--){
            for(j=0;j<m;j++){
                ma1[i][j]=max(ma1[i][j], ma1[i+1][j]);
            }
        }
       
        
        for(i=0;i<n;i++){
            ma=INT_MIN;
            for(j=m-1;j>=0;j--){
                mar[i][j]=ma;
                ma=max(ma, 0LL+board[i][j]);
            }
        }
        for(i=0;i<m;i++){
            ma=INT_MIN;
            for(j=0;j<n;j++){
                mac[j][i]=ma;
                ma=max(ma, 0LL+board[j][i]);
                
            }
        }
        
        for(i=1;i<n-1;i++){
            for(j=1;j<m-1;j++){
                res=max(res, 0LL+ma1[i+1][j-1]+mar[i][j]+mac[i][j]);
            }
        }
        //----------
        // _*_
        // *__
        // __*
        for(i=0;i<n;i++){
            ma=INT_MIN;
            for(j=m-1;j>=0;j--){
                k=board[i][j];
                ma=max(ma, k);
                ma1[i][j]=ma;
            }
        }
        for(i=n-2;i>=0;i--){
            for(j=0;j<m;j++){
                ma1[i][j]=max(ma1[i][j], ma1[i+1][j]);
            }
        }
       
        
        for(i=0;i<n;i++){
            ma=INT_MIN;
            for(j=0;j<m;j++){
                mar[i][j]=ma;
                ma=max(ma, 0LL+board[i][j]);
            }
        }
        for(i=0;i<m;i++){
            ma=INT_MIN;
            for(j=0;j<n;j++){
                mac[j][i]=ma;
                ma=max(ma, 0LL+board[j][i]);
                
            }
        }
        
        for(i=1;i<n-1;i++){
            for(j=1;j<m-1;j++){
                res=max(res, 0LL+ma1[i+1][j+1]+mar[i][j]+mac[i][j]);
            }
        }
        //---------------
        // __*
        // _*_
        // *__
        for(i=0;i<n;i++){
            ma=INT_MIN;
            for(j=m-1;j>=0;j--){
                k=board[i][j];
                ma=max(ma, k);
                ma1[i][j]=ma;
            }
        }
        for(i=1;i<n;i++){
            for(j=0;j<m;j++){
                ma1[i][j]=max(ma1[i][j], ma1[i-1][j]);
            }
        }
        for(i=0;i<n;i++){
            ma=INT_MIN;
            for(j=0;j<m;j++){
                k=board[i][j];
                ma=max(ma, k);
                ma2[i][j]=ma;
            }
        }
        for(i=n-2;i>=0;i--){
            for(j=0;j<m;j++){
                ma2[i][j]=max(ma2[i][j], ma2[i+1][j]);
            }
        }
        
        for(i=1;i<n-1;i++){
            for(j=1;j<m-1;j++){
                res=max(res, 0LL+board[i][j]+ma1[i-1][j+1]+ma2[i+1][j-1]);
            }
        }
        // ---
        for(i=0;i<n;i++){
            ma=INT_MIN;
            for(j=0;j<m;j++){
               
                k=board[i][j];
                ma=max(ma, k);
                ma1[i][j]=ma;
            }
        }
        for(i=1;i<n;i++){
            for(j=0;j<m;j++){
                ma1[i][j]=max(ma1[i][j], ma1[i-1][j]);
            }
        }
        for(i=0;i<n;i++){
            ma=INT_MIN;
            for(j=m-1;j>=0;j--){
                k=board[i][j];
                ma=max(ma, k);
                ma2[i][j]=ma;
            }
        }
        for(i=n-2;i>=0;i--){
            for(j=0;j<m;j++){
                ma2[i][j]=max(ma2[i][j], ma2[i+1][j]);
            }
        }
        
        for(i=1;i<n-1;i++){
            for(j=1;j<m-1;j++){
                res=max(res, 0LL+board[i][j]+ma1[i-1][j-1]+ma2[i+1][j+1]);
            }
        }
        cout<<res<<endl;
        
        
        return res;
    }
};