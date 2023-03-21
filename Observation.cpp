#include<bits/stdc++.h>

using namespace std;

int h,num,inp,q,m,dat[10010]={0};
vector <int> graph[10010];

void dfs(int cur){
    for(int i=0;i<graph[cur].size();i++){
        dfs(graph[cur][i]);
        dat[cur]+=dat[graph[cur][i]];
    }
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);    
    cin>>num;
    for(int i=1;i<=num;i++){
        cin>>inp;
        if(!inp){
            h=i;
        }
        graph[inp].push_back(i);
    }
    cin>>q;
    while(q--){
        cin>>m>>inp;
        dat[m]=inp;
    }
    dfs(h);
    for(int i=1;i<=num;i++){
        cout<<dat[i]<<"\n";
    }
    return 0;
}
