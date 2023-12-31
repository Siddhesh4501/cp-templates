#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

// This seg Tree is for finding sum of segments
// update as per your need

class SegTree{
    private:

        vector<ll> seg;
        vector<ll> lazy;
        ll n;
        void build(ll ind, ll low, ll high, ll arr[]){
            if(low == high){
                seg[ind] = arr[low];
                return;
            }
            ll mid = low + (high - low)/2;
            build(2*ind + 1, low, mid, arr);
            build(2*ind + 2, mid + 1, high, arr);

            seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
        }

        ll querySeg(ll ind, ll low, ll high, ll l, ll r){
           if(lazy[ind] != 0){
                seg[ind] += (high - low + 1) * lazy[ind];
                if(low != high){
                    lazy[2*ind + 1] += lazy[ind];
                    lazy[2*ind + 2] += lazy[ind];
                }
                lazy[ind] = 0;
            }
            if(r < low || l > high)
                return 0;
            if(low >= l && high <= r)
                return seg[ind];
            
            ll mid = low + (high - low)/2;

            ll left = querySeg(ind*2 + 1, low, mid, l , r);
            ll right = querySeg(ind*2 + 2, mid + 1, high, l, r);
            return left + right;
        }

        void updateSeg(ll ind, ll low, ll high, ll i, ll val){

            if(lazy[ind] != 0){
                seg[ind] += (high - low + 1) * lazy[ind];
                if(low != high){
                    lazy[2*ind + 1] += lazy[ind];
                    lazy[2*ind + 2] += lazy[ind];
                }
                lazy[ind] = 0;
            }

            if(low == high){
                seg[ind] += val;
                return;
            }
            ll mid = low + (high - low)/2;
            if(i <= mid)
                updateSeg(ind*2 + 1, low, mid, i, val);
            else
                updateSeg(ind*2 + 2, mid + 1, high, i, val);
            seg[ind] = seg[ind*2 + 1] + seg[ind*2 + 2];    
        }

        void updateRangeSeg(ll ind, ll low, ll high, ll l, ll r, ll val){

            if(lazy[ind] != 0){
                seg[ind] += (high - low + 1) * lazy[ind];
                if(low != high){
                    lazy[2*ind + 1] += lazy[ind];
                    lazy[2*ind + 2] += lazy[ind];
                }
                lazy[ind] = 0;
            }

            if(high < l || low > r)
                return;
            if(low >= l && high <= r){
                seg[ind] += (high - low + 1) * val;
                if(low != high){
                    lazy[2 *ind + 1] += val;
                    lazy[2 *ind + 2] += val;
                }
                return;
            }

            ll mid = low + (high - low)/2;
            updateRangeSeg(ind*2 + 1, low, mid, l , r, val);
            updateRangeSeg(ind*2 + 2, mid + 1, high, l, r, val);
            seg[ind] = seg[ind*2 + 1] + seg[ind*2 + 2];   
        }
    public: 
        
        SegTree(ll arr[], ll n){
            this->n = n;
            seg.resize(n*4+5);
            lazy.resize(n*4+5);
            build(0, 0, n-1, arr);
        }

        // query sum in the range l to r inclusive
        ll query(ll l, ll r){
            return querySeg(0, 0, n - 1, l, r);
        }

        // increaement value at index i by val
        void update(ll i, ll val){
            updateSeg(0, 0, n - 1, i, val);
        }

        // increament value in the range l to r by value val
        void updateRange(ll l, ll r, ll val){
            updateRangeSeg(0, 0, n - 1, l, r, val);
        }

};


int main(){
    ll t, n, type, l, r, i, val, q;
    cin>>t;
    while(t--){
        cin>>n>>q;
        ll arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        SegTree T(arr, n);
        while(q--){
            cin>>type;
            if(type == 1){
                cin>>l>>r;
                cout<<T.query(l, r)<<endl;
            }
            if(type == 2){
                cin>>i>>val;
                T.update(i, val);
            }
            if(type == 3){
                cin>>l>>r>>val;
                T.updateRange(l, r, val);
            }
        }
    }




    return 0;
}