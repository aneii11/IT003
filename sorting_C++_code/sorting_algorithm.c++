#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

bool sorted(double arr[]){
    for(int i=1;i<1000000;i++)
        if( arr[i] > arr[i+1] )
            return 0;
    return 1;
}
//Quick sort
double randomPivot(double arr[], int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(arr[random], arr[high]);
    return arr[high];
}

int partition(double arr[], int low, int high) {
    double pivot = randomPivot(arr, low, high);
    int i = low - 1;
    int j = high + 1;
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}

void quickSort(double arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

//Heap sort
void heapify(double arr[], int N, int i){
    int largest = i;
    int left_child = 2*i+1;
    int right_child = 2*i+2;
    if( left_child < N && arr[left_child] > arr[largest] )
        largest = left_child;
    if( right_child < N && arr[right_child] > arr[largest])
        largest = right_child;
    if( largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapsort(double arr[], int N){
    for(int i = N/2 - 1; i >= 0;i--)
        heapify(arr,N,i);
    for(int i = N-1;i >=0;i--){
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }
}

//merge sort
void merge(double arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    double *L = new double[n1], *R = new double[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete []L;
    delete []R;
}

void mergesort(double arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
double test[1000000];

void load_data(string filename){
    ifstream inp;
    inp.open(filename);
    for(int i=0;i<1000000;i++)
        inp >> test[i];
}

int main(){
    for(int i = 0; i < 4; i++){
        if(i == 0)
            cout << "STL Sort:\n";
        if(i == 1)
            cout << "Quick Sort:\n";
        if(i == 2)
            cout << "Heap Sort:\n";
        if(i == 3)
            cout << "Merge Sort:\n";
        for(int j = 1; j <= 10; j++){
            string f_name = "test " + to_string(j);
            load_data(f_name);
            if(i == 0){
                auto start = high_resolution_clock::now();
                sort(test, test+1000000);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(stop - start);
                cout<< "Test "<< j << ": " << duration.count() << "ms\t Sorted: "<< sorted(test) << "\n";
            }
            if(i == 1){
                auto start = high_resolution_clock::now();
                quickSort(test,0,1000000-1);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(stop - start);
                cout<< "Test "<< j << ": " << duration.count() << "ms\t Sorted: "<<sorted(test)<< "\n";
            }
            if(i == 2){
                auto start = high_resolution_clock::now();
                heapsort(test,1000000);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(stop - start);
                cout<< "Test "<< j << ": " << duration.count() << "ms\t Sorted: "<< sorted(test) << '\n';
            }
            if(i == 3){
                auto start = high_resolution_clock::now();
                mergesort(test,0,1000000-1);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(stop - start);
                cout<< "Test "<< j << ": " << duration.count() << "ms\t Sorted: "<<sorted(test)<< '\n';
            }

        }
        cout << "\n";
    }
}
