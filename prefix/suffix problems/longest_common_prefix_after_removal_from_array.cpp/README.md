
[Problem](https://leetcode.com/problems/longest-common-prefix-between-adjacent-strings-after-removals/description/)
Current Approach 
Consider only the previous word and next word for each index i
When taking suffix array into account, think that ith word contributes only at i and i-1 th index so you want to think of suffix(i+1) th index
when taking prefix array into account , think that ith word contributes only at i and i+1th index so you want to consider i-1 of prefix array

Similar to how 0th index and n-1 th work

At 0 : p(0) =0 and for suffix the current word will contribute at (0) index so think of taking max of p[0] & s[1]
At n-1 : the word will contribute toward prefix[n-1] but suffix(0) =0 ; take max of both 
