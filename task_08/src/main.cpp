#include <iostream>
#include <vector>

int Select(std::vector<int>& array, int left, int right, int k) {
    if (left >= right) {
        return array[left];
    }

    int i = left;
    int j = right;

    int pivot = array[(left + right) / 2];
    while (i <= j) {
        while (array[i] < pivot) {
            i++;
        }

        while (array[j] > pivot) {
            j--;
        }

        if (i <= j) {
            std::swap(array[i], array[j]); 
            i++;
            j--;
        }
    }
     
    if (k <= j && left < j) {
        return Select (array, left, j, k);
    } 
    if (k >= i && i < right) {
        return Select(array, i, right, k);
    }
    return array[k];
}

int K(std::vector<int>& array, int left, int right, int k) {
    return Select(array, left, right, k - 1);
}


int main() { 
    std::vector<int> A = {5, 48, 5976, 486, 1918, 346, 356, 57, 912, 438, 132, 376};

    int d = K(A, 0, 11, 4 );

    std::cout << d << std::endl;
    return 0; 
}
