#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll num,k,dat[500010],ban[500010],dp[500010]={0},flag,temp;
    
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>num>>k;
    for(int i=1;i<=num;i++){
        cin>>dat[i];
    }
    for(int i=1;i<=num;i++){
        cin>>ban[i];
    }
    if(num<=10000){
        memset(dp,1,sizeof(dp));
        dp[1]=0;
        for(int i=2;i<=num;i++){
            //ทำ sliding window ต่อ
            for(int j=max(1ll,i-k);j<i;j++){
                if(ban[j]!=i){
                    dp[i]=min(dp[i],dp[j]+dat[j]);
                }
            }
            
        }
        cout<<dp[num];
        return 0;
    }
    deque <ll> dq;
    dq.push_back(1);
    dp[1]=dat[1];
    for(int i=2;i<=num;i++){
        while(dq.size()){
            if(dq.front()<i-k){
                dq.pop_front();
            }
            else{
                break;
            }
        }
        for(int j=0;j<dq.size();j++){
            if(i!=ban[dq[j]]){
                dp[i]=dp[dq[j]]+dat[i];
                break;
            }
        }
        if(!dp[i]){
            continue;
        }
        flag=0;
        while(dq.size()){
            if(dp[dq.back()]>dp[i]){
                temp=dq.back();
                dq.pop_back();
                flag=1;
            }
            else{
                break;
            }
        }
        dq.push_back(i);
        if(flag){
            dq.push_back(temp);
        }
    }
    cout<<dp[num]-dat[num];
    return 0;
}
