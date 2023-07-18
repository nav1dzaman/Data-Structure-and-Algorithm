#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <map>
#include <set>
#include <sstream>
#include <deque>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <bitset>
#include <algorithm>
#include <string>
#include <fstream>
#include <assert.h>
#include <list>
#include <cstring>
using namespace std;
typedef long long  ll;
typedef long long int lli;
typedef long double ld;
#define io ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define READ_WRITE freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define prina(a) for(auto x : a) cout << x << " "; cout << endl
void inv(vector <lli> &v,lli n){
for(lli i=0;i<n;i++){lli x;cin>>x;v.push_back(x);}}
void ina(lli arra[],lli n){for(lli i=0;i<n;i++)cin>>arra[i];}
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
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
  const char* comma = strchr (names + 1, ',');
  cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

lli power(lli base,lli n, lli mod)
{
   
  lli result=1;
  while(n)
  {
    if(n%2==1)
    {
      result =(result*base)%mod;
      n--;
    }
    else {
      base=(base*base)%mod;
      n/=2;
    }
  }
  return result;
} 

bool pali(string s){
  string ss=s;
   reverse(all(ss));
  if(ss==s)return true;
  else return false;
}
bool prime(lli n){
  if(n<2)return false;
  if(n==2)return true;
  if(n%2==0)return false;
  for(lli i=3;i*i<=n;i+=2){
    if(n%i==0)return false;
  }
  return true;
}
bool divisor(int n){
  
  if(n<2)return false;
  if(n==2)return false;
  if(n%2==0)return false;
  for(lli i=3;i*i<=n;i+=2){
    if(n%i==0)return false;
  }
  return true;
    
}
void yu(int a[][5]){

}
lli MX=100;
lli lev[100][100];
lli m,n;
bool vs[100][100];
char st[100][100];
lli dx[]={1,-1,0, 0, 1,1,-1,-1};
lli dy[]={0, 0,1,-1,-1,1,1,-1};

lli bfs(lli fx,lli fy) /// starting position
{
  lli hu=1;
    lli i,v,x,y,md=0;
    queue <pair<lli,lli>> q;
    vs[fx][fy]=1;
   // lev[fx][fy]=0;
    q.push({fx,fy});
    while(!q.empty()){
        auto pr=q.front();
        fx=pr.first;
        fy=pr.second;
        q.pop();
        for(i=0;i<8;i++){
            x=fx+dx[i];
            y=fy+dy[i];
            if(x<0||x>=n||y<0||y>=m)continue; 
            if(vs[x][y]==0 && st[x][y]=='W'){ 
                q.push({x,y});
                vs[x][y]=1;
                hu++;
            }
        }

    } 
    return hu;
  }
    


int main()
{
  #ifndef ONLINE_JUDGE
  READ_WRITE
  #endif


     int cases;
  string input;
  int a, b;
  stringstream ss;
  map<int,int> result;
  cin >> cases;
  cin.ignore(100, '\n');
  cin.ignore(100, '\n');
  while (cases--) {
    n = 0;
    m = 0;
    //num = 1;
    result.clear();
    /*for (int i = 0; i < 100; i++)
      for (int j = 0; j < 100; j++) {
        vs[i][j] = false;
        st[i][j] = 'L';
      }*/
    memset(vs, 0, sizeof(vs));
    memset(st, 0, sizeof(st));
    while (getline(cin, input)) {
      if (input == "")
        break;
      if (input[0] == 'L' || input[0] == 'W') {
        for (int i = 0, sz = input.size(); i < sz; i++) {
          st[n][i] = input[i];
        }
        n++;
        m = input.size();
      } else {
        /*for (int i = 0; i < 100; i++)
          for (int j = 0; j < 100; j++)
            vs[i][j] = false;*/
        memset(vs, 0, sizeof(vs));
        ss << input;
        ss >> a >> b;
        ss.str("");
        ss.clear();
        cout << bfs(a-1, b-1) << endl;
      }
    }
    if (cases)
      cout << endl;
  }

 
}



/*
set-deque-pqueue-pair-map-stack-sorting
1)FIND THAT BItCH TEST CASE
2)check complexity
3)Observe properly! Simulate and Draw !
4)Look at /solve the test case , equation
5)Math - Observation -Bf - Greedy -test case pattern
6)Think!Think!Think!Think!Think!Think!Think!Think!Think!
*/





