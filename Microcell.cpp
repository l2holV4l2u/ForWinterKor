#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll num,k,dat[50010],u,v,cnt=0,sum=0;
    
vector <ll> graph[50010];

void dfs(int cur,int par){
    for(int i=0;i<graph[cur].size();i++){
        if(graph[cur][i]!=par){
            dfs(graph[cur][i],cur);
            dat[cur]+=dat[graph[cur][i]];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>num>>k;
    for(int i=1;i<=num;i++){
        cin>>dat[i];
        sum+=dat[i];
    }
    for(int i=1;i<num;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1,-1);
    for(int i=2;i<=num;i++){
        cnt+=abs(sum-(2*dat[i]))<=k;
    }
    cout<<cnt;
    return 0;
}
/*
8 4
1 1 1 1 1 1 1 1
1 5
1 3
1 7
5 4
5 2
5 6
3 8

12 314
39 44 66 -4 -31 44 17 25 74 -37 71 3
1 2
1 11
2 3
2 8
2 9
3 4
4 5
4 6
6 7
8 10
11 12

*/
