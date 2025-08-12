//#include <iostream>
//using namespace std;
//
//
//void bubbleSort(int arr[], int n) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - 1 - i; j++) {
//            if (arr[j] > arr[j + 1]) {
//                // Swap
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
//
//// Remove duplicates from sorted array, 
//int removeDuplicates(int arr[], int n) {
//    
//
//    int j = 0; 
//
//    for (int i = 0; i < n - 1; i++) {
//        
//        if (arr[i] != arr[i + 1]) {
//            arr[j++] = arr[i];
//        }
//    }
//
//    arr[j++] = arr[n - 1]; 
//
//    return j; 
//}
//
//int main() {
//    int arr[] = {2,3,2,6,2};
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    bubbleSort(arr, n);  
//    int newSize = removeDuplicates(arr, n);  
//    
//    cout << "Array after deleting duplicates: ";
//    for (int i = 0; i < newSize; i++) {
//        cout << arr[i] << " ";
//    }
//
//    return 0;
//}
//

// binary search implementation
//#include <iostream>
//using namespace std;
//
//int binarySearch(int arr[], int n, int target) {
//    int low = 0, high = n - 1;
//    while (low <= high) {
//        int mid = (low + high) / 2;
//        if (arr[mid] == target)
//            return mid;
//        else if (arr[mid] < target)
//            low = mid + 1;
//        else
//            high = mid - 1;
//    }
//    return -1; 
//}
//
//int main() {
//    int arr[] = {2, 4, 6, 8, 10, 12, 14};
//    int n = sizeof(arr) / sizeof(arr[0]);
//    int target = 10;
//
//    int result = binarySearch(arr, n, target);
//    if (result != -1)
//        cout << "Element found at index: " << result << endl;
//    else
////        cout << "Element not found" << endl;
////
////    return 0;
////}
////
//
//-------------------------- sparse matrix operations --------------------------//
//#include <iostream>
//using namespace std;
//
//struct Triple {
//    int row, col, val;
//};
//
//// ----------------------
//// (a) Transpose Function
//// ----------------------
//void transpose(Triple mat[], Triple trans[]) {
//    // First row: swap rows & columns
//    trans[0].row = mat[0].col;
//    trans[0].col = mat[0].row;
//    trans[0].val = mat[0].val;
//
//    int k = 1;
//    // Go column by column in original
//    for (int i = 0; i < mat[0].col; i++) {
//        for (int j = 1; j <= mat[0].val; j++) {
//            if (mat[j].col == i) {
//                trans[k].row = mat[j].col;
//                trans[k].col = mat[j].row;
//                trans[k].val = mat[j].val;
//                k++;
//            }
//        }
//    }
//}
//
//// ----------------------
//// (b) Addition Function
//// ----------------------
//void addSparse(Triple mat1[], Triple mat2[], Triple sum[]) {
//    if (mat1[0].row != mat2[0].row || mat1[0].col != mat2[0].col) {
//        cout << "Addition not possible: different dimensions!" << endl;
//        return;
//    }
//
//    int n1 = mat1[0].val;
//    int n2 = mat2[0].val;
//    int i = 1, j = 1, k = 1;
//
//    sum[0].row = mat1[0].row;
//    sum[0].col = mat1[0].col;
//
//    while (i <= n1 && j <= n2) {
//        if (mat1[i].row < mat2[j].row || (mat1[i].row == mat2[j].row && mat1[i].col < mat2[j].col)) {
//            sum[k++] = mat1[i++];
//        }
//        else if (mat2[j].row < mat1[i].row || (mat2[j].row == mat1[i].row && mat2[j].col < mat1[i].col)) {
//            sum[k++] = mat2[j++];
//        }
//        else { // same position
//            int value = mat1[i].val + mat2[j].val;
//            if (value != 0) {
//                sum[k].row = mat1[i].row;
//                sum[k].col = mat1[i].col;
//                sum[k].val = value;
//                k++;
//            }
//            i++;
//            j++;
//        }
//    }
//
//    while (i <= n1) sum[k++] = mat1[i++];
//    while (j <= n2) sum[k++] = mat2[j++];
//
//    sum[0].val = k - 1; // store number of non-zero elements
//}
//
//// ----------------------
//// (c) Multiplication Function
//// ----------------------
//void multiplySparse(Triple mat1[], Triple mat2[], Triple result[]) {
//    if (mat1[0].col != mat2[0].row) {
//        cout << "Multiplication not possible: incompatible dimensions!" << endl;
//        return;
//    }
//
//    Triple transB[100];
//    transpose(mat2, transB); // transpose B for easier matching
//
//    int k = 1;
//    result[0].row = mat1[0].row;
//    result[0].col = mat2[0].col;
//
//    for (int i = 0; i < mat1[0].row; i++) {
//        for (int j = 0; j < transB[0].row; j++) {
//            int sumVal = 0;
//            for (int a = 1; a <= mat1[0].val; a++) {
//                if (mat1[a].row != i) continue;
//                for (int b = 1; b <= transB[0].val; b++) {
//                    if (transB[b].row != j) continue;
//                    if (mat1[a].col == transB[b].col) {
//                        sumVal += mat1[a].val * transB[b].val;
//                    }
//                }
//            }
//            if (sumVal != 0) {
//                result[k].row = i;
//                result[k].col = j;
//                result[k].val = sumVal;
//                k++;
//            }
//        }
//    }
//    result[0].val = k - 1;
//}
//
//// ----------------------
//// Print Function
//// ----------------------
//void printSparse(Triple mat[]) {
//    for (int i = 0; i <= mat[0].val; i++) {
//        cout << mat[i].row << " " << mat[i].col << " " << mat[i].val << endl;
//    }
//    cout << endl;
//}
//
//// ----------------------
//// Main Program
//// ----------------------
//int main() {
//    Triple A[] = {
//        {3, 3, 3}, // rows, cols, non-zeros
//        {0, 0, 5},
//        {1, 1, 8},
//        {2, 2, 3}
//    };
//
//    Triple B[] = {
//        {3, 3, 3},
//        {0, 1, 4},
//        {1, 2, 7},
//        {2, 0, 6}
//    };
//
//    cout << "Matrix A:" << endl;
//    printSparse(A);
//
//    cout << "Matrix B:" << endl;
//    printSparse(B);
//
//    // (a) Transpose
//    Triple transA[100];
//    transpose(A, transA);
//    cout << "(a) Transpose of A:" << endl;
//    printSparse(transA);
//
//    // (b) Addition
//    Triple sum[100];
//    addSparse(A, B, sum);
//    cout << "(b) A + B:" << endl;
//    printSparse(sum);
//
//    // (c) Multiplication
//    Triple product[100];
//    multiplySparse(A, B, product);
//    cout << "(c) A × B:" << endl;
//    printSparse(product);
//
//    return 0;
//}
//


//#include <iostream>
//using namespace std;
//
//int countInversions(int arr[], int n) {
//    int count = 0;
//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (arr[i] > arr[j])
//                count++;
//        }
//    }
//    return count;
//}
//
//int main() {
//    int arr[] = {2, 4, 1, 3, 5};
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    cout << "Number of inversions: " << countInversions(arr, n) << endl;
//    return 0;
//}



//
//#include <iostream>
//using namespace std;
//
//int main() {
//    int arr[] = {1, 2, 2, 3, 4, 4, 5};
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    int distinctCount = 0;
//
//    for (int i = 0; i < n; i++) {
//        bool isDuplicate = false;
//        for (int j = 0; j < i; j++) { 
//            if (arr[i] == arr[j]) {
//                isDuplicate = true;
//                break;
//            }
//        }
//        if (!isDuplicate) {
//            distinctCount++;
//        }
//    }
//
//    cout << "Number of distinct elements: " << distinctCount << endl;
//    return 0;
//}
