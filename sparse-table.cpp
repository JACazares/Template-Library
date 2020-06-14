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

const int LOG = 30;
vi a;
vector<vi> table;

void init(int n)
{
    table.resize(LOG);
    for(int i = 0; i < LOG; i++)
        table[i].resize(n);
    for(int i = 0; i < n; i++)
        table[0][i] = a[i];

    for(int j = 1; j < LOG; j++)
        for(int i = 0; i < n - 2*(1 << (j - 1)) + 1; i++)
            table[j][i] = min(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
}

ll qry(int l, int r)
{
    if(l+1 == r)
        return a[l];
    int lg = 32 - __builtin_clz(r-l) - 1;
    return min(table[lg][l], table[lg][r - (1 << lg)]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vi l(Q), r(Q);
    a.resize(N);
    for(int i = 0; i < N; i++)
        cin >> a[i];
    init(N);
    for(int i = 0; i < Q; i++)
    {
        cin >> l[i] >> r[i];
        cout << qry(l[i], r[i]) << "\n";
    }
    return 0;
}
