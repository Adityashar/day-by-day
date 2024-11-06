#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T> 
class heap {
    int max_size;
    int cur_size;
    vector<T> arr;
public:
    heap(int ms): max_size(ms) { }
    ~heap() {}

    bool push(T val) {
        if (cur_size == max_size)
            return false;

        arr.push_back(val);
        cur_size += 1;
        // heapify(0); Only used when the top needs to be fixed
        decrease_key(arr.size() - 1, val);

        return true;
    }

    T top() {
        return arr[0];
    }

    bool pop() {
        if (cur_size == 0)
            return false;

        swap(arr[0], arr.back());
        arr.pop_back();
        cur_size -= 1;
        heapify(0);

        return true;
    }


    // Assumes the Tree is already heapified
    void heapify(int root) {
        int n = arr.size();
        int left = 2 * root + 1, right = 2 * root + 2;

        int next = root;
        
        if (left < n && arr[left] < arr[next])
            next = left;
        if (right < n && arr[right] < arr[next])
            next = right;

        if (next != root) {
            swap(arr[next], arr[root]);
            heapify(next);
        }
    }

    // Inplace update the keys value
    void decrease_key(int i, T val) {
        arr[i] = val;
        int p = (i - 1) / 2;

        while (p >= 0 && arr[p] > arr[i]) {
            swap(arr[i], arr[p]);
            i = p;
            p = (i - 1) / 2;
        }
    }
};


void heapSort(vector<int> &arr) {
    int n = arr.size();

    heap<int> h(n+1);

    for (auto &i: arr) {
        h.push(i);
    }

    for (int i=0; i<n; i++) {
        arr[i] = h.top();
        h.pop();
    }

}

int main() {

    vector<int> arr = {2,-1,-5,6,7};
    heapSort(arr);

    for (auto &i: arr) {
        cout<<i<<" ";
    }

    return 0;
}
