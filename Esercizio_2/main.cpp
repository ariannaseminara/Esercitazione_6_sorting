#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>
#include <numeric>
#include <algorithm>
#include "SortingAlgorithm.hpp"
#include <sstream>

using namespace std;
using namespace SortLibrary;

int main(int argc, char ** argv)
{
    istringstream ist(argv[1]);
        unsigned int n;
    ist >> n;

    // Dichiarazione di variabili per la media dei tempi di esecuzione
    double bubble_sort_total_time = 0;
    double merge_sort_total_time = 0;
    const int NUM_RUNS = 10; // Numero di esecuzione

    for(unsigned int i = 1; i <= NUM_RUNS; i++)
    {
        vector<int> v(n);

        // Genera numeri casuali nel vettore
        srand(time(nullptr));
        for (unsigned int i = 0; i < n; i++) {
            v[i] = rand() % 3000; // Numeri casuali da 0 a 299
        }

        // Stampa il vettore prima della sua ordinazione
        cout << "\nBefore sorting:" << endl;
        for(unsigned int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;

        // Esegue BubbleSort sul vettore
        std::chrono::steady_clock::time_point bubble_sort_begin = std::chrono::steady_clock::now();
        sleep(1);
        BubbleSort(v);
        std::chrono::steady_clock::time_point bubble_sort_end = std::chrono::steady_clock::now();

        // Stampa il vettore dopo BubbleSort
        cout << "\nAfter BubbleSort:" << endl;
        for(unsigned int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;

        // Calcola il tempo trascorso per BubbleSort
        double bubble_sort_duration = std::chrono::duration_cast<std::chrono::milliseconds>(bubble_sort_end - bubble_sort_begin).count();
        cout << "BubbleSort duration: " << bubble_sort_duration << " milliseconds" << endl;
        bubble_sort_total_time += bubble_sort_duration;

        // Esegue MergeSort sul vettore
        std::chrono::steady_clock::time_point merge_sort_begin = std::chrono::steady_clock::now();
        sleep(1);
        MergeSort(v);
        std::chrono::steady_clock::time_point merge_sort_end = std::chrono::steady_clock::now();

        // Stampa il vettore dopo MergeSort
        cout << "\nAfter MergeSort:" << endl;
        for(unsigned int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;

        // Calcola il tempo trascorso per MergeSort
        double merge_sort_duration = std::chrono::duration_cast<std::chrono::milliseconds>(merge_sort_end - merge_sort_begin).count();
        cout << "MergeSort duration: " << merge_sort_duration << " milliseconds" << endl;
        merge_sort_total_time += merge_sort_duration;

        n++;
    }

    // Calcola la media dei tempi di esecuzione
    double bubble_sort_avg_time = bubble_sort_total_time / NUM_RUNS;
    double merge_sort_avg_time = merge_sort_total_time / NUM_RUNS;

    // Stampa la media dei tempi di esecuzione
    cout << "\nAverage BubbleSort duration: " << bubble_sort_avg_time << " milliseconds" << endl;
    cout << "Average MergeSort duration: " << merge_sort_avg_time << " milliseconds" << endl;

    return 0;
}

