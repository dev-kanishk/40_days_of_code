#include<bits/stdc++.h>
#define ll long long
using namespace std;

class mypair{
public:
	ll first,second;
};
bool cmp(mypair&a , mypair &b){
	return a.second > b.second;
}
int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
#endif
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 // write your code here

    ll n;
    ll numbags;
    cin >> n;
    cin >> numbags;
    mypair jwells[n];
    for(ll i  = 0; i < n; i++){
    	cin >> jwells[i].first >> jwells[i].second;
    }

    sort(jwells,jwells+n,cmp);

    multiset < ll>  bags;


    for(ll i = 0; i < numbags; i++){
    	ll temp;
    	cin >> temp;

    	bags.insert(temp);
    }

    ll total_value = 0;

    for(ll i = 0; i < n && numbags > 0; i++){

    	if(bags.end() != bags.lower_bound(jwells[i].first)){
    		bags.erase(bags.lower_bound(jwells[i].first));
    		numbags--;
    		total_value += jwells[i].second;
    	}


    }



    cout << total_value;


    return 0;


}