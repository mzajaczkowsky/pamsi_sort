
#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <chrono>
#include "Sorts.h"

using namespace std;

template <class T>
class Table
{
public:

    Table();
    virtual ~Table();

    //publiczna funkcja do przeprowadzania testów algorytmów
    void testSort();

private:

    // funkcja sprawdzajaca czy tablica jest dobrze posortowana
    void checkIfSortedGood(T arr[], int sizeOfArray);

    //funkcja wypisujaca elementy tablicy
    void printArray(T arr[], int sizeOfArray);

    //funckja wypelniajaca tablice elementami
    T * createArray(T arr[], int sizeOfArray, double percentOfSort);

    //funkcja wykonujaca pojedynczy test
    void makeTestOnArray(T arr[], int sizeOfArray, int whichSort);
};

#endif // TABLE_H
