#include<bits/stdc++.h>

using namespace std;


struct node {
    int x;
    int y;
    int val;
};


int main() {
    node nd, new_nd;
    queue < node > q;
    vector < pair < int , int> > add = {{2, 1},{1, 2},{-1, 2}, {-2, 1}, {-2, -1},{-1, -2},{1, -2}, {2, -1}};
    int n;
    cin>>n;
    bool check[n][n];
    int  res[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            check[i][j]=0;
        }
    }
    int nx, ny;
    nd.x = 0;
    nd.y = 0;
    nd.val = 0;
    q.push(nd);
    while(!q.empty()) {
        nd = q.front();
        q.pop();
        if(check[nd.x][nd.y]) continue;
        check[nd.x][nd.y]=1;
        res[nd.x][nd.y]= nd.val;
        for( int i=0;i<8;i++){
            nx = nd.x+add[i].first;
            ny = nd.y+add[i].second;
            new_nd.x = nx;
            new_nd.y = ny;
            new_nd.val = nd.val+1;
            if(nx>=0 && nx<n && ny>=0 && ny<n && !check[nx][ny]) q.push(new_nd);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<res[i][j]<<"   ";
        }
        cout<<endl;
    }

}