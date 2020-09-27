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

int gcdExtended(int a,int b,int *x,int *y)
{
    if(a==0)
    {
        *x=0;
        *y=1;
        return b;
    }
    int x1,y1;
    int gcd=gcdExtended(b%a,a,&x1,&y1);

    *x=y1-(b/a)*x1;
    *y=x1;

    return gcd;
}

int inverse(int a,int m)
{
    int x,y,res;
    int g=gcdExtended(a, m, &x, &y);
    if(g!=1)
    {
        cout<<"Inverse Does not exist"<<endl;
    }
    else{
         // m is added to handle negative x
          res=(x%m+m)%m;
    }
    return res;

}

int findMinX(int num[], int rem[], int k)
{
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];

    int result = 0;

    for (int i = 0; i < k; i++)
    {
        int pp = prod / num[i];
        result += rem[i] * inverse(pp, num[i]) * pp;
    }

    return result % prod;
}

int main(void)
{
    int num[] = {3, 4, 5};
    int rem[] = {2, 3, 1};
    int k = sizeof(num)/sizeof(num[0]);
    cout << "x is " << findMinX(num, rem, k);
    return 0;
}
