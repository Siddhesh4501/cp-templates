#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

class Helper{
public:
    static void countInInterval(vector<pair<ll, ll>> &intervals, ll ans[], ll n)
    {
        for (int i = 0; i < n; i++)
            ans[i] = 0;
        for (auto &i : intervals)
        {
            ans[i.first]++;
            if (i.second < n - 1)
                ans[i.second + 1]--;
        }
        for (int i = 1; i < n; i++)
            ans[i] += ans[i - 1];
    }

    static ll bin_pow(ll x, ll n, ll mod)
    {
        x %= mod;
        ll res = 1;

        while (n > 0)
        {
            if (n % 2)
            {
                res = res * x % mod;
            }
            x = x * x % mod;
            n /= 2;
        }
        return res;
    }
};