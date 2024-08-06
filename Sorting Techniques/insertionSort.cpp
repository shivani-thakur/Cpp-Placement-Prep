// Following is the solution for: https://www.geeksforgeeks.org/problems/insertion-sort/0

class Solution
{
    public:
    void insert(int arr[], int i)
    {
        //code here
        while(i>0 && arr[i] < arr[i-1] ) {
            int temp = arr[i-1];
            arr[i-1] = arr[i];
            arr[i] = temp;
            i--;
        }
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        //code here
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i-1]) {
                insert(arr, i);
            }
        }
    }
};