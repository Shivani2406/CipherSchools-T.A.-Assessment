// Q1. Given an array nums containing n distinct numbers
// in the range [0, n], return the only number in the range
// that is missing from the array. Input: nums = [3,0,1], Output: 2 .

#include <iostream>

using namespace std;

int main()
{
    int n, i, elem, expected_sum, sum_arr_elem=0;
    cin >> n;  // take user input for n
    expected_sum = n*(n+1)/2;  // formula for sum of first n whole numbers

    for (i=0; i<n; i++){
        cin >> elem;
        sum_arr_elem += elem;
    }

    cout << (expected_sum - sum_arr_elem);
    // missing number = (sum of first n whole numbers) - (sum of array elements)
    return 0;
}
