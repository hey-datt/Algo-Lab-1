#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *temp1 = new int[n1];
    int *temp2 = new int[n2];

    for(int i = 0; i < n1; i++){
        temp1[i] = arr[left + i];
    }

    for(int i = 0; i < n2; i++){
        temp2[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while( i < n1 && j < n2){
        if(temp1[i] <= temp2[j]){
            arr[k] = temp1[i];
            i++;
        }
        else{
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = temp1[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = temp2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int initial, int final){
    int mid;
    if(initial < final){
        mid = initial + (final - initial)/2;
        mergeSort(arr, initial, mid);
        mergeSort(arr, mid + 1, final);
        merge(arr, initial, mid, final);
    }
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int checkforCorrectness(int arr[], int n){
    int correct = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            correct = 0;
            break;
        }
    }
    return correct;
}


int main(){

    int size,choice;
    cout<<"Enter the Size of Array "<<endl;
    cin>>size;
    ifstream infile;
    int *arr = new int[size];

    cout<<"Enter 1 for selecting numbers Randomly "<<"\n"<< "Enter 2 for selecting numbers from Uniform Distribution " << "\n"<<"Enter 3 for selecting numbers from Normal Distribution "<<endl;
    cin>>choice;

    if(choice == 1){

        int max;
        cout<<"Enter the max limit of the number "<<endl;
        cin>>max;
        for(int i = 0; i < size; i++){
            arr[i] = rand() % max;
        }
    }

    else if(choice == 2){
        infile.open("D:/B.TECH/2nd YEAR(2021-22)/4th Sem/Algorithm Lab/Assignment 1/Prb1A/uniform_dist.csv");
        for(int i = 0; i < size; i++){
            infile >> arr[i];
        }
        infile.close();
    }
    else if(choice == 3){
        infile.open("D:/B.TECH/2nd YEAR(2021-22)/4th Sem/Algorithm Lab/Assignment 1/Prb1B/normal_dist.txt");
        for(int i = 0; i < size; i++){
            infile >> arr[i];
        }
        infile.close();
    }
    else
    cout<<"Enter a valid Choice "<<endl;

    cout<<"The unsorted Arrays are "<<endl;
    printArray(arr,size);

    mergeSort(arr,0,size-1);
    cout<<"After Sorting "<<endl;
    printArray(arr,size);
    int correct = checkforCorrectness(arr, size);
    if (correct == 1)
    cout << "The array has been correctly sorted" <<endl;
    else
    cout << "There has been some error in sorting!! " << endl;
}