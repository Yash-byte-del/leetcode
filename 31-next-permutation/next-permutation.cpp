class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int n = A.size();
        int pivot = -1;

        // Step 1: find pivot
        for(int i = n - 2; i >= 0; i--) {
            if(A[i] < A[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2: if no pivot, reverse entire array
        if(pivot == -1) {
            reverse(A.begin(), A.end());
            return;
        }

        // Step 3: find next greater element
        for(int i = n - 1; i > pivot; i--) {
            if(A[i] > A[pivot]) {
                swap(A[i], A[pivot]);
                break;
            }
        }

        // Step 4: reverse suffix
        reverse(A.begin() + pivot + 1, A.end());
    }
};
