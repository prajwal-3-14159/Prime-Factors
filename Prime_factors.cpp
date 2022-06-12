#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <cmath>


using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef unsigned long ul;

typedef vector<ll> vec;
typedef vector<char> vec_c;
typedef vector<ld> vecd;

map<ul, char> Primes;

bool is_prime(ul p)
{
    if (Primes[p] ==  'y'){
        return true;
    }
    if (Primes[p] == 'n'){
        return false;
    }

    else{
    if (p <= 1){
        Primes[p] = 'n';
        return false;
    }
    if (p <= 3){
        Primes[p] = 'y';
        return true;
    }
    if (p % 2 == 0 || p % 3 == 0)
    {
        Primes[p] = 'n';
        return false;
    }
    double root_p = sqrt(p);
    for (int i = 5; i <= root_p; i = i + 6)
    {
        if (p % i == 0 || p % (i + 2) == 0)
        {
            Primes[p] = 'n';
            return false;
        }
    }
    Primes[p] = 'y';
    return true;
    }
}

void prime_factors(ul n)
{
    vec Prime_fac;
    Prime_fac.push_back(1);
    if (n%2 == 0){ Prime_fac.push_back(2); }
    if (n%3 == 0){ Prime_fac.push_back(3); }
    //ul root_n = sqrt(n);
    for (int i=6; i<n/2; i+=6)
    {
        if (is_prime(i-1) == true && n % (i-1) == 0){
            Prime_fac.push_back(i-1);
            //Prime_fac.push_back(n/(i-1));
        }
        if (is_prime(i+1) == true && n % (i+1) == 0){
            Prime_fac.push_back(i+1);
            //Prime_fac.push_back(n/(i+1));
        }
    }
    for (int i=0; i<Prime_fac.size(); i++)
    {
        cout << Prime_fac[i] << " ";
    }
    cout << "\n";
}

int main()
{
    for (ul i=2; i<10000; i++)
    {
        cout << i << "->";
        prime_factors(i);
    }

    return 0;
}

