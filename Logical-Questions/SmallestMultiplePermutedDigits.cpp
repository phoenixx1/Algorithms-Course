//author @Nishant

#include <bits/stdc++.h>
using namespace std;

/*long int combo(long int a, long int b);

int main()
{
    long int N, d;
    cin >> N >> d;
    vector<long int> num;
    while (N > 0)
    {
        long int x = N % 10;
        if(x != 0){
            num.push_back(x);
        }
        N = N / 10;
    }
    sort(num.begin(), num.end());
    long int number = num.at(0);
    for(long int i=1; i<num.size(); i++){
        number = combo(number, num.at(i));
    }
    //cout << number;
    vector<long int> combinations;
    long int temp = number;
    long int n = num.size();
    while(1){
        combinations.push_back(temp);
        long int rem = temp % 10; 
        long int div = temp / 10; 
        temp = (pow(10, n - 1)) * rem + div; 
        if (temp == number)  
            break; 
    }
    
    sort(combinations.begin(), combinations.end());
    int c1 = 0;
    for(long int i=0; i<combinations.size(); i++){
        if(combinations.at(i)%d == 0){
            cout << combinations.at(i);
            c1++;
            break;
        }
    }
    if(c1 == 0){
        cout << "-1";
    }
    
}

long int combo(long int a, long int b){
    long int x = 10;
    while(b >= 10){
        x *= 10;
    }
    return a * x + b;
}
*/
int combo(int a,  int b);
vector<int> heapPermutation(vector<int> a, int size, int n, int d); 
int printArr(vector<int> a,int n);

int main()
{
    int N, d;
    cin >> N >> d;
    vector<int> num;
    while (N > 0)
    {
        int x = N % 10;
        
            num.push_back(x);
        
        N = N / 10;
    }
    sort(num.begin(), num.end());
    //cout << num.at(0);
    vector<int> combinations;
    combinations = heapPermutation(num, num.size(), num.size(), d);
    //long int number = num.at(0);
    //for(long int i=1; i<num.size(); i++){
    //    number = combo(number, num.at(i));
    //}
    //cout << number;

    //vector<long int> combinations;
    //long int temp = number;
    //long int n = num.size();
    // while(1){
    //     combinations.push_back(temp);
    //     long int rem = temp % 10; 
    //     long int div = temp / 10; 
    //     temp = (pow(10, n - 1)) * rem + div; 
    //     if (temp == number)  
    //         break; 
    // }
    
    sort(combinations.begin(), combinations.end());
    int c1 = 0;
  	vector<int> finalAns;
    for(long int i=0; i<combinations.size(); i++){
        
        if(combinations.at(i)%d == 0){
            //finalAns.push_back(combinations.at(i));
            cout << combinations.at(i) << endl;
            c1++;
        }
    }
    // if(c1 == 0){
    //     cout << "-1";
    // }else{
  	// 	sort(finalAns.begin(), finalAns.end());
  	// 	cout << finalAns.at(0);
    // }
    
}

int combo(int a, int b){
    long int x = 10;
    while(b >= 10){
        x *= 10;
    }
    return a * x + b;
}

int printArr(vector<int> a,int n) 
{ 
    long int number = a.at(0);
    for(long int i=1; i<n; i++){
        number = combo(number, a.at(i));
    }
    return number;
} 
  

vector<int> heapPermutation(vector<int> a, int size, int n, int d)
{ 
    vector<int> combo;
    if (size == 1) 
    { 
        combo.push_back(printArr(a, n)); 
        return combo; 
    } 
  
    for (int i=0; i<size; i++) 
    { 
        combo = heapPermutation(a,size-1,n, d); 
  
        if (size%2==1) 
            swap(a[0], a[size-1]); 
  
        else
            swap(a[i], a[size-1]); 
    } 
    return combo;
} 

/*
#include<bits/stdc++.h>
using namespace std;
//#include<math.h>

int main()
{
  int N, d, i,j,temp=0,count=0;
  int arr[20];
  cin>>N>>d;
 
  while(N>0)
  {
    arr[count] = N % 10;
    N /= 10;
    count++;
  }
 
  for(i = 0;i<count;i++)
  {
    for(j=0;j<count;j++)
    {
      if(arr[i]<arr[j])
      {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }
  }
 
  for(i = 0;i<count;i++)
  {
    //cout<<arr[i]<<" ";
    if(arr[i]==0)
    {
      temp++;
    }
  }
  //cout<<temp;
  int len = count-temp;
  int farr[count];
  for(i=0;i<len;i++)
  {
    farr[i] = arr[temp++];
  }
  
 
  int num=0;
  
  int flag=0;
  do
  {
    for(i=0;i<len;i++)
  {
    num = num*10 + farr[i];
  }
    if(num%d == 0)
    {
      cout<<num;
      flag++;
      break;
    }
    num = 0;
  }while(next_permutation(farr,farr+len));
  
  if(flag == 0)
  {
    cout<<"-1";
  }
  return 0;
}
*/