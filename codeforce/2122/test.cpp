int a;

int cnt[10]={0};
while(t>0){
    cnt[t%10]++;
    t/=10;
}
int mn=1000, res=-1;
for(int i=0;i<10;i++){
    if(mn>cnt[i]){
        mn = cnt[i];
        res = i;
    }
}