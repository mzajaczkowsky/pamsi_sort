
#ifndef SORTS_H
#define SORTS_H
#include <iostream>
#include <math.h>

using namespace std;


template <class T>
class Sorts
{
public:
    Sorts();
    virtual ~Sorts();

    //funkcja do wywolania sortowania przez scalanie
    void mergeSort(T arr[], int arrSize);

    //funkcja do wywolania sortowania szybkiego
    void quickSort(T arr[], int arrSize);

    //funkcja do wywolania sortowania introspektywnego
    void introspectiveSort(T arr[], int arrSize);

private:

    //funkcja wywolujaca sortowanie przez wstawianie
    void insertionSort(T arr[], int arrSize);

    //funkcja wywolujaca sortowanie przez kopcowanie
    void heapSort(T arr[], int arrSize);

    //prywatna funkcja wykorzystujaca rekurencje do sortowania przez scalanie
    void mergeSort(T arr[], int first, int last);

    //funkcja scalajaca juz posorowane tablice
    void merging(T arr[], int first, int middle, int last);

    //prywatna funkcja rekurencyjna do sortowania szybkiego
    void quickSort(T arr[], int first, int last);

    //unkcja dzieli tablice na mniejsze i wieksze liczby wzgledem pierwszego elementu (Potrzebne do quick-sorta)
    T partitioning(T arr[], int first, int last);

    //funkcja sluzy do tworzenia kopca
    void heapify(T arr[], int rootIndex, int heapSize);

    //funkcja zamienia miejscami wartosci tablicy o podanych indeksach
    void swapValues(T arr[], int i, int j);

    //funkcja decyduje jakiego sortowanie uzyc w sortowaniu hybrydowym
    void introSort(T arr[], int arrSize, int depth);

};

#endif // SORTS_H
