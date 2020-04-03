#include "Sorts.h"

template <class T>
Sorts<T>::Sorts()
{
    //ctor
}

template <class T>
Sorts<T>::~Sorts()
{
    //dtor
}

template <class T>
void Sorts<T>::quickSort(T arr[], int arrSize)
{
    quickSort(arr, 0, arrSize-1);
}

template <class T>
void Sorts<T>::quickSort(T arr[], int first, int last)
{
    if (first < last)
    {
        T pivot = partitioning(arr, first, last);
        quickSort(arr, first, pivot -1);
        quickSort(arr, pivot + 1, last);
    }
}


template <class T>
T Sorts<T>::partitioning(T arr[], int first, int last)
{
    //Przyjmujemy pierwwszy element jako os
    //wzgledem niego bedziemy dzielic tablice na mniejsze i wieksze elementy
    T pivot = arr[first];
    //Bedziemy iterowac po tablicy od dwoch stron
    int i = first;
    int j = last;
    while (true)
    {
        //Przesuwamy sie az znajdziemy element o indeksie j wiekszy od osi
        // oraz i mniejszym od osi
        while (arr[j] > pivot)
            --j;
        while (arr[i] < pivot)
            ++i;

        //jesli i jest wieksze od j to zwracamy j
        if (i >= j)
            return j;

        //jesli nie to zamieniamy je miejscami i przesuwamy sie dalej
        swapValues(arr,i,j);
        ++i;
        --j;
    }
}


template <class T>
void Sorts<T>::mergeSort(T arr[], int arrSize)
{
    mergeSort(arr, 0, arrSize-1);
}


template <class T>
void Sorts<T>::mergeSort(T arr[], int first, int last)
{
    if (first < last)
    {
        T middle = ( first + last )/2;

        mergeSort(arr, first, middle);
        mergeSort(arr, middle+1, last);
        merging(arr, first, middle, last);
    }
}



template <class T>
void Sorts<T>::merging(T arr[], int first, int middle, int last)
{
    int i, j, k;
    int leftSize = middle - first + 1;
    int rightSize = last - middle;

    // Tworzymy tymczasowe tablice
    T leftArr[leftSize], rightArr[rightSize];

    // Wypelniamy tablice
    for (i = 0; i < leftSize; ++i)
        leftArr[i] = arr[first + i];
    for (j = 0; j < rightSize; ++j)
        rightArr[j] = arr[middle + 1+ j];

    //wlasciwe scalanie
    i = 0; //indeks lewej tablicy
    j = 0; //indeks prawej tablicy
    k = first; //indeks prawdziwej tablicy, do ktorej kopiujemy elementy
    //wykonujemy kopiowanie az ktoras z tablic pomocniczych sie skonczy
    while (i < leftSize && j < rightSize)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            ++i;
        }
        else
        {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // Kopiujemy pozostalosci tablic
    while (i < leftSize)
    {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }
    while (j < rightSize)
    {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}




template <class T>
void Sorts<T>::insertionSort(T arr[], int arrSize)
{
    int i,j;
    int temp;
    for (i=1; i<arrSize; ++i)
    {
        temp=arr[i];
        for(j=i; j > 0 && temp < arr[j-1]; --j)
        {
            arr[j]=arr[j-1];
        }
        arr[j]=temp;
    }
}


template <class T>
void Sorts<T>::heapSort(T arr[], int arrSize)
{
    int i;
    //Najpierw tworzymy kopiec
    for(i=arrSize/2; i>0; --i)
        heapify(arr-1, i, arrSize);
    for(i=arrSize-1; i>0; --i)
    {
        //przestawiawmy korzen z 0 na ostatnia pozycje
        swapValues(arr,0,i);
        //znajdujemy nowy korzen na zmniejszonej tablicy
        heapify(arr-1, 1, i);
    }
}


template <class T>
void Sorts<T>::heapify(T arr[], int rootIndex, int heapSize)
{
    int i,j;
    i = rootIndex;
    while(i<=heapSize/2)
    {
        j=2*i;
        if(j+1<=heapSize && arr[j+1]>arr[j])
            j=j+1;
        if(arr[i]<arr[j])
        {
            swapValues(arr,i,j);
        }
        else
        {
            break;
        }


        i=j;
    }
}


template <class T>
void Sorts<T>::swapValues(T arr[], int i, int j)
{
    int temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}


template <class T>
void Sorts<T>::introspectiveSort(T arr[], int arrSize)
{
    introSort(arr,arrSize,(int)floor(2*log(arrSize)/log(2)));
    insertionSort(arr,arrSize);
}


template <class T>
void Sorts<T>::introSort(T arr[], int arrSize, int depth)
{
    int i;
    if (depth<=0)
    {
        heapSort(arr,arrSize);
        return;
    }
    i=partitioning(arr,0,arrSize-1);
    if (i>9)
        introSort(arr,i,depth-1);
    if (arrSize-1-i>9)
        introSort(arr+i+1,arrSize-1-i,depth-1);
}

template class Sorts<int>;
template class Sorts<double>;
template class Sorts<short>;
