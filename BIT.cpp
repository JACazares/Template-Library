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

vl a, BIT;

void init(int n)
{
    BIT.resize(n+1);
    for(int i = 1; i <= n; i++)
    {
        BIT[i] += a[i];
        if(i + (i&-i) <= n)
            BIT[i + (i&-i)] += BIT[i];
    }
}

void upd(int n, int pos, int x)
{
    for(; pos <= n; pos += (pos&-pos))
        BIT[pos] += x;
}

ll qry(int pos)
{
    ll res = 0;
    for(; pos; pos -= (pos & -pos))
        res += BIT[pos];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    a.resize(N + 1);
    for(int i = 1; i <= N; i++)
        cin >> a[i];
    init(N);
    vi t(Q), p(Q), x(Q), l(Q), r(Q);
    for(int i = 0; i < Q; i++)
    {
        cin >> t[i];
        if(t[i] == 0)
        {
            cin >> p[i] >> x[i];
            ++p[i];
            upd(N, p[i], x[i]);
            a[p[i]] += x[i];
        }
        else
        {
            cin >> l[i] >> r[i];
            ++l[i], ++r[i];
            cout << qry(r[i] - 1) - qry(l[i] - 1) << "\n";
        }
    }
    return 0;
}
