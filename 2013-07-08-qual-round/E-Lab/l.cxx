
#include <iostream>
#include <istream>
#include <ostream>

#include <map>

using namespace std;

typedef long long mint;

mint n, x, k;

mint gblocks;

map<mint, mint> chunks;

int main()
{
	cin >> n >> x >> k;

	mint aix, gena, stud;

	for (mint ix = 0; ix != n; ++ix)
	{
		cin >> aix;

		if (x > 0)
		{
			stud = aix % x;
			gena = aix / x;
			gblocks += gena;
		}
		else
		{
			stud = aix;
		}

		if (stud > 0)
		{
			chunks[stud] += 1;
		}
	}

	mint days = 0;

	mint s;

	while (gblocks > 0 || ! chunks.empty())
	{
		++days;

		if (gblocks > 0)
		{
			--gblocks;
		}
		else
		{
			--chunks.rbegin()->second;
			
			if (chunks.rbegin()->second == 0)
			{
				chunks.erase(chunks.rbegin()->first);
			}
		}

		s = k;

		while (s > 0 && (gblocks > 0 || ! chunks.empty()))
		{
			if (! chunks.empty())
			{
				mint totsize = chunks.begin()->first * chunks.begin()->second;

				if (totsize <= s)
				{
					s -= totsize;

					chunks.erase(chunks.begin());
				}
				else
				{
					chunks.begin()->second -= s / chunks.begin()->first;

					if (s % chunks.begin()->first != 0)
					{
						--chunks.begin()->second;

						mint kk = chunks.begin()->first;

						++chunks[chunks.begin()->first - (s % chunks.begin()->first)];

						if (chunks[kk] == 0)
						{
							chunks.erase(kk);
						}
					}

					s = 0;
				}
			}
			else
			{
				mint totsize = x * gblocks;

				if (totsize <= s)
				{
					s -= totsize;

					gblocks = 0;
				}
				else
				{
					gblocks -= s / x;

					if (s % x != 0)
					{
						--gblocks;

						++chunks[x - (s % x)];
					}

					s = 0;
				}
			}
		}
	}

	cout << days << endl;

	return 0;
}

