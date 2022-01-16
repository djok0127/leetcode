// leetcode problems
//  median of two sorted arrays
#include <iostream>
using namespace std;
#include <vector>

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int sorted_size = nums1.size()+nums2.size();
    cout << "sort size : " << sorted_size << endl;
    cout << "sorted median: " << sorted_size/2 << endl;

    vector<double> sorted(sorted_size, 0.0);
    int nums1_i = 0;
    int nums2_i = 0;

    // sort vector
    for(int cur_idx = 0; cur_idx < sorted_size; cur_idx++) {
        if (nums1.size() <= nums1_i) {
            sorted[cur_idx] = nums2[nums2_i];
            nums2_i++;
        } else if(nums2.size() <= nums2_i){
            sorted[cur_idx] = nums1[nums1_i];
            nums1_i++;
        } 
        else {
            if (nums1[nums1_i] > nums2[nums2_i]) {
                sorted[cur_idx] = nums2[nums2_i];
                nums2_i++;
            } else {
                sorted[cur_idx] = nums1[nums1_i];
                nums1_i++;
            }
        }
        cout << "sorted: " << sorted[cur_idx] << endl;
    }
    

    double median = sorted[sorted_size/2];

    if (sorted_size % 2 == 0) {
        // even need to calculate median
        median = (sorted[sorted_size/2 - 1] + median)/2;
    }
    return median;
}

int main(int argc, char *argv[]) {
    int x;
    int y;
    vector<int> v1;
    vector<int> v2;
    cout << "number input x :";
    for (int i = 0; i < 2; i++) {
        cin >> x;
        v1.push_back(x);
    }
    cout << "number input Y: ";
    for (int i = 0; i<2; i++){
        cin >> y;
        v2.push_back(y);
    }
    cout << "answer: " << findMedianSortedArrays(v1,v2) << endl;

    cin >> x;

    return 0;
}
