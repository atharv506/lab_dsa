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


//
//
//#include <iostream>
//#include <cstring>  // For strcat, strcpy, strcmp, strlen
//#include <cctype>   // For tolower
//using namespace std;
//
//// (a) Concatenate two strings
//void concatenateStrings() {
//    char str1[100], str2[50];
//    cout << "Enter first string: ";
//    cin >> str1;
//    cout << "Enter second string: ";
//    cin >> str2;
//
//    strcat(str1, str2); // Append str2 to str1
//    cout << "Concatenated string: " << str1 << endl;
//}
//
//// (b) Reverse a string
//void reverseString() {
//    char str[100];
//    cout << "Enter a string: ";
//    cin >> str;
//
//    int len = strlen(str);
//    for (int i = 0; i < len / 2; i++) {
//        char temp = str[i];
//        str[i] = str[len - i - 1];
//        str[len - i - 1] = temp;
//    }
//    cout << "Reversed string: " << str << endl;
//}
//
//// (c) Delete all vowels from string
//void deleteVowels() {
//    char str[100], result[100];
//    cout << "Enter a string: ";
//    cin >> str;
//
//    int j = 0;
//    for (int i = 0; str[i] != '\0'; i++) {
//        char ch = tolower(str[i]);
//        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
//            result[j++] = str[i];
//        }
//    }
//    result[j] = '\0';
//    cout << "String without vowels: " << result << endl;
//}
//
//// (d) Sort strings in alphabetical order
//void sortStrings() {
//    int n;
//    char str[50][50];
//    cout << "Enter number of strings: ";
//    cin >> n;
//
//    cout << "Enter strings:\n";
//    for (int i = 0; i < n; i++) {
//        cin >> str[i];
//    }
//
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (strcmp(str[i], str[j]) > 0) { // Compare alphabetically
//                char temp[50];
//                strcpy(temp, str[i]);
//                strcpy(str[i], str[j]);
//                strcpy(str[j], temp);
//            }
//        }
//    }
//
//    cout << "Sorted strings:\n";
//    for (int i = 0; i < n; i++) {
//        cout << str[i] << endl;
//    }
//}
//
//// (e) Convert a character from uppercase to lowercase
//void convertUpperToLower() {
//    char ch;
//    cout << "Enter an uppercase character: ";
//    cin >> ch;
//
//    ch = tolower(ch); // Convert to lowercase
//    cout << "Lowercase character: " << ch << endl;
//}
//
//// Main menu
//int main() {
//    int choice;
//    do {
//        cout << "\nString Operations Menu:\n";
//        cout << "1. Concatenate Strings\n";
//        cout << "2. Reverse String\n";
//        cout << "3. Delete Vowels\n";
//        cout << "4. Sort Strings Alphabetically\n";
//        cout << "5. Convert Uppercase to Lowercase\n";
//        cout << "0. Exit\n";
//        cout << "Enter choice: ";
//        cin >> choice;
//
//        switch (choice) {
//            case 1: concatenateStrings(); break;
//            case 2: reverseString(); break;
//            case 3: deleteVowels(); break;
//            case 4: sortStrings(); break;
//            case 5: convertUpperToLower(); break;
//            case 0: cout << "Exiting...\n"; break;
//            default: cout << "Invalid choice!\n";
//        }
//    } while (choice != 0);
//
//    return 0;
//}
//
//
//
////#include <iostream>
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
