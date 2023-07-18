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

#define endl "\n"
#define all(v) (v).begin(), (v).end()
#define srt(v) sort (all (v))
#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define rv(a,n) for(int i=0;i<n;i++)cin>>a[i]
const ll mod=1000000007;


bool check(vi b, vpii intervals, int m){
    srt(b);
    for(int i=0;i<m;i++){
        int val = upper_bound(all(b),intervals[i].second)-lower_bound(all(b),intervals[i].first);
        if(2*val>intervals[i].second-intervals[i].first+1)return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
    int n,m;
    cin>>n>>m;
    vpii intervals(m);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        intervals[i]=mp(x,y);
    }
    int q;
    cin>>q;
    vi a(q);
    rv(a,q);
    int l=0,r=q-1;
    bool f = false;
    while(l<r){
        int mid = l+(r-l)/2;
        vi b;
        for(int i=0;i<=mid;i++){
            b.pb(a[i]);
        }
        if(check(b,intervals,m)){
            f=true;
            r=mid;
        }
        else {
            l=mid+1;
        }
    }
    if (f) cout << l+1 << endl;
    else {
        vi b;
        for(int i=0;i<=l;i++){
            b.pb(a[i]);
        }
        if(check(b,intervals,m)) cout<< l+1 << endl;
        else cout << -1 << endl;
    }
}

return 0;
}