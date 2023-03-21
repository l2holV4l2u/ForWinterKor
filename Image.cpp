#include<bits/stdc++.h>

using namespace std;

int num,x[110][2],y[110][2],par[110],a,b,cnt=0,temp[110]={0};
    
bool isoverlap(int a,int b){
    return !(y[a][1]<y[b][0]||y[a][0]>y[b][1]||x[a][1]<x[b][0]||x[a][0]>x[b][1]);
}

int fp(int cur){
    if(par[cur]==cur){
        return cur;
    }
    return par[cur]=fp(par[cur]);
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>num;
    for(int i=0;i<num;i++){
        par[i]=i;
        cin>>x[i][0]>>y[i][0]>>x[i][1]>>y[i][1];
        vector <int> temp;
        for(int j=0;j<i;j++){
            if(isoverlap(i,j)){
                temp.push_back(j);
            }
        }
        if(temp.size()){
            a=fp(temp[0]),par[i]=a;
            for(int j=1;j<temp.size();j++){
                b=fp(temp[j]),par[b]=a;
            }
        }
    }
    for(int i=0;i<num;i++){
        a=fp(i);
        cnt+=(temp[a]==0);
        temp[a]=1;
    }
    cout<<cnt;
    return 0;
}
/*
3
1 4 4 8
2 1 5 6
7 3 10 7
*/
