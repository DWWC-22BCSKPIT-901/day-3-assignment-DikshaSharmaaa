#include <iostream>
#include <vector>
#include <algorithm> // For min_element and max_element
using namespace std;

// Function to compute GCD using Euclid's algorithm
int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // Example 1
    vector<int> nums1 = {2, 5, 6, 9, 10};
    int smallest1 = *min_element(nums1.begin(), nums1.end());
    int largest1 = *max_element(nums1.begin(), nums1.end());
    cout << "Input: nums = [2, 5, 6, 9, 10]" << endl;
    cout << "Output: " << findGCD(smallest1, largest1) << endl;

    // Example 2
    vector<int> nums2 = {7, 5, 6, 8, 3};
    int smallest2 = *min_element(nums2.begin(), nums2.end());
    int largest2 = *max_element(nums2.begin(), nums2.end());
    cout << "Input: nums = [7, 5, 6, 8, 3]" << endl;
    cout << "Output: " << findGCD(smallest2, largest2) << endl;

    // Example 3
    vector<int> nums3 = {3, 3};
    int smallest3 = *min_element(nums3.begin(), nums3.end());
    int largest3 = *max_element(nums3.begin(), nums3.end());
    cout << "Input: nums = [3, 3]" << endl;
    cout << "Output: " << findGCD(smallest3, largest3) << endl;

    return 0;
}
