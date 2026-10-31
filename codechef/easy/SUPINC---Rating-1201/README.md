# SUPINC - Rating 1201

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Superincreasing

An array $A$ of length $N$ containing  **positive**  integers is said to be  *superincreasing*  if each element is  **strictly greater**  than the sum of all the previous elements.

That is, for each $i$ from $2$ to $N$, the condition

$$ A_i \gt A_1 + A_2 + \ldots + A_{i-1} $$

should hold.
For example, $A = [3, 5, 10, 42]$ is a superincreasing array, while $A = [1, 2, 3]$ is not ($3 = 1+2$, but it should be  *strictly greater*  than that).

Chef had a superincreasing array $A$ of length $N$ with him a long time ago, but has forgotten all its elements now.
The only piece of information he recalls is that the value $X$ occurred at index $K$ of the array, i.e, $A_K = X$.

Can you tell Chef if he recalls correctly?
That is, does there exist a superincreasing array $A$ of length $N$ such that $A_K = X$?

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- The first and only line of each test case contains three space-separated integers $N, K,$ and $X$ — the length of $A$, the index at which $X$ occurs, and the value $X$.
### Output Format

For each test case, output on a new line the answer: `Yes` if a valid superincreasing array exists, and `No` otherwise.

Each letter of the output may be printed in either uppercase or lowercase, i.e, the strings `NO`, `no, `No`, and `nO` will all be treated as equivalent.

### Constraints
- $1 \leq T \leq 10^5$
- $1 \leq K \leq N \leq 2\cdot 10^5$
- $1 \leq X \leq 10^9$
- The sum of $N$ across all tests won't exceed $2\cdot 10^5$.
### Sample 1:
Input
Output

```
4
3 2 3
3 3 3
5 3 6
6 2 1

```

```
Yes
No
Yes
No
```

### Explanation:

 **Test case $1$:**  We have $N = 3, K = 2, X = 3$.
Consider the array $A = [1, 3, 10]$. It's superincreasing because $3\gt 1$ and $10\gt 1+3$, and has $A_2 = 3$, as desired.

 **Test case $2$:**  We have $N = 3, K = 3, X = 3$.
It can be shown that no superincreasing array of length $3$ that contains positive integers can have $A_3 = 3$.
Note that $A = [1, 2, 3]$ is  *not*  superincreasing: $A_3$ should be  **strictly**  larger than $A_1+A_2$.

 **Test case $3$:**  One example of a valid array is $A = [2, 3, 6, 15, 60]$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-31T08:39:41.983Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t ;
    cin>>t ;
    while(t--){
       int n , k, x ;
       cin>>n>>k>>x ;
       
       vector<int> nums(n);
       nums[k-1] = x ;
     
       int strt = 1 ;
       int prev = 0;
       bool temp = true;
       for(int i = 0 ; i<n ; i++){
          nums[i] = strt ;
          strt = nums[i] +1 ;
       }
       if(nums[k-1] >= x){
           cout<<"NO"<<endl;
       }else{
           cout<<"YES"<<endl;
       }
        
        
        
    }
    
   return 0; 
}

```

---

[View on CodeChef](https://www.codechef.com/problems/SUPINC)