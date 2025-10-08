#include<bits/stdc++.h>
using namespace std;
void quickSort(int a[], int l, int h) {
    if (l < h) {
        int p = a[h];
        int i = l - 1;
        for (int j = l; j < h; j++) {
            if (a[j] < p) {
                i++;
                swap(a[i], a[j]);
            }
        }
        swap(a[i + 1], a[h]);
        int pi = i + 1;
        quickSort(a, l, pi - 1);
        quickSort(a, pi + 1, h);
    }
}
int main() {
    int a[] = {10, 2, 3, 5, 1, 9, 17};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Original Array: 10 2 3 5 1 9 17" << endl;
    quickSort(a, 0, n - 1);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
