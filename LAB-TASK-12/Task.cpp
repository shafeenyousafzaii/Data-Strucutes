#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void bubbleSort(int size, int arr[])
{
    int comparisons = 0;
    for (int i = 0; i < (size - 1); i++)
    {
        // comparisons++;
        for (int j = 1; j < (size - i); j++)
        {
            comparisons++;
            if (arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
        }
    }
    cout << "Bubble Sort Comparisons: " << comparisons << endl;
}

void selectionSort(int size, int arr[])
{
    int comparisons = 0;
    int count = 0;
    for (int i = 0; i <= size - 1; i++)
    {
        // comparisons++;
        int min = i;
        for (int j = i; j <= size - 1; j++)
        {
            comparisons++;
            // cout << "Selection Sort Comparisons: " << i+j << endl;
            if (arr[min] > arr[j + 1])
            {
                // count++;
                min = j + 1;
            }
            // count++;
        }
        // cout << "count ; " << count << endl;
        // comparisons++;
        swap(arr[min], arr[i]);
    }
    cout << "Selection Sort Comparisons: " << comparisons-size  << endl;
    // cout << "count : " << count << endl;
}

void insertionSort(int size, int arr[])
{
    int comparisons = 0;
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            comparisons++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    cout << "Insertion Sort Comparisons: " << comparisons << endl;
}
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r , int size)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m,size);
        mergeSort(arr, m + 1, r,size);

        merge(arr, l, m, r);
    }
    display(size,arr);
}

int binarySearchRecursive(int arr[], int left, int right, int key, int &comparisons)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            return binarySearchRecursive(arr, mid + 1, right, key, comparisons);
        else
            return binarySearchRecursive(arr, left, mid - 1, key, comparisons);
    }
    return -1;
}

int binarySearchIterative(int arr[], int size, int key, int &comparisons)
{
     int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        comparisons++; 
        if (arr[mid] == key)
        {
            return mid; 
        }
        else if (arr[mid] < key)
        {
            left = mid + 1; 
        }
        else
        {
            right = mid - 1; 
        }
    }

    return -1;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "\nMenu:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Binary Search (Recursive)\n";
    cout << "6. Binary Search (Iterative)\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        bubbleSort(size, arr);
        break;
    case 2:
        selectionSort(size, arr);
        break;
    case 3:
        insertionSort(size, arr);
        display(size, arr);
        break;
    case 4:
        mergeSort(arr, 0, size - 1, size);
        display(size, arr);
        break;
    case 5:
    {
        int key;
        cout << "Enter the value to find: ";
        cin >> key;
        int comparisons = 0;
        int result = binarySearchRecursive(arr, 0, size - 1, key, comparisons);
        if (result != -1)
        {
            cout << "Element found at index " << result << endl;
        }
        else
        {
            cout << "Element not found\n";
        }
        cout << "Comparisons: " << comparisons << endl;
        break;
    }
    case 6:
    {
        int key;
        cout << "Enter the value to find: ";
        cin >> key;
        int comparisons = 0;
        int result = binarySearchIterative(arr, size, key, comparisons);
        if (result != -1)
        {
            cout << "Element found at index " << result << endl;
        }
        else
        {
            cout << "Element not found\n";
        }
        cout << "Comparisons: " << comparisons << endl;
        break;
    }
    default:
        cout << "Invalid choice\n";
    }

    return 0;
}
