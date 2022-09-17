#include<bits/stdc++.h>
using namespace std;
vector <int> graph[1000000];
int visited[5000000];
vector <int> store;
vector <int> vv,tmp;

void dfs(int source){
    visited[source]=true;
    vector <int> temp=graph[source];
    sort(temp.begin(),temp.end(),greater<int>());

    for (int i=0;i<temp.size();i++){
        int next = temp[i];
        if (visited[next] == false){
             dfs(next);
        }
    }


    store.push_back(source);
}

int main()
{
     int nodes, edges;
    cin>>nodes>>edges;
    for (int i = 0; i < edges; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
    }

    for(int i=nodes;i>=1;i--){
        if(visited[i]==false){
            dfs(i);
        }
    }

   reverse(store.begin(),store.end());

    for(int i=0;i<store.size();i++){
      cout<<store[i]<<endl;
    }

}
