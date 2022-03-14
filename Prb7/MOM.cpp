#include<bits/stdc++.h>
using namespace std;

void insertion_sort(short arr[], int initial, int final)
{
    for (int i = initial; i <= final; i++)
    {
        int value = arr[i];
        int pos = i - 1;
        while (pos >= initial && arr[pos] > value)
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = value;
    }
}

int findMedian(short arr[], int initial, int final)
{
    insertion_sort(arr, initial, final);
    int mid = (initial + final) / 2;
    return arr[mid];
}

int median_of_median(short arr[], int arr_size, int divide_size)
{
    if (arr_size < divide_size)
    {
        int median = findMedian(arr, 0, arr_size - 1);
        return median;
    }

    int no_full_group = arr_size / divide_size;
    int elements_in_last = arr_size % divide_size;

    int next_arr_size;

    if (elements_in_last == 0)
        next_arr_size = no_full_group;
    else
        next_arr_size = no_full_group + 1;

    short next_arr[next_arr_size];

    for (int i = 0; i < next_arr_size; i++)
    {
        if (i == next_arr_size -1)
            next_arr[i] = findMedian(arr, divide_size * i, arr_size - 1);
        else
            next_arr[i] = findMedian(arr, divide_size * i, divide_size * (i + 1) - 1);
    }

    return median_of_median(next_arr, next_arr_size,divide_size);
}

int main()
{
    srand(time(0));

    int arr_size = 10;

    short arr[arr_size];

    for (int i = 0; i < arr_size; i++)
        arr[i] = rand() % 100;

    for (int i = 0; i < arr_size; i++)
        cout<<arr[i];
    cout<<endl;

    short copy[arr_size];

    for (int i = 0; i < arr_size; i++)
        copy[i] = arr[i];

    
    cout<<"MoM = " << median_of_median(arr, arr_size,5) << endl;
    
    cout<<"Direct = " << findMedian(copy, 0, arr_size - 1) << endl;

    return 0;
}