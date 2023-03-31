#include<bits/stdc++.h>
using namespace std;

const int MAX=17;


int main(){
    int n,q;cin>>n>>q;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    //binary lifting
    int table[MAX][n];

    //calculating for first parent
    for(int i=0;i<n;i++){
        table[0][i]=v[i];
    }

    //calculating for the rest
    for(int i=1;i<MAX;i++){
        for(int j=0;j<n;j++){
            table[i][j]=table[i-1][table[i-1][j]];
        }
    }

    //query
    while(q--){
        int a,k;cin>>a>>k;//{node,ith parent}

        for(int i=0;i<MAX;i++){
            int mask=(1<<i);
            if((k&mask)>0){
                a=table[i][a];
            }
        }
        cout<<a<<'\n';
    }
}

//input
// 7 6
// 0
// 0
// 0
// 1
// 3
// 2
// 3
// 5 1
// 6 2
// 3 2
// 3 3
// 6 3
// 4 1

//output
// 2
// 1
// 0
// 0
// 0
// 3