#include <iostream>
#include <string>
#include <set>
#include "heap.cc"
#include "sortedcollection.cc"
#include "introselect.cc"
#include "utils.cc"

using namespace std;

int main()
{
    int kth = 10;

    MinMaxHeap<int> heap(kth);
    SortedCollection<int> sorted(kth);
    IntroSelect<int> intro(kth);
    
    string line;
    while (getline(cin, line)) 
    {
        int n = stoi(line);

        //cout << "[Sorts]\t" << sorted.Insert(n) << endl; 
        cout << "[Heaps]\t" << heap.Insert(n) << endl;
        //cout << "[Intro]\t" << intro.Insert(n) << endl;
    }
}