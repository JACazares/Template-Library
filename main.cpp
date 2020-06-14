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

void init(int n, vi& parent)
{
    for(int i = 0; i <= n; i++)
        parent[i] = i;
}

int look(int node, vi& parent)
{
    if(parent[node] == node)
        return node;
    return parent[node] = look(parent[node], parent);
}

void join(int a, int b, vi& parent, vi& depth)
{
    a = look(a, parent), b = look(b, parent);
    if(a == b)
        return;
    if(depth[a] < depth[b])
    {
        parent[a] = b;
        depth[a] = 0;
    }
    else
    {
        parent[b] = a;
        if(depth[a] == depth[b])
            depth[a]++;
        depth[b] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vi t(Q), u(Q), v(Q), parent(N), depth(N);
    init(N, parent);
    for(int q = 0; q < Q; q++)
    {
        cin >> t[q] >> u[q] >> v[q];
        if(t[q] == 0)
            join(u[q], v[q], parent, depth);
        else
            cout << (look(u[q], parent) == look(v[q], parent) ? 1 : 0) << "\n";
    }
    return 0;
}
