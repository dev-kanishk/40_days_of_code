#include <bits/stdc++.h>
using namespace std;

int kadelay(int* sum, int row){
    int largest = -1 * INT_MAX;
    for(int i = 0; i < row; i++){
        if(i-1 >= 0){
            sum[i] = max(sum[i],(sum[i-1] + sum[i]));
            if(sum[i] > largest)
                largest = sum[i];
        }
    }
    return largest;
}

int main()
{
    int row, col;
    cin >> row >> col;
    int arr[row][col];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> arr[i][j];
        }
    }
    
    int maximum = -1 * INT_MAX;
    
    for(int l = 0; l < col; l++){
        for(int r = l; r < col; r++){
            int sum[row];
            for(int i = 0; i < row; i++){
                sum[i] = 0;
                for(int j = l; j <= r; j++){
                    sum[i] += arr[i][j];
                }
            }
            int max_subarray = kadelay(sum,row);
            if(maximum < max_subarray){
                maximum = max_subarray;
            }
        }
    }
    
    cout << maximum;
    
    return 0;
}
