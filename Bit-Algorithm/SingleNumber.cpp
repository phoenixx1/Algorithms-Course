//author @Nishant

#include<bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/single-number/

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

If we take XOR of zero and some bit, it will return that bit
a ^ 0 = aa⊕0=a
If we take XOR of two same bits, it will return 0
a ^ a = 0a⊕a=0
a ^ b ^ a = (a ^ a) ^ b = 0 ^ b = b
*/

int singleNumber(vector<int>& nums) {
    int x = nums[0];
    for (int i = 1; i <nums.size() ; i++) {
        x ^= nums[i];
    }
    return x;
}

int main(){
    vector<int> nums{4,1,2,1,2};// take desired input by user this is an example I have taken here
    cout << singleNumber(nums);
}