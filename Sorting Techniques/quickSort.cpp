// Following is the solution for: https://www.geeksforgeeks.org/problems/quick-sort/1

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if (low < high) {
            int prt_ind = partition(arr, low, high);
            quickSort(arr, low, prt_ind - 1);
            quickSort(arr, prt_ind + 1, high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int i = low, j = high, pivot = arr[low];
       while (i < j) {
           while (i <= high && arr[i] <= pivot) {
               i++;
           }
           while (j >= low && arr[j] > pivot) {
               j--;
           }
           if (i < j) swap(arr[i], arr[j]);
       }
       swap(arr[low], arr[j]);
       return j;
    }
};