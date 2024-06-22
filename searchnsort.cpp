// Binary search using iterative approach
/* #include <iostream>
using namespace std;
void binarySearch(int arr[], int size, int key)
{
    int l = 0;
    int h = size - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] == key)
        {
            cout << key << " found at index = " << mid << endl;
            return;
        }
        else if (arr[mid] < key)
        {
            l = mid + 1;
        }
        else if (arr[mid] > key)
        {
            h = mid - 1;
        }
    }
    cout << "Element not found in array!";
}

int main()
{
    int arr[]={2,4,6,7,8};
    binarySearch(arr,5,6);
} */

// Binary search using iterative approach
/* #include <iostream>
using namespace std;
void binarySearch(int arr[], int l, int h, int key)
{
    int mid = (l + h) / 2;
    if (arr[mid] == key)
    {
        cout << key << " found at index =" << mid << endl;
    }
    else if (arr[mid] > key)
    {
        binarySearch(arr, l, mid - 1, key);
    }
    else if (arr[mid] < key)
    {
        binarySearch(arr, mid + 1, h, key);
    }
    else
        cout << "Elemnt not found in the array" << endl;
}
int main()
{
    int arr[] = {2, 4, 6, 7, 8};
    binarySearch(arr, 0, 4, 20);
} */

// Selection sort
#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
                ;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        // if no elements are swapped in the round (i.e array is sorted)
        if (flag == false)
            break;
    }
    printArray(arr, 6);
}

void insertionSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        // to shift all elements greater han key to left by one place
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printArray(arr, n);
}


    int main()
    {
        int arr[] = {2, 4, 1, 0, 8, 5};
        printArray(arr, 6);
        insertionSort(arr, 6);
    }