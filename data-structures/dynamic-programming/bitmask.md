# Bitmask

## Iterating Through All Bitmasks
Simple iteration using a `for` loop over all of the subsets of an array of size `n`
```cpp

// n -> Given Number
for (int i = 0; i < (1 << n); i++) {
    // perform any action
    // ...
    cout << bitset<16>(i) << endl;
}

```
## Enumerating All Submasks of a Mask
Given a mask, enumerate or find all of the submasks of this mask

`Submask` = A bitmask created from a given mask which consists of only its set bits

`Submasks` = A subset of a set containing all of the bitmasks that could be created with `N=k, say k=5` where only sets set bits were used of the original mask 

Eg: Given N=5 or Mask='101', then our submasks would be 5, 4, 1 or '101', '100', '001'

### Naive Approach 
The simplest approach is to traverse every mask in the range [0, 1 << (count of set bit in N)] and check if no other bits are set in it except for the bits in N. Then, print it. 

Time Complexity: O(2(count of set bit in N))

Auxiliary Space: O(1)

### Optimised Approach
The above approach can be optimized by only traversing the submasks which are the subset of mask N. 
- Take S = Mask as the initial position
- Next Mask would be S = (S-1) & Mask

Eg: Mask = 10 or 1010

1. S = 1010
2. S-1 = 1001 // Flip all unset bits on the right of the rightmost set bit including the set bit
3. S-1 & Mask = 1001 & 1010
4. New S = 1000
5. S-1 = 0111
6. S-1 & Mask = 0111 ^ 1010
7. New S = 0110 or 6
8. S-1 = 0101 or 5
9. S-1 & Mask = 0101 & 1010
10. New S = 0000

```cpp
for (int sub = mask; sub > 0; sub = (sub-1) & mask) {
    // perform anything
    // ...
    cout << bitset<16>(sub) << endl;
}
```
