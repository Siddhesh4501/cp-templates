#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;
const ll UPPER = 1e7 + 5;


class PAndC{
    private:

    ll n;
    vector<ll> fact, invFact;

    void initialize(){
        for(ll i = 2; i <= n; i++)
            fact[i] = (i * fact[i - 1]) % MOD;
        invFact[n] = bin_pow(fact[n], MOD - 2);
        for(ll i = n - 1; i >= 0; i--)
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }

    ll bin_pow(ll x, ll n)
    {
        x %= MOD;
        ll res = 1;

        while (n > 0)
        {
            if (n % 2)
            {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            n /= 2;
        }
        return res;
    }


    public:

    PAndC(ll n = UPPER){
        this->n = n;
        fact = vector<ll>(this->n + 1, 1);
        invFact = vector<ll>(this->n + 1, 1);
        initialize();
    }

    ll getFact(ll n){
        return fact[n];
    }
    ll getInvFact(ll n){
        return invFact[n];
    }

    ll nPr(ll n, ll r){
        return (getFact(n) * getInvFact(n - r)) % MOD;
    }

    ll nCr(ll n, ll r){
        return (((getFact(n) * getInvFact(n - r)) % MOD) * getInvFact(r)) % MOD;
    }
};