/*
#include<stdio.h>
#include <string.h> 
#define MAX_SIZE 100

void printParenthesis(int left, int right, char str[]){
    static char result[MAX_SIZE];
    static int i=0;
    if(left==0 && right==0){
        printf("%s\n",str);
    }
    char open = '(';
    char close = ')';
    if(left>0)
        printParenthesis(left-1, right, strncat(str, &open, 1));
    if(right>0 && right>left)
        printParenthesis(left, right-1, strncat(str, &close, 1));
    
    
}

int main(){
    int n;
    scanf("%d", &n);
    char str[MAX_SIZE];
    if(n>0){
        printParenthesis(n, n, str);
    }else{
        return 0;
    }
    return 0;
}

void printParenthesis(int pos, int n, int open, int close){
    
    static char str[MAX_SIZE];
    
    if(n==close){
        printf("%s\n",str);
    }else{
        if(open > close)  
        { 
            str[pos] = ')'; 
            printParenthesis(pos+1, n, open, close+1); 
        } 
          
        if(open < n) 
        { 
            str[pos] = '('; 
            printParenthesis(pos+1, n, open+1, close); 
        } 
    }
}
*/