#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;
typedef vector <string> vs;
typedef vector <vi> vvi;
typedef vector <vll> vvll;
typedef vector <vpii> vvpii;
typedef vector <vpll> vvpll;

#define endl "\n";
#define all(v) (v).begin(), (v).end()
#define srt(v) sort (all (v))
#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define rv(a,n) for(int i=0;i<n;i++)cin>>a[i]
const ll mod=1000000007;


int numroot(vi &count, int n, vi adj[], int u, vector<bool>&vis){
    int val = 0;
    vis[u]=true;
    for(int v=0;v<adj[u].size();v++){
        if(!vis[adj[u][v]])val+=numroot(count,n,adj,adj[u][v],vis);
    }
    if(val==0)val++;
    count[u]=val;
    return val;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi adj[n];
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u-1].pb(v-1);
            adj[v-1].pb(u-1);
        }
        vi count(n,0);
        vector<bool>vis(n,false);
        int total_roots = numroot(count,n,adj,0,vis);
        int q;
        cin>>q;
        for(int i=0;i<q;i++){
            int u,v;
            cin>>u>>v;
            cout<<ll(count[u-1])*ll(count[v-1])<<endl;
        }
    }

return 0;
}