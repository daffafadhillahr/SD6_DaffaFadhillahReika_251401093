// Binary Searching
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binaryIterative(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int iterations = 0;

    cout << "\n=== BINARY SEARCH ITERATIVE ===" << endl;
    cout << "Angka yang akan dicari: " << target << endl;

    while (left <= right) {
        iterations++;
        int middle = left + (right - left) / 2; // (right + left) / 2

        cout << "Iterasi " << iterations << ": "
        << "Left=" << left << ", Right=" << right << ", Middle=" << middle
        << ", Nilai[" << middle << "]=" << arr[middle] << endl;

        if (arr[middle] == target) {
            cout << "Data ditemukan pada indeks " << middle << endl;
            return middle;
        }
        if (target < arr[middle]) {
            cout << "Target lebih kecil, cari di bagian kiri" << endl;
            right = middle - 1;
        } else {
            cout << "Target lebih besar, cari di bagian kanan" << endl;
            left = middle + 1;
        }
    }
    cout << "Data tidak ditemukan" << endl;
    return -1;
}

int binarySearchRecursive(vector<int>& arr, int left, int right, int target, int& iterations) {
    if (iterations == 0) {
        cout << "\n=== BINARY SEARCH RECURSIVE ===" << endl;
        cout << "Angka yang dicari: " << target << endl;
    }
    if (left > right) {
        cout << "Data tidak ditemukan" << endl;
        return -1;
    }

    iterations++;
    int middle = left + (right - left) / 2;

    cout << "Rekursi " << iterations << ": "
    << "Left=" << left << ", Right=" << right << ", Middle=" <<
    middle << ", Nilai[" << middle << "]=" << arr[middle] << endl;

    if (arr[middle] == target) {
        cout << "Data ditemukan pada indeks " << middle << endl;
        return middle;
    }
    if (target < arr[middle]) {
        cout << "Target lebih kecil, cari di bagian kiri" << endl;
        return binarySearchRecursive(arr, left, middle - 1, target, iterations);
    } else {
        cout << "Target lebih besar, cari di bagian kanan" << endl;
        return binarySearchRecursive(arr, middle + 1, right, target, iterations);
    }
}

void printArray(const vector<int>& arr, const string& title) {
    cout << title << ": ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    system("cls");
    vector<int> data = {12, 9, 52, 26, 30, 36, 21};

    sort(data.begin(), data.end());

    printArray(data, "Array awal");

    int target;
    cout << "\nMasukkan angka yang ingin dicari: ";
    cin >> target;

    // Contoh penggunaan binary iteratif
    binaryIterative(data, target);

    // Contoh penggunaan binary rekursif
    int iterations = 0;
    int result = binarySearchRecursive(data, 0, data.size() - 1, target, iterations);

    return 0;
}