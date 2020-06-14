#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

#define mp make_pair
#define sz(x) (int)x.size()
#define pb push_back

vl a, prefix;

void init(int n)
{
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    prefix.resize(n);
    prefix[0] = a[0];
    for(int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + a[i];
}

ll qry(int l, int r)
{
    return prefix[r] - (l >= 0 ? prefix[l] : 0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vi l(Q), r(Q);
    init(N);
    for(int i = 0; i < Q; i++) 
    {
        cin >> l[i] >> r[i];
        cout << qry(l[i] - 1, r[i] - 1) << "\n";
    }
    return 0;
}
