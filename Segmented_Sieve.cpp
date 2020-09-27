#include<bits/stdc++.h>
#define ll long long
#define fors(i,n)  for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define LOOP(it,m) for(auto it=m.begin();it!=m.end();it++)
#define  pb              push_back
#define  mp              make_pair
#define  vll             vector<ll>
#define  pll             pair <ll,ll>
#define  umap            unordered_map
#define  uset            unordered_set
#define  lb              lower_bound
#define  ub              upper_bound
#define  maxe            *max_element
#define  mine            *min_element
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        a/__gcd(a,b)*b
#define endl            "\n"
#define debug(x)        cout << " x =" << x << "\n";
#define init(c,a)       memset(c,a,sizeof(c))
#define mod             1000000007

using namespace std;

//------------------------------------------------
// ---------CODE HERE-----------------

void simpleSieve(ll limit,vector<ll> &prime)
{
   bool mark[limit+1];
    init(mark,true);

    for(int p=2;p<=sqrt(limit);p++)
    {
        if(mark[p]==true)
        {
            for(int i=p*p;i<limit;i+=p)
            {
                mark[i]=false;
            }
        }
    }
     for (int p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
            cout << p <<endl;
        }
    }
}

void segmentedSieve(ll n)
{
    vector <ll> prime;
    ll limit=floor(sqrt(n))+1;
    simpleSieve(limit,prime);
    ll low=limit;
    ll high=2*limit;

    while(low<n)
    {
        if(high>n)
            high=n;

         bool mark[limit+1];
         memset(mark, true, sizeof(mark));

         for(int i=0;i<prime.size();i++)
         {
             ll loLim = floor(low/prime[i]) * prime[i];
              if (loLim < low)
                loLim += prime[i];

              for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
         }

         for(int i=low;i<high;i++)
         {
             if(mark[i-low]==true)
             {
                 cout<<i<<endl;
             }
         }

         low=low+limit;
         high=high+limit;
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  int n = 1000;
    cout << "Primes smaller than " << n << ":n";
    segmentedSieve(n);
    return 0;


}





