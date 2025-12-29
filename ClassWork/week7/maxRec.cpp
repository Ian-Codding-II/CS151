#include <iostream>

using std::cout, std::endl, std::cin;

int max(int m, int arr[], int size);

int main() {
    int num[5] = {-1, 12, 3, -543, 43};

    cout << "The biggest number in the array is: " << max(num[0], num + 1, 4) << endl;

    return 0;
}

int max(int m, int arr[], int size) {

    return size == 0 ? m : arr[0] > m ? max(arr[0], arr + 1, size - 1)
                                      : max(m, arr + 1, size - 1);
}