#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef long long int lli;
typedef long double ld;
#define io ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define READ_WRITE freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define prina(a) for(auto x : a) cout << x << " "; cout << endl
void inpv(vector <lli> &v,lli n){
for(lli i=0;i<n;i++){lli x;cin>>x;v.push_back(x);}}
void inpa(lli arra[],lli n){for(lli i=0;i<n;i++)cin>>arra[i];}
#define test int T; cin>>T; while(T--) 
#define lcm(a,b)  (a*(b/__gcd(a,b)))
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define pb push_back
#define mp make_pair
#define ln cout<<endl
#define sz(x) ((int) x.size())
#define all(v) v.begin(), v.end()
#define vi vector <lli> 
#define deb cout<<"DEBUG"<<endl
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
long long int mina = 0x3f3f3f3f;
long long int maxa=0;
long long int MOD=1e9+7;
const int N=1e5+7;
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
  const char* comma = strchr (names + 1, ',');
  cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
} 

#define MX 200001

vector < int > graph[MX];

lli weapon ;
lli maxi=0;



void bfs(int source){
  bool vis[MX]={0};
  int dist[MX]={0};
  vector <int> v;
    queue < int > Q;
     v.push_back(source);
    vis[source] = 1;
    dist[source] = 0;
    Q.push(source);

    while(!Q.empty()){
        int node = Q.front();

        Q.pop();

        for (int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i];
            if (vis[next] == 0){
                v.push_back(next);
                vis[next] = 1;
                dist[next] = dist[node] + 1;
                if(dist[next]>=maxi){
                  maxi=dist[next];
                  weapon=next;
                }
                Q.push(next);
            }
        }
    }
}


int main()
{    

  lli nodes;
  cin>>nodes;
  lli source;
  for(lli i=0;i<nodes-1;i++){
     int u, v;
        cin >> u >> v;
        source=u;
        graph[u].push_back(v);
        graph[v].push_back(u);

  }
  bfs(source);
  
  bfs(weapon);
  
   
  cout<<maxi<<endl;
  
  

 

 
   
 
 
}
  

