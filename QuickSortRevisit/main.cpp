#include <iostream>
#include <vector>
#include <iterator>

template <typename T>
int Partition(std::vector<T> &array, int low, int high)
{
    T pivot = array[high];
    int index = low-1;
    
    for(int j=low; j<high; j++)
    {
        if(array[j] <= pivot) // changed here
        {
            index++;
            std::swap(array[j], array[index]);
        }
    }
    std::swap(array[high], array[index+1]); // changed here
    return(index+1);
}

template <typename T>
void QuickSort(std::vector<T> &array, int low, int high)
{
    if(low < high)
    {
        int pivot = Partition(array, low, high);
        QuickSort(array, low, pivot-1);
        QuickSort(array, pivot+1, high);
    }
}

template <typename T>
void Print(std::vector<T> &array)
{
    for(typename std::vector<T>::iterator itr = array.begin(); itr != array.end(); itr++)
    {
        std::cout << *itr << "  ";
    }
    puts("");
}

int main()
{
    std::vector<int> array = {0, -33, -44, 55, 11, -22, -33, 0, 0, 5, 7, 19, -13, -11, -99, 100};
    
    std::cout << "Unsorted array is: \n";
    Print(array);
    puts("");
    
    std::cout << "Sorted array is: \n";
    QuickSort(array, 0, array.size()-1);
    Print(array);
    puts("");
    
    return 0;
}
