#include "Table.h"

template <class T>
Table<T>::Table()
{
    //ctor
}

template <class T>
Table<T>::~Table()
{
    //dtor
}


template <class T>
T * Table<T>::createArray(T arr[], int sizeOfArray, double percentOfSort)
{
    srand(time(0));
    for (int i=0; i < sizeOfArray; ++i)
    {
        arr[i] = i + 0.5;
    }

    if(percentOfSort == -1 )
    {
        //Odwrocona tablica
        reverse(arr, arr + sizeOfArray);
        cout << "Tablica posortowana w odwrotnej  kolejnosci " << endl;
        cout << " " << endl;
    }
    else
    {
        int whereToStartShuffle = (percentOfSort * sizeOfArray) / 100;
        random_shuffle(&arr[whereToStartShuffle], &arr[sizeOfArray]);
        cout << " " << endl;
        cout << " " << endl;
        cout << percentOfSort << "% poczatkowych elementow posortowanych" << endl;
        cout << "Ilosc elementow tablicy: " << sizeOfArray << endl;
        cout << " " << endl;
    }
    return arr;
}


template <class T>
void Table<T>::printArray(T arr[], int sizeOfArray)
{
    for (int i=0; i<sizeOfArray; ++i)
    {
        cout << arr[i] << endl;
    }
}

template <class T>
void Table<T>::checkIfSortedGood(T arr[], int sizeOfArray)
{
    for (int i=1; i<sizeOfArray; ++i)
    {
        if (arr[i] < arr[i-1])
            cout << "blednie posortowane" << endl;
    }
}


template <class T>
void Table<T>::testSort()
{
    int sizeOfArray[] = {10000, 50000, 100000, 500000, 1000000}; //wybieramy z ilu elementow maja sie skladac tablice do posortowania
    double percentOfSort[] = {25}; //procent posortowanych elementow w tablicy dla odwroconej wybieramy [ -1 ]

    for (int i = 0; i < 5; ++i)
    {
        for (auto j : percentOfSort)
        {
            //Tworzymy 3 tablice dla 3 sortowan
            T * mergeArray = new T[sizeOfArray[i]];
            T * quickArray = new T[sizeOfArray[i]];
            T * introArray = new T[sizeOfArray[i]];

            //Wypelniamy jedna i kopiujemy zawartosc do pozostalych
            createArray(mergeArray, sizeOfArray[i], j);
            copy(mergeArray, mergeArray + sizeOfArray[i], quickArray);
            copy(mergeArray, mergeArray + sizeOfArray[i], introArray);

            //Wykonujemy testy
            makeTestOnArray(mergeArray, sizeOfArray[i], 1);
            //checkIfSortedGood(mergeArray, sizeOfArray[i]);
            //makeTestOnArray(quickArray, sizeOfArray[i], 2);
            makeTestOnArray(introArray, sizeOfArray[i], 3);
        }
    }
}


template <class T>
void Table<T>::makeTestOnArray(T arr[], int sizeOfArray, int whichSort)
{
    Sorts <T> sorts;

    //Zaczynamy pomiar czasu
    auto start = chrono::high_resolution_clock::now();

    //Wybieramy algorytm sortowania
    if (whichSort == 1)
    {
        sorts.mergeSort(arr, sizeOfArray);
        cout << "SORTOWANIE PRZEZ SCALANIE" << endl;
    }
    else if (whichSort == 2)
    {
        sorts.quickSort(arr, sizeOfArray);
        cout << "SORTOWANIE SZYBKIE" << endl;
    }
    else if (whichSort == 3)
    {
        sorts.introspectiveSort(arr, sizeOfArray);
        cout << "SORTOWANIE INTROSPEKTYWNE" << endl;
    }

    //Konczymy pomiar czasu
    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = stop - start;


    cout << "Czas sortowania: " << elapsed.count() << " s\n";
    cout << " " << endl;
}

template class Table<int>;
template class Table<double>;
template class Table<short>;

