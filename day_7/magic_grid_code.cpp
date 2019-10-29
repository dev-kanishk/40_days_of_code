#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while(t--){
        
        int row, col;
        cin>> row >> col;
        int arr[row][col];
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cin >> arr[i][j];
            }
        }
        
        int dp[row][col];
        
        for(int i = row-1; i >= 0; i--){
            for(int j = col-1; j >= 0; j--){
                int right = -1 * INT_MAX, left = -1 * INT_MAX;
                if(j+1 < col){
                    right = dp[i][j+1];
                }
                if(i+1 < row){
                    left = dp[i+1][j];
                }
                
                if(i+1 < row || j+1 < col){
                dp[i][j] = arr[i][j] + max(right,left);
                    if(dp[i][j] >= 0)
                        dp[i][j] = -1;
                }
                else
                    dp[i][j] = -1;
            }
        }
         cout << -1*dp[0][0]<<endl;
    }
    
   
    return 0;
}