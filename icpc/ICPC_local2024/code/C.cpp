#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define _ <<" "<<

using namespace std;
ll mod = 1000000007;

int main(){
    ll n, m, k, i, j, s, t, mid;
    cin>>n>>m>>k;
    int path[n][m];
    bool vis[n+1][m+1];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            vis[i][j]=0;
        }
    }
    if(k>n*m-1){
        cout<<"IMPOSSIBLE"<<endl;

        return 0;
    }
    if(m%2){
        if(k<n+m-2){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        cout<<"POSSIBLE"<<endl;
        t = (k-n-m+2)/(n-1);
        mid = m - t;
        k -= n+m-2;
        // cout<<"t: " _ t<<endl;
        for(i=0;i<t;i++){
            cout<<n-1 _ m _ n _ m<<endl;
            vis[n-1][m]=1;
            // vis[n][m]=1;
            for(j=1;j<=n-2;j++){
                cout<<j _ m-i _ j+1 _ m-i<<endl;
                vis[j][m-i]=1;
                vis[j+1][m-i]=1;
            }
            if(i!=0){
                if(i%2==0){
                    cout<<n-1 _ m-i+1 _ n-1 _ m-i<<endl;
                    vis[n-1][m-i+1]=1;
                    vis[n-1][m-i]=1;
                }
                else{
                    cout<<1 _ m-i+1 _ 1 _ m-i<<endl;
                    vis[1][m-i+1]=1;
                    vis[1][m-i]=1;
                }
            }
        }
        i=t;
        k-=t*(n-1);
        if(k>0){
            mid--;
            if(i%2==0){
                cout<<n-1 _ m-i+1 _ n-1 _ m-i<<endl;
                vis[n-1][m-i+1]=1;
                vis[n-1][m-i]=1;
                k--;
                cout<<k<<endl;
                for(j=0;j<k;j++){
                    cout<< n-1-j _ m-i _ n-1-j-1 _ m-i<<endl;
                    vis[n-j-1][m-i]=1;
                    vis[n-j-2][m-i]=1;
                }
            }
            else{
                cout<<1 _ m-i+1 _ 1 _ m-i<<endl;
                vis[1][m-i+1]=1;
                vis[1][m-i]=1;
                k--;
                for(j=0;j<k;j++){
                    cout<< j+1 _ m-i _ j+2 _ m-i<<endl;
                    vis[j+1][m-i]=1;
                    vis[j+2][m-i]=1;
                }
            }
        }
        

        mid = (2+mid)/2;
        for(j=1;j<=n-1;j++){
            cout<<j _ mid _ j+1 _ mid<<endl;
            // vis[j][mid]=1;
            // vis[j+1][mid]=1;
        }
        for(i=1;i<=n;i++){
            for(j=2;j<=m;j++){
                if(vis[i][j]){
                    break;
                }
                cout<<i _ j-1 _ i _ j<<endl;
            }
        }

        // cout<<"Vis"<<endl;
        // for(i=1;i<=n;i++){
        //     for(j=1;j<=m;j++){
        //         cout<<vis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        

        return 0; 
    }
    
    if(n%2){
        int a=n;
        n=m;
        m=a;

        if(k<n+m-2){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        cout<<"POSSIBLE"<<endl;
        t = (k-n-m+2)/(n-1);
        mid = m - t;
        k -= n+m-2;
        // cout<<"t: " _ t<<endl;
        for(i=0;i<t;i++){
            cout<<m _ n-1 _ m _ n<<endl;
            // cout<<n-1 _ m _ n _ m<<endl;
            // vis[n-1][m]=1;
            vis[m][n-1]=1;
            
            for(j=1;j<=n-2;j++){
                cout<<m-i _ j _ m-i _ j+1<<endl;
                // cout<<j _ m-i _ j+1 _ m-i<<endl;
                // vis[j][m-i]=1;
                vis[m-i][j]=1;
                // vis[j+1][m-i]=1;
                vis[m-i][j+1]=1;

            }
            if(i!=0){
                if(i%2==0){
                    cout<< m-i+1 _ n-1 _ m-i _ n-1<<endl;
                    // cout<<n-1 _ m-i+1 _ n-1 _ m-i<<endl;
                    //  vis[m-i+1][n-1]=1;
                    // vis[m-i][n-1]=1;
                    vis[m-i+1][n-1]=1;
                    vis[m-i][n-1]=1;
                }
                else{
                    cout<< m-i+1 _ 1 _ m-i _ 1<<endl;
                    // cout<<1 _ m-i+1 _ 1 _ m-i<<endl;
                    // vis[m-i+1][1]=1;
                    // vis[m-i][1]=1;
                    vis[m-i+1][1]=1;
                    vis[m-i][1]=1;
                }
            }
        }
        i=t;
        k-=t*(n-1);
        if(k>0){
            mid--;
            if(i%2==0){
                cout<<m-i+1 _ n-1 _ m-i _ n-1<<endl;
                // cout<<n-1 _ m-i+1 _ n-1 _ m-i<<endl;
                // vis[n-1][m-i+1]=1;
                // vis[n-1][m-i]=1;
                vis[m-i+1][n-1]=1;
                vis[m-i][n-1]=1;
                k--;
                for(j=0;j<k;j++){
                    cout<< m-i _ n-1-j _ m-i _ n-1-j-1<<endl;
                    // cout<< n-1-j _ m-i _ n-1-j-1 _ m-i<<endl;
                    // vis[n-j-1][m-i]=1;
                    // vis[n-j-2][m-i]=1;
                    vis[m-i][n-j-1]=1;
                    vis[m-i][n-j-2]=1;
                }
            }
            else{
                cout<<m-i+1 _ 1 _ m-i _ 1<<endl;
                // cout<<1 _ m-i+1 _ 1 _ m-i<<endl;
                // vis[1][m-i+1]=1;
                // vis[1][m-i]=1;
                vis[m-i+1][1]=1;
                vis[m-i][1]=1;
                k--;
                for(j=0;j<k;j++){
                    cout<< m-i _ j+1 _ m-i _ j+2<<endl;
                    // cout<< j+1 _ m-i _ j+2 _ m-i<<endl;
                    // vis[j+1][m-i]=1;
                    // vis[j+2][m-i]=1;
                    vis[m-i][j+1]=1;
                    vis[m-i][j+2]=1;
                }
            }
        }
        

        mid = (2+mid)/2;
        for(j=1;j<=n-1;j++){
            cout<<mid _ j _ mid _ j+1<<endl;
            // cout<<j _ mid _ j+1 _ mid<<endl;
            // vis[j][mid]=1;
            // vis[j+1][mid]=1;
        }
        for(i=1;i<=n;i++){
            for(j=2;j<=m;j++){
                // if(vis[i][j]){
                if(vis[j][i]){
                    break;
                }
                // cout<<i _ j-1 _ i _ j<<endl;
                cout<<j-1 _ i _ j _ i<<endl;
            }
        }
        // cout<<"Vis"<<endl;
        // for(i=1;i<=m;i++){
        //     for(j=1;j<=n;j++){
        //         cout<<vis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }


        return 0;
    }
    if(k<n+m-1){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        cout<<"POSSIBLE"<<endl;
        t = (k-n-m+2)/(n-1);
        mid = m - t;
        k -= n+m-2;
        // cout<<"t: " _ t<<endl;
        for(i=0;i<t;i++){
            cout<<n-1 _ m _ n _ m<<endl;
            vis[n-1][m]=1;
            // vis[n][m]=1;
            for(j=1;j<=n-2;j++){
                cout<<j _ m-i _ j+1 _ m-i<<endl;
                vis[j][m-i]=1;
                vis[j+1][m-i]=1;
            }
            if(i!=0){
                if(i%2==0){
                    cout<<n-1 _ m-i+1 _ n-1 _ m-i<<endl;
                    vis[n-1][m-i+1]=1;
                    vis[n-1][m-i]=1;
                }
                else{
                    cout<<1 _ m-i+1 _ 1 _ m-i<<endl;
                    vis[1][m-i+1]=1;
                    vis[1][m-i]=1;
                }
            }
        }
        i=t;
        k-=t*(n-1);
        if(k>0){
            mid--;
            if(i%2==0){
                cout<<n-1 _ m-i+1 _ n-1 _ m-i<<endl;
                vis[n-1][m-i+1]=1;
                vis[n-1][m-i]=1;
                k--;
                cout<<k<<endl;
                for(j=0;j<k;j++){
                    cout<< n-1-j _ m-i _ n-1-j-1 _ m-i<<endl;
                    vis[n-j-1][m-i]=1;
                    vis[n-j-2][m-i]=1;
                }
            }
            else{
                cout<<1 _ m-i+1 _ 1 _ m-i<<endl;
                vis[1][m-i+1]=1;
                vis[1][m-i]=1;
                k--;
                for(j=0;j<k;j++){
                    cout<< j+1 _ m-i _ j+2 _ m-i<<endl;
                    vis[j+1][m-i]=1;
                    vis[j+2][m-i]=1;
                }
            }
        }
        

        mid = (2+mid)/2;
        for(j=1;j<=n-1;j++){
            cout<<j _ mid _ j+1 _ mid<<endl;
            // vis[j][mid]=1;
            // vis[j+1][mid]=1;
        }
        for(i=1;i<=n;i++){
            for(j=2;j<=m;j++){
                if(vis[i][j]){
                    break;
                }
                cout<<i _ j-1 _ i _ j<<endl;
            }
        }


}