// Time complexity O(n^2)

#include <iostream>
#include <vector>

void SelectionSort(std::vector<int>&);

int main()
{
    std::cout << "Enter size for array: " << std::endl;
    int size = 0;
    std::cin >> size;
    std::vector<int> arr(size); 
    std::cout << "Enter elements " << std::endl;
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    std::cout << "Sort array: " << std::endl;
    SelectionSort(arr);
    for(int i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}

void SelectionSort(std::vector<int>& arr)
{
    for(int i = 0; i < arr.size(); ++i)
    {
        int minIndex = i;
        for(int j = i + 1; j < arr.size() ; ++j)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {
            int tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp; 
        }
    }
}