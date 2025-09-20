#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const vector<int> *A = &nums1, *B = &nums2;
        if (A->size() > B->size()) swap(A, B);       // binary search smaller array

        int m = (int)A->size(), n = (int)B->size();
        int totalLeft = (m + n + 1) / 2;

        int lo = 0, hi = m;
        while (lo <= hi) {
            int i = (lo + hi) / 2;                   // cut in A
            int j = totalLeft - i;                   // cut in B

            int Aleft  = (i ? (*A)[i - 1] : numeric_limits<int>::min());
            int Aright = (i < m ? (*A)[i] : numeric_limits<int>::max());
            int Bleft  = (j ? (*B)[j - 1] : numeric_limits<int>::min());
            int Bright = (j < n ? (*B)[j] : numeric_limits<int>::max());

            if (Aleft <= Bright && Bleft <= Aright) {
                if ((m + n) & 1) {
                    return static_cast<double>(max(Aleft, Bleft));
                }
                // cast before adding to avoid int overflow
                double leftMax  = static_cast<double>(max(Aleft, Bleft));
                double rightMin = static_cast<double>(min(Aright, Bright));
                return (leftMax + rightMin) / 2.0;
            } else if (Aleft > Bright) {
                hi = i - 1;                          // move cut left
            } else {
                lo = i + 1;                          // move cut right
            }
        }
        // If both arrays are empty (undefined per problem), return 0.0 as a guard.
        return 0.0;
    }
};
