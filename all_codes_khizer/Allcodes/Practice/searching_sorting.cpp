#include <iostream>
#include <algorithm>
using namespace std;
void display(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int size, int arr[])
{
    int comparisons = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size - i; j++)
        {
            comparisons++;
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
            }
        }
    }

    cout << "Buuble Sort comperisons" << comparisons << endl;
}

void selectionSort(int size, int arr[])
{
    int comparisons = 0;
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i; j < size - 1; j++)
        {
            comparisons++;
            if (arr[j + 1] < arr[min])
            {
                min = j + 1;
            }
            swap(arr[min], arr[i]);
        }
    }
    cout << "Selection Sort comparisons" << comparisons << endl;
}
void insertionSort(int size, int arr[])
{
    int comparisons = 0;
    int i, j, key;
    for (i = 0; i < size - 1; i++)
    {
        j = i - 1;
        key = arr[i];
        while ((j >= 0) && (arr[j] > key))
        {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    cout << "Insertion Sort comparisons" << comparisons << endl;
}

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int l = mid - left + 1;
    int r = right - mid;

    int L[l], R[r];
    for (i = 0; i < l; i++)
    {
        L[i] = arr[left + i];
    }
    for (j = 0; j < r; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < l && j < r)
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
    }
    while (i < l)
    {
        arr[k] = L[i];
        k++;
        i++;
    }
    while (j < r)
    {
        arr[k] = R[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int binarySearchRecursive(int arr[], int left, int right, int key, int &comparsions)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
        {
            cout << "Value found " << endl;
            return mid;
        }
        else if (arr[mid] > key)
        {
           return binarySearchRecursive(arr, left, mid - 1, key, comparsions);
            comparsions++;
        }
        else if (arr[mid] < key)
        {
           return binarySearchRecursive(arr, mid + 1, right, key, comparsions);
            comparsions++;
        }
    }
    else
    return -1;
}
int binarySearchIterative(int arr[],int size,int key, int &comparisons)
{
    int l=0;
    int r=size-1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==key)
        {
            cout<<"Value found"<<endl;
            return mid;
        }
        else if(arr[mid]>key)
        {
            r=mid-1;
            comparisons++;
        }
        else if(arr[mid]<key)
        {
            l=mid+1;
            comparisons++;
        }

    }
    
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
        mergeSort(arr, 0, size - 1);
        display(size, arr);
        break;
    case 5:
    {
        int key;
        cout << "Enter the value to find: ";
        cin >> key;
        int comparisons = 0;
        sort(arr, arr + size);
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
    {
        cout << "Invalid choice\n";
        break;
    }
    }

    return 0;
}
