#include <iostream>
#include <vector>
#include <algorithm>



void insertionSort(std::vector<int>& bucket) 
{
    int n = bucket.size();
    for (int i = 1; i < n; ++i) 
    {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) 
        {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}


void bucketSort(std::vector<int>& arr) 
{
    int n = arr.size();
    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;
    std::vector<vector<int>> buckets(range);
    for (int i = 0; i < n; ++i) 
    {
        int index = arr[i] - min_val;
        buckets[index].push_back(arr[i]);
    }


    for (int i = 0; i < range; ++i) 
    {
        if (!buckets[i].empty()) 
        {
            insertionSort(buckets[i]);
        }
    }


    int index = 0;
    for (int i = 0; i < range; ++i) 
    {
        for (int j = 0; j < buckets[i].size(); ++j) 
        {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() 
{
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    bucketSort(arr);
    std::cout << "Sorted array: ";
    for (int num : arr) 
    {
        std::cout << num << " ";
    }
    std::cout << endl;

    return 0;
}
