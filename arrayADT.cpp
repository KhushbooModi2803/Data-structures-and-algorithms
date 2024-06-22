/* // Performing Operations on an Array
#include <stdio.h>
#include <stdlib.h>
struct array
{
    int *A;
    int size;
    int length;
};

void display(struct array arr)
{
    int i;
    printf("\nThe elements are: \n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}
void create(struct array *arr)
{
    int i, n;
    printf("Enter the size of the array: ");
    scanf("%d", &arr->size);
    arr->A = (int *)malloc(arr->size * sizeof(int));
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the numbers: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr->A[i]);
    }
    arr->length = n;
}
void append(struct array *arr, int x)
{
    if (arr->length == arr->size)
    {
        printf("Addition of element not possible because of size !\n");
    }
    else
    {
        arr->A[arr->length++] = x;
        printf("Element(%d) is appended !\n", x);
    }
}
void insert(struct array *arr, int index, int x)
{
    int i;
    if (arr->length < arr->size)
    {
        if (index != 0 && index <= arr->size)
        {
            for (i = arr->length; i > index; i--)
            {
                arr->A[i] = arr->A[i - 1];
            }
            arr->A[index] = x;
            arr->length++;
        }
    }
    printf("Element inserted !\n");
}
void Delete(struct array *arr, int index)
{
    int i;
    if (index != 0 && index < arr->size)
    {
        for (i = index; i < arr->length; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
}

//----------------------------------------LINEAR SEARCH----------------------------------------------------------------->

void linearsearch(struct array arr, int key) // normal linear search
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == key)
            printf("%d found at index  = %d\n", key, i);
    }
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void tls(struct array *arr, int key) // improved linear search using transposition
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            swap(&arr->A[i], &arr->A[i - 1]);
            printf("%d found at index  = %d\n", key, i - 1);
        }
    }
}
void mtf(struct array *arr, int key) // improved linear search using moving to front
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            swap(&arr->A[0], &arr->A[i]);
            printf("%d found at index  = %d\n", key, 0);
        }
    }
}
//----------------------------------------BINARY SEARCH----------------------------------------------------------------->
void sort(struct array *arr)
{
    int i, j;
    for (i = 0; i < arr->length; i++)
    {
        for (j = 0; j < arr->length - i - 1; j++)
        {
            if (arr->A[j] > arr->A[j + 1])
            {
                swap(&arr->A[j], &arr->A[j + 1]);
            }
        }
    }
}
int binarysearch(struct array arr, int key) // binary search using while loop/iteration method
{
    int mid, high, low;
    sort(&arr);
    low = 0;
    high = arr.length;
    while (low < +high)
    {
        mid = (low + high) / 2;
        if (arr.A[mid] == key)
        {
            return mid;
        }
        else if (arr.A[mid] > key)
        {
            high = mid - 1;
        }
        else if (arr.A[mid] < key)
        {
            low = mid + 1;
        }
    }
    return -1;
}
int rbs(struct array arr, int key, int low, int high) // binary search using recursion (tail recursion)
{
    sort(&arr);
    int mid = (high + low) / 2;
    if (low <= high)
    {
        if (arr.A[mid] == key)
            return mid;
        else if (arr.A[mid] > key)
            rbs(arr, key, low, mid - 1);
        else if (arr.A[mid] < key)
            rbs(arr, key, mid + 1, high);
    }
    return -1;
}
void get(struct array arr, int index)
{
    if (index >= 0 && index <= arr.length)
        printf("Element at index =%d is %d\n", index, arr.A[index]);
    else
        printf("Index out of range !");
}
void set(struct array *arr, int index, int key)
{
    if (index >= 0 && index < +arr->length)
    {
        arr->A[index] = key;
        printf("\nElement updated !\n");
    }
    else
        printf("\nIndex out of range ! ");
}
void maxarray(struct array arr) // maximum and minimum can also be printed by sorting the array and printing first / last element accordingly
{
    int max = arr.A[0], i;
    for (i = 0; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    printf("\nMaximum of the array = %d\n", max);
}
void minarray(struct array arr)
{
    int min = arr.A[0], i;
    for (i = 0; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    printf("\nminimum of the array = %d\n", min);
}
void sumofarray(struct array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
        sum += arr.A[i];
    printf("Sum of all elements of array = %d", sum);
}
void avgofarray(struct array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
        sum += arr.A[i];
    printf("Average of all elements of array = %d", sum / arr.length);
}
void reverse(struct array *arr) // method 1
{
    int temp[arr->length];
    int i, j;
    for (i = arr->length - 1, j = 0; i >= 0, j < arr->length; i--, j++)
    {
        temp[j] = arr->A[i];
    }
    for (i = 0; i < arr->length; i++)
    {
        arr->A[i] = temp[i];
    }
}
void reverseint(struct array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}
// Checking if an array is sorted and inserting in a sorted array
int issorted(struct array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i + 1] < arr.A[i])
            return 0;
    }
    return 1;
}
void insertinsort(struct array *arr, int key)
{
    sort(arr);
    int i = arr->length - 1;
    if (arr->length < arr->size)
    {
        while (i >= 0 && arr->A[i] > key)
        {
            arr->A[i + 1] = arr->A[i];
            i--;
        }
        arr->A[i + 1] = key;
    }
    arr->length++;
    printf("Element inserted !");
}
// Rearranging negative elements to one side and positive to another
void rearrange(struct array *arr)
{
    display(*arr);
    int i = 0;
    int j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] > 0)
            j--;
        if (i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
    display(*arr);
}
struct array *merge(struct array *arr1, struct array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    sort(arr1);
    sort(arr2);

    struct array *arr3 = (struct array *)malloc(sizeof(struct array));
    arr3->size = arr1->size + arr2->size;
    arr3->A = (int *)malloc(arr3->size * sizeof(int));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            // i++;
            // k++;
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
            // j++;
            // k++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
        // k++;
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
        // k++;
    }
    arr3->length = arr1->length + arr2->length;

    return arr3;
}
void unionusm(struct array arr1, struct array arr2) // union using merge
{
    struct array *arr3;
    arr3 = (struct array *)malloc(sizeof(struct array));
    arr3->size = arr1.size + arr2.size;
    arr3->A = (int *)malloc(sizeof(arr3->size * sizeof(int)));

    sort(&arr1);
    sort(&arr2);
    int i, j, k;
    i = j = k = 0;
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
        {
            arr3->A[k++] = arr1.A[i++];
        }
        else if (arr1.A[i] > arr2.A[j])
        {
            arr3->A[k++] = arr2.A[j++];
        }
        else if (arr1.A[i] == arr2.A[j])
        {
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }
    for (; i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];
    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];
    arr3->length = k;
    display(*arr3);
}
void intersectionusm(struct array arr1, struct array arr2)
{
    sort(&arr1);
    sort(&arr2);
    struct array *arr3 = (struct array *)malloc(sizeof(struct array));
    arr3->size = arr1.size + arr2.size;
    arr3->A = (int *)malloc(sizeof(arr3->size * sizeof(int)));
    int i, j, k;
    i = j = k = 0;
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] == arr2.A[j])
        {
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
        else if (arr1.A[i] < arr2.A[j])
            i++;
        else if (arr1.A[i] > arr2.A[j])
            j++;
    }
    arr3->length = k;
    display(*arr3);
}
void difference(struct array arr1, struct array arr2)
{
    struct array *arr3 = (struct array *)malloc(sizeof(struct array));
    arr3->size = arr1.size + arr2.size;
    arr3->A = (int *)malloc(arr3->size * (sizeof(int)));
    sort(&arr1);
    sort(&arr2);
    int i, j, k;
    i = j = k = 0;
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] == arr2.A[j])
        {
            i++;
            j++;
        }
        else if (arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++];
        else
            j++;
    }
    for (; i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];
    arr3->length = k;
    display(*arr3);
}
int main()
{
    struct array arr1, arr2;
    create(&arr1);
    create(&arr2);
    difference(arr1, arr2);
}
 */

// Finding missing element in a sorted array
