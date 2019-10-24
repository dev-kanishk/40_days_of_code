#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
#endif

	ll n;
	cin >> n;

	ll *arr = new ll[n];
	ll *dp = new ll[n];
	dp[0] = 0;

	for(ll i = 0; i < n; i++)
		cin >> arr[i];
	ll i = 0;
	ll  j = 1;
	ll min_cost = 0;
	while(j != n-1){
		if(abs(arr[i]) > abs(arr[j]) || (abs(arr[i]) == abs(arr[j]) && arr[i] > 0)){
			min_cost += (j-i)*arr[i]+(j*j - i*i)*arr[i]*arr[i];
			i = j;
			
		}
		j++;
		
	}
	min_cost += (j-i)*arr[i]+(j*j - i*i)*arr[i]*arr[i];
	cout << min_cost;


	
}