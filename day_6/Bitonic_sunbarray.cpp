 	
	int longestBitonicSubarray(int *input, int n) {
		
	
        int inc[n];
        int largest = 0;
        int dec[n];
        
        for(int i = 0; i < n; i++){
            int j = i-1;
            int count = 0;
            while(j >= 0){
                if (input[j] < input[i]){
                   if( count < inc[j])
                       count = inc[j];
                    // break;
                }
                j--;
            }
                
            
            inc[i] = 1 + count;
             //  cout << inc[i] <<" ";
            if(largest < inc[i])
                largest = inc[i];
        }
     	   // cout << endl;
          for(int i = n-1; i >= 0; i--){
            int j = i+1;
            int count = 0;
            while(j < n){
                if (input[j] < input[i]){
                    if(count < dec[j])
                        count = dec[j];
                    // break;
                }
                j++;
            }
            dec[i] = 1 + count;
               //cout << dec[i] <<" ";
            if(largest < dec[i])
                largest = dec[i];
        }
    //    cout << endl;
        largest = 0;
        for(int i = 0; i < n; i++){
            int sum = inc[i] + dec[i]-1;
            if(sum > largest){
                largest = sum;
            }
        }
        return largest;
     	
     	
 	}

