#include <bits/stdc++.h>
using namespace std;
const int TOTAL_ELEMENTS = 100;
const int MAXIMUM = 100;

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}


void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}


int partition(int array[], int low, int high) {

    int pivot = array[high];    
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
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


int main() {

  
    srand(time(0));
    
    ofstream outfile;
    outfile.open("datasets.txt");
    for(int i = 0; i < TOTAL_ELEMENTS; i++){
        outfile << rand()%MAXIMUM << "\n";
    }
    outfile.close();
    int *array = new int[TOTAL_ELEMENTS];
    ifstream infile;
    infile.open("datasets.txt");
    int data;
    for(int i = 0; i < TOTAL_ELEMENTS; i++){
        infile>>data;
        
        array[i] = data;
    }
    infile.close();
    printArray(array,TOTAL_ELEMENTS);
    cout << "SORTED ARRAY " <<endl;
    quickSort(array, 0, TOTAL_ELEMENTS-1);
    printArray(array,TOTAL_ELEMENTS);
    int correct = checkforCorrectness(array, TOTAL_ELEMENTS);
    if (correct == 1)
    cout << "The array has been correctly sorted" <<endl;
    else
    cout << "There has been some error in sorting!! " << endl;
    return 0;
}