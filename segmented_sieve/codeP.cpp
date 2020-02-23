#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> findprimes(int n){
    bool sieve[n+1];
    for(int i = 0; i <= n; i++)
        sieve[i] = true;
    sieve[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(sieve[i]){
            for(int j = i*i; j <= n; j+=i){
                sieve[j] = false;
            }
        }
    }
    vector<int> primes;
    primes.push_back(2);
    for(int i = 3; i <= n; i+=2){
        if(sieve[i]){
            primes.push_back(i);
        }
    }
    return primes;
}

struct mytype{
    ll begin,last;
    
};

int main(){
    int t;
    cin >> t;
    mytype inputs[t];
    ll max = 0, min = LONG_MAX;
    for(int i = 0; i < t; i++){
        cin>>inputs[i].begin >> inputs[i].last;
        if(max  < inputs[i].last)
            max = inputs[i].last;
        if(min > inputs[i].begin)
            min = inputs[i].begin;
    }
    
    vector<int> primes = findprimes(sqrt(max)+1);
    
    
    for(int k = 0; k < t; k++){
    
        ll begin = inputs[k].begin, last = inputs[k].last;
        cin>> begin >> last;
        // vector<int> primes = findprimes(sqrt(last)+1);
        bool sieve[last-begin+1];
        for(int i = 0; i <= last-begin; i++){
            sieve[i] = true;
        }
        for(int i = 0; i < primes.size() && (primes[i]*(long long)primes[i] <= last); i++){
            int st = 0;
            st = (begin/primes[i])*primes[i];
            if(st < begin)
                st += primes[i];
            st = st-begin;
          
            for(int j = st; j <= last-begin; j+=primes[i]){
                if(begin+j == primes[i])
                    continue;
                sieve[j] = false;
                // cout << j <<" v";
            }
        }
        // cout<<endl;
    
        
        for(int j = 0; j <= last-begin; j++){
            // cout << i << endl;
            if(sieve[j]){
                cout << begin+j <<endl;
            }
        }
    
    }
    
}