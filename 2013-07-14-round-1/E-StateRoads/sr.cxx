
#include <iostream>
#include <istream>
#include <ostream>

#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef int mint;

mint n, q;

vector<pair<mint, mint> > qs;

vector<unordered_set<mint> > es;

void connect(mint u, mint v)
{
	es[u].insert(v);
	es[v].insert(u);
	qs.push_back(make_pair(u, v));
}

void undo(mint m)
{
	pair<mint, mint> p = qs[m];
	es[p.first].erase(p.second);
	es[p.second].erase(p.first);
}

bool query()
{
	mint k, u;

	cin >> k;

	unordered_set<mint> tgt;

	for (mint i = 0; i != k; ++i)
	{
		cin >> u;

		--u;

		tgt.insert(u);
	}

	for (unordered_set<mint>::iterator itr0 = tgt.begin();
			itr0 != tgt.end(); ++itr0)
	{
		mint nx = *itr0;

		if (es[nx].size() >= tgt.size())
		{
			return false;
		}

		for (unordered_set<mint>::iterator itr = es[nx].begin();
				itr != es[nx].end(); ++itr)
		{
			mint nnx = *itr;

			if (tgt.find(nnx) == tgt.end())
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	cin >> n >> q;

	es = vector<unordered_set<mint> >(n);

	mint t, u, v, m;

	for (mint i = 0; i != q; ++i)
	{
		cin >> t;

		if (t == 1)
		{
			cin >> u >> v;

			connect(u - 1, v - 1);
		}
		else if (t == 2)
		{
			cin >> m;

			undo(m - 1);
		}
		else
		{
			cout << (query() ? "YES" : "NO") << endl;
		}
	}

	return 0;
}

