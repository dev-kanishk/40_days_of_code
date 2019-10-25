#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
#endif
    //   ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
 
 // write your code here

    int sum,d;
    cin >> sum >> d;

    int arr[d]={0};
    arr[0] = 1;
    int curr = 1;
    for(int i = d-1; i >= 0; i--){

    	 if(curr < sum){

    	 	if(sum-curr <= 9){
    	 		arr[i] += sum-curr;

    	 		break;

    	 	}
    	 	else{
    	 		arr[i] = 9;
    	 		curr += 9;
    	 	}
    	 }
    }
    

for(int i = 0; i < d; i++)
	cout <<arr[i];

    return 0;


}