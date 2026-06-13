#include <iostream>
#include <vector>

void quickSort (std::vector<int>& array, int left, int right) {
    if (left >= right) {
        return;
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
     
    if (left < j) {
        quickSort(array, left, j);
    }

    if (i < right) {
        quickSort(array, i, right);
    }
}



int main() { 
    std::vector<int> A = {5, 48, 5976, 486, 1918, 346, 356, 57, 912, 438, 132, 376};

    quickSort (A, 0, 11);

    for (int i : A){
        std::cout << i << ' ';
    }
    return 0; 
}

