
#include <iostream>
#include <vector>

using namespace std;


int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

       
        if (arr[mid] == target) {
            return mid;
        }
        
        else if (arr[mid] < target) {
            left = mid + 1;
        }
       
        else {
            right = mid - 1;
        }
    }

    return -1;
}


int main() {
    vector<int> arr = {2, 5, 7, 10, 15, 20, 25, 30};
    int target = 22;

    int index = binarySearch(arr, target);

    if (index != -1) {
        cout << "Element  " << target << " found at index " << index << endl;
    } else {
        cout << "Element  " << target << " not found in array.\n";
    }

    return 0;
}