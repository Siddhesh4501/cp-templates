#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long

class Tree
{
private:
    ll n = -1;
    ll root = -1;
    vector<vector<ll>> tree;
    void countDepth(ll root, ll currdepth, ll depth[])
    {
        depth[root] = currdepth;
        for (ll i : this->tree[root])
            countDepth(i, currdepth + 1, depth);
    }
    int countRem(ll root, ll other[])
    {
        ll count = 1;
        for (int i : tree[root])
            count += countRem(i, other);
            
        other[root] = this->n - count;
        return count;
    }

public:
    Tree(ll n)
    {
        tree.resize(n, vector<ll>());
        this->n = n;
    }
    Tree(ll n, vector<vector<ll>> &edges)
    {
        this->n = n;
        tree.resize(this->n, vector<ll>());
        this->addEdgesToTree(edges);
    }
    ll getNoOfNodes()
    {
        return this->n;
    }

    void addEdgesToTree(vector<vector<ll>> &edges)
    {
        for (auto &edge : edges)
            tree[edge[0]].push_back(edge[1]);
    }

    void addEdgeToTree(ll x, ll y)
    {
        tree[x].push_back(y);
    }

    ll getRootOfTree()
    {
        if (root != -1)
            return this->root;
        vector<bool> flag(n, true);
        for (auto &i : tree)
            for (auto &j : i)
                flag[j] = false;

        for (int i = 0; i < n; i++)
        {
            if (flag[i])
            {
                this->root = i;
                break;
            }
        }
        return this->root;
    }

    void countDepthOfEachNode(ll depth[])
    {
        countDepth(this->getRootOfTree(), 0, depth);
    }

    void countOtherNodesOfEachNode(ll other[])
    {
        countRem(this->root, other);
    }
};