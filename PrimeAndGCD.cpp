#include<bits/stdc++.h>
using namespace std;
#define ll long long


const ll UPPER  = 1e7 + 5;
const ll MOD = 1e9 + 7;



class PrimeAndFactors{
    private:
    ll n;
    vector<bool> prime;
    vector<ll> LCF;
    vector<ll> primeNumbers;
    
    void updatePrime(){
        prime[0] = prime[1] = false;
        LCF[0] = 0, LCF[1] = 1;
        for(ll i = 2; i * i <= n; i++){
            if(prime[i]){
                for(ll j = i * i; j <= n; j += i){
                    prime[j] = false;
                    LCF[j] = min(LCF[j], i);
                }
            }
        }
        for(ll i = 0; i <= n; i++){
            if(prime[i]){
                LCF[i] = i;
                primeNumbers.push_back(i);   
            }
        }
    }
    
    public:
    PrimeAndFactors(ll n = UPPER){
        this->n = max(n, 2LL);
        this->prime = vector<bool>(this->n + 1, true);
        this->LCF = vector<ll>(this->n + 1, this->n + 5);
        this->updatePrime();
    }
    
    bool isPrime(ll num){
        return this->prime[num];
    }
    
    ll getLCF(ll num){
        
        return this->LCF[num];
    }
    
    vector<ll> getAllPrimeNumbers(){
        return this->primeNumbers;
    }
    
    unordered_map<ll, ll> getPrimeFactorsCount(ll num){
       unordered_map<ll, ll> umap;
       while(num > 1){
           umap[this->getLCF(num)]++;
           num /= this->getLCF(num);
       }
       return umap;
    }
    
    vector<ll> getPrimeFactors(ll num){
       set<ll> s;
       while(num > 1){
           s.insert(getLCF(num));
           num /= getLCF(num);
       }
       return vector<ll>(s.begin(), s.end());
    }
    
    ll getTotalNoOfDivisors(ll n){
        ll ans = 1;
        unordered_map<ll, ll> umap = getPrimeFactorsCount(n);
        for(auto& [primeNum, count] : umap)
            ans = (ans * (count + 1)) % MOD;
        return ans;
    }
};


int main() {
	PrimeAndFactors p(1000);
    vector<ll> prime = p.getAllPrimeNumbers();
    for(ll i : prime)
        cout<<i<<" ";

	return 0;
}
