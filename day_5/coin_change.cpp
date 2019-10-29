
#include<bits/stdc++.h>

int countWaysToMakeChange(int denos[], int numDe, int value){

    
       sort(denos,denos+numDe);
  
    
    int  arr[numDe+1][value+1];
    
    for(int i = 0; i <= numDe; i++){
        for(int j = 0; j <= value; j++){
            if(j == 0){
                arr[i][j] = 1;
            }
            else if (i == 0){
            arr[i][j] = 0;
            }
            else{
                if(j >= denos[i-1]){
                    arr[i][j] = arr[i-1][j] + arr[i][j - denos[i-1]];
                }
                else{
                    arr[i][j] = arr[i-1][j];
                }
                
            }
        }
    }
    

  

    return arr[numDe][value];
}
