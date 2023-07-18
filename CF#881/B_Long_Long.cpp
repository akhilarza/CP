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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vll a(n);
        rv(a,n);
        ll sum = 0;
        int count = 0;
        bool f = false;
        for(int i=0;i<n;i++){
            sum+=abs(a[i]);
            if(a[i] < 0){
                if(!f){
                    f = true;
                    count++;
                }
            }
            else if(a[i] > 0){
                if(f){
                    f = false;
                }
            }
            else{
                continue;
            }
        }
        cout<< sum << " " << count << endl;
    }

return 0;
}