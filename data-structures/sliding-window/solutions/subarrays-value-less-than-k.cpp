#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

/*
    Calculate the number of subarrays in nums
    where all elements are less than K

    With SlidingWindow
*/
int subArrayCountLessThanKSW(vector<int> &nums, int k) {
    int n = nums.size();

    int ws = 0, we = 0;
    int ans = 0;
    int countMoreThanK = 0;
    
    while (we < n) {
        if (nums[we++] > k) {
            countMoreThanK += 1;
        }

        if (countMoreThanK > 0) {
            while (countMoreThanK > 0 && ws < we) {
                if (nums[ws++] > k) {
                    countMoreThanK -= 1;
                }
            }
        } else {
            ans += (we - ws);
        }
    }
    return ans;
}

/*
    Calculate the number of subarrays in nums
    where all elements are less than K

    With unordered_map
*/
int subArrayCountLessThanK(vector<int> &nums, int k) {
    int n = nums.size();
    int ans = 0;
    int sum = 0;

    unordered_map<int, int> map;
    map[0] = 1;

    for (int i=0; i<n; i++) {
        sum += nums[i] > k;

        if (map.find(sum) != map.end()) {
            ans += map[sum];
        }
        map[sum] += 1;
    }

    return ans;
}   

struct Testcase {
    vector<int> nums;
    int k;
    int expected;
};

int main() {
    time_t start, end; 

    Testcase testCases[] = {
        {
            {1, 5, 7, 8, 2, 3, 9},
            6,
            6
        },
        {
            {1, 10, 12, 4, 5, 3, 2, 7},
            9,
            16
        },
        {
            {1, 5, 1, 4, 5, 3, 2, 7},
            9,
            36
        },
        {
            {1, 5, 1, 4, 5, 3, 2, 7},
            4,
            7
        }
    };

    time(&start);

    for (auto &tc: testCases) {
        cout<<"Input:\nArray: ";
        for (auto &c: tc.nums) {
            cout<<c<<" ";
        }
        cout<<"\nk: "<<tc.k<<endl;
        cout<<"Output: "<<subArrayCountLessThanK(tc.nums, tc.k)<<endl<<endl;
    }

    time(&end);

    double time_taken = double(end - start); 
    cout << "Time taken by program is : " << fixed 
        << time_taken << setprecision(15); 
    cout << " sec " << endl; 

    return 0;
}