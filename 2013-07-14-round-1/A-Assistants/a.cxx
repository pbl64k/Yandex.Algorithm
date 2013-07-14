
#include <iostream>
#include <istream>
#include <ostream>

#include <algorithm>
#include <vector>

using namespace std;

typedef int mint;

mint n;

vector<mint> p;
vector<mint> a;

struct expr
{
	public:
	mint id_;
	bool p_;
	mint d_;
	mint mxd_;

	expr(mint id, bool p, mint d):
			id_(id), p_(p), d_(d), mxd_(0)
	{
	}

	expr(): id_(0), p_(false), d_(0), mxd_(0)
	{
	}
};

vector<expr> x;

class cmp_1
{
	public:
	cmp_1() {}

	bool operator()(const expr &a0, const expr &b0) const
	{
		return a[a0.id_] > a[b0.id_];
	}
};

class cmp_2
{
	public:
	cmp_2() {}

	bool operator()(const expr &a0, const expr &b0) const
	{
		return a0.d_ + a[a0.id_] > b0.d_ + a[b0.id_];
	}
};

class cmp_3
{
	public:
	cmp_3() {}

	bool operator()(const expr &a0, const expr &b0) const
	{
		return a0.id_ < b0.id_;
	}
};

int main()
{
	cin >> n;

	p = vector<mint>(n);
	a = vector<mint>(n);
	x = vector<expr>(n);

	for (mint i = 0; i != n; ++i)
	{
		cin >> p[i] >> a[i];

		x[i] = expr(i, false, 0);
	}

	sort(x.begin(), x.end(), cmp_1());

	for (mint i = 0; i != n; ++i)
	{
		x[i].d_ = i;
	}

	mint st = n;
	mint offs = 0;

	for (mint i = 0; i != n; ++i)
	{
		if (st + p[x[i].id_] - 1 <= x[i].d_ + a[x[i].id_])
		{
			x[i].p_ = true;
			x[i].d_ = st;
			st += p[x[i].id_];
			++offs;
		}
		else
		{
			break;
		}
	}

	sort(x.begin(), x.end(), cmp_3());

	mint max_d = 0;

	for (mint i = 0; i != n; ++i)
	{
		max_d = max(max_d, x[i].p_ ? x[i].d_ - offs + p[x[i].id_] - 1 : x[i].d_ - offs + a[x[i].id_]);
	}

	cout << (max_d + 1) << endl;

	for (mint i = 0; i != n; ++i)
	{
		cout << (x[i].p_ ? 'B' : 'A') << " " << (x[i].d_ - offs + 1) << endl;
	}

	return 0;
}

