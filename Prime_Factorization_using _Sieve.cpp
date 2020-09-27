// C++ program to find prime factorization of a
// number n in O(Log n) time with precomputation
// allowed.
#include "bits/stdc++.h"
using namespace std;

#define MAXN   100001
#define ll long long
#define fors(i,n)  for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define LOOP(it,m) for(auto it=m.begin();it!=m.end();it++)

ll SPF[MAXN];

void sieve()
{
    SPF[1]=1;
    loop(i,2,MAXN)
    {
        // marking smallest prime factor for every
        // number to be itself.
        SPF[i]=i;
    }
    // separately marking spf for every even
    // number as 2
    for(ll i=4;i<MAXN;i+=2)
    {
        SPF[i]=2;
    }
    for(int i=3;i*i<MAXN;i++)
    {
        //checking if i is prime
        if(SPF[i]==i)
        {     // marking SPF for all numbers divisible by i
            for(int j=i*i;j<MAXN;j+=i)         // Update all multiples of i greater than or equal to the square of it
            {
                if(SPF[j]==j)
                    SPF[j]=i;
            }
        }
    }
}
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;       //contain prime factors of x
    while (x != 1)
    {
        ret.push_back(SPF[x]);
        x = x / SPF[x];
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    // precalculating Smallest Prime Factor
    sieve();
    int x = 12246;
    cout << "prime factorization for " << x << " : ";

    // calling getFactorization function
    vector <int> p = getFactorization(x);

    for (int i=0; i<p.size(); i++)
        cout << p[i] << " ";
    cout << endl;
    return 0;
}
