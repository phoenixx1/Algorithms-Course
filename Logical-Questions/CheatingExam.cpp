//author @Nishant
/*
IAMSMARTERTHANYOU
IE U
ATRO
MRTY
SAHN
M A
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;  
    string encoded;
    cin >> encoded;
  	if(encoded.length() <= 0 || n<=0){
    	return 0;
  	}
    if(n==1){
        cout << encoded;
        return 0;
    }
    int len = (encoded.length()-1)/(n-1);
    if(len%2 != 0){
    	len += 1;
    }
    char code[n][len];
    int k = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<len; j++){
            if(i==0 && j==0){
                code[i][i] = encoded.at(k++);
            }
            if(i==0 && j>0){
                if(j%2!=0){
                    code[i][j] = encoded.at(k++);
                }
            }
            if(i>0 && i<n-1){
                code[i][j] = encoded.at(k++);
            }
            if(i==n-1){
                if(j%2 == 0){
                    code[i][j] = encoded.at(k++);
                }
            }
        }
    }
    // for(int i=0;i<n;i++){
    //      cout << endl;
    //      for(int j=0;j<len;j++)
    //          cout << code[i][j] << "\t";
    // }
    vector<char> ans;
    for(int j=0; j<len; j++){           
        if(j%2==0){
            if(j==0){
                for(int i=0; i<n; i++){
                    //if(code[i][j]!='X' && (code[i+1][j]!='X' || code[i][j+1]!='X')){
                    //if(code[i][j]!='X'){
                        ans.push_back(code[i][j]);
                    //}
                }
            }else{
                for(int i=1; i<n; i++){
                    //if(code[i][j]!='X'){
                        ans.push_back(code[i][j]);
                    //}
                }
            }
        }else{
            for(int i=n-2; i>=0; i--){
                //if(code[i][j]!='X'){
                    ans.push_back(code[i][j]);
                //}
            }
        }
    }
    int temp = ans.size()-1;
    while(ans.at(temp) == 'X'){
        temp--;
    }
    for(int i=0; i<=temp; i++){
        cout << ans.at(i);
    }
}
