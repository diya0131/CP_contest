#include<bits/stdc++.h>
using namespace std;

int t[120000];

bool cmp(vector<int>& a, vector<int>& b) {
	return a[0]>b[0];
}
void buildt( int v, int l, int r){
	if(l == r){
		t[v] = 0;
	}else{	
		int mid = (l+r)/2;
		buildt(2*v, l, mid);
		buildt(2*v+1, mid+1, r);
		t[v] = t[2*v] + t[2*v+1]; 	
	}
}

int sum(int v, int tl, int tr, int l, int r) {
	
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}
void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        t[v] = 1;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos);
        else
            update(v*2+1, tm+1, tr, pos);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int main(){
	
	int l,r,k,q,n;
	cin>>n;
	int j = n;
	pair<int, int> arr[n];
	for(int i = 0 ; i < n; i++){
		cin>>arr[i].first;
		arr[i].second = i;
	}
	cin>>q;
	vector<vector<int> > a;
	vector< int > b;
	b.push_back(0);
	b.push_back(0);
	b.push_back(0);
	b.push_back(0);
	int res[q];
	for(int i = 0; i < q; i++){
		a.push_back(b);
		cin>> a[i][1] >> a[i][2] >> a[i][0];
		a[i][3]=i;
		a[i][1]--;
		a[i][2]--;
	}
	sort(a.begin(), a.end(), cmp);
	sort(arr, arr + n);
	buildt(1, 0, n-1);
	j--;
	for(int i = 0; i < q; i++){
		while(j > -1 && arr[j].first > a[i][0]){
			update(1, 0, n-1, arr[j].second);
			j--;
		}
		res[a[i][3]]=sum(1, 0, n-1, a[i][1],a[i][2]);
		
	}
	for(int i=0;i<q;i++){
		cout<<res[i]<<endl;
	}
	
	
	return 0;
}