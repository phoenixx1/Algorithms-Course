//author @Nishant

#include<bits/stdc++.h>
using namespace std;

int firstDigit(int x){
    while(x>=10){
        x = x/10;
    }
    return x;
}
int secondDigit(int x){
    if(x<100){
        return x % 10;
    }else if(x>=100 && x<1000){
        while (x >= 100)
            x /= 10;
        return x % 10;
    }else{
        int y = x%1000;
        y = y / 100;
        return y;
    }
    
}

int main(){
    int n, temp;
    
    cin >> n;
    int a[n];
    if(n<0){
        return 0;
    }
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){		
		for(int j=i+1;j<n;j++){
			if(firstDigit(a[i])<firstDigit(a[j])){
				int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
			}else if(firstDigit(a[i])==firstDigit(a[j])){
                if(secondDigit(a[i])<secondDigit(a[j])){
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
		}
	}
    
    for(int i=0; i<n; i++){
        cout << a[i];
    }
    
    return 0;
}
