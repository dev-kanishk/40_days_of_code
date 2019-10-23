#include<bits/stdc++.h>
using namespace std;
class tri{
    public:
    int start,end,profit;
};


bool valuecomp(tri &a, tri &b){
    return a.end < b.end;
}

int binarysearch(int start, int end, tri *arr, int current){
    int output = -1;
    while(start <= end){
        int mid = start+(end-start)/2;
        if(arr[mid].end <= arr[current].start){
            start = mid+1;
            output = mid;
            
        }
        else{
            end = mid-1;
        }
    }
    return output;
}



int main(){
    int n;
    cin >> n;
    tri arr[n];
    for(int i = 0; i < n; i++){
        cin>> arr[i].start >> arr[i].end >> arr[i].profit;
    }
    sort(arr, arr+n, valuecomp);
    
    int max[n];
    
    
    for(int i = 0; i < n ; i++){
       
        int temp = 0;
         int j = binarysearch(0, i-1, arr, i);
      
        
        int limit = 0;
        if(j >= 0)
            limit =arr[j].start;
       
        for(;j >= 0 && arr[j].end <= arr[i].start && arr[j].end > limit; j--){
               if(max[j] > temp){
                temp = max[j];
                limit = arr[j].start;
            }
        }
        
        
        max[i] = temp+arr[i].profit;
    }
    int output = 0;
    for(int i = 0; i < n ; i++){
        if(output < max[i])
            output = max[i];
    }
    cout << output;
}