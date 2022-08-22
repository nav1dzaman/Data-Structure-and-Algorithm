#include<bits/stdc++.h>
using namespace std;

vector <int> graph[10000];
bool visited[500000];
  vector <int> vv,tmp;
void dfs(int source){
    vv.push_back(source);
    visited[source] = 1;
    for (int i = 0; i < graph[source].size(); i++){
        int next = graph[source][i];
        if (visited[next] == 0){
             dfs(next);
        }
    }
}

int main()
{
    int nodes, edges;
    cin>>nodes>>edges;
    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt=0;

    for(int i=1;i<=edges;i++){
        if(visited[i]==false){
            visited[i]=true;
            dfs(i);
            cnt++;
        }
    }

    cout<<cnt<<endl;
    return 0;
}
