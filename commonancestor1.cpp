#include<bits/stdc++.h>
using namespace std;

vector<int>parent(1e5),level(1e5);

void dfs(int node,int l,vector<vector<int>>&g){
   level[node]=l;
   for(int child:g[node]){
    parent[child]=node;
    dfs(child,l+1,g);
   }
}

int lca(int u,int v){
    //if level of v is less than level of u
    if(level[u]>level[v]){
        swap(u,v);
    }
    

    //assuming level of v is greater than level of u
    //to make level of u and v same
    while(level[u]!=level[v]){
        v=parent[v];
    }

    if(u==v)return u;

    //else after having same level keep searching for the common parent upwards
    while(u!=v){
        u=parent[u];
        v=parent[v];
    }
    return u;
}


int main(){
    int n;cin>>n;
    vector<vector<int>>g(n+1);

    //graph input
    for(int i=1;i<=n;i++){
       int count;cin>>count;
       for(int j=0;j<count;j++){
         int x;cin>>x;
         g[i].push_back(x);
       }
    }

    //dfs call for storing parent and level
    dfs(1,1,g);

    //queries for lca of u and v
    int q;cin>>q;
    while(q--){
        int u,v;cin>>u>>v;
        cout<<lca(u,v)<<'\n';
    }
}


//inputs
/*
9
2 2 3
2 4 5
2 6 7
0
0
1 8
1 9
0
0
3
8 7
4 9
5 2
*/

/*
output
3
1
2
*/