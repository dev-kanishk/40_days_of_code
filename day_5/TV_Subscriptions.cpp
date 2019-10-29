    #include<bits/stdc++.h>
    #define ll long long
    using namespace std;
     
     
     
    int main(){
    // 	#ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
        
    // #endif
          ios_base::sync_with_stdio(false);
        cin.tie(NULL);
     
     // write your code 
     
        int t;
        cin >> t;
        while(t--){
    set<int> s;
    unordered_map <int,int> mp;
     
    int n,k,d;
    cin >>n>>k>>d;
     
    int arr[n];
    for(int i = 0; i < n; i++)
    	cin >> arr[i];
     
    for(int i = 0; i < d; i++){
    	s.insert(arr[i]);
    	mp[arr[i]]++;
    }
    	int min =  s.size();
     
    	for(int i = d; i < n; i++){
    		if(mp.count(arr[i-d]) && mp[arr[i-d]] == 1){
    			s.erase(arr[i-d]);
    			mp[arr[i-d]] = 0;
     
    		}
    		else if(mp.count(arr[i-d]) && mp[arr[i-d]] > 1){
    			mp[arr[i-d]]--;
    		}
     
    		s.insert(arr[i]);
    		mp[arr[i]]++;
     
    		if(s.size() < min)
    			min = s.size();
     
     
    	}
     
    	cout << min <<"\n";
     
     
    }
     
     
        return 0;
     
     
    }