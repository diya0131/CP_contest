#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long i, k, j, n, s, q, t;
    vector < long long > pr;
    vector < long long  > sum;
    int ma = 1000001;
    bool a[ma];
    for(int i=2;i<ma;i++){
        if(!a[i]){
            pr.push_back(i);
            k = i;
            while(k<ma){
                a[k]=1;
                k+=i;
            }
        }
    }
    long long pre = 1, most=0;
    long long res[1001];
    for(int i=0;i<1001;i++) res[i]=100000;
    
    for(i=2;i<10001;i++){
        t=i;
        if(i%2) s=1;
        else s=0;
        k=2;
        q=1;
        while(t>1){
            while(t%k==0){
                s++;
                t/=k;
            }
            q*=s;
            s=1;
            k++;
        }
        if(pre*q<1001){
            res[pre*q]=min(res[pre*q], i-1);
            most = max(most, pre*q);
            if(most>=1000) {
                cout<<i<<"at last\n";
                break;
            }
        }
        pre = q;
    }
    cin>>n;
    cout<<"hemm"<<most<<endl;
    
    for(i=1;i<20;i++){
        cout<<i<<": "<<res[i]<<endl;
    }
    for(int i=0;i<n;i++){
        cin>>i;
        cout<<res[i]<<endl;
    }
    
      
    return 0;
}
