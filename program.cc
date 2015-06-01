#include <iostream>
#include <set>
#include "heap.cc"
#include "sortedcollection.cc"
#include "introselect.cc"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int kth = 10;

    MinMaxHeap<int> heap(kth);
    SortedCollection<int> sorted(kth);
    IntroSelect<int> intro(kth);

    auto t_start = chrono::high_resolution_clock::now();

    srand((unsigned)time(0));
    int random_integer;
    for(int index=0; index<=100; index++)
    {
        random_integer = (rand()%10)+1;

        cout << "[Sorts]\t" << sorted.Insert(random_integer);
        cout << "[Heaps]\t" << heap.Insert(random_integer);
        cout << "[Intro]\t" << intro.Insert(random_integer);
    }

    auto t_end = chrono::high_resolution_clock::now();
    cout << "Total CPU Time: " <<chrono::duration<double, std::milli>(t_end-t_start).count() << "ms" << endl;

    return 0;
}