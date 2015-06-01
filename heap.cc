#include <algorithm>
#include <exception>
#include <sstream>
#include <vector>
#include "utils.cc"

using namespace std;

template<typename T> class MinMaxHeap
{
public:
    MinMaxHeap(int k)
    {
        k_index = k;
    }

    string Insert(const T& n)
    {
        auto number = n;
        
        insertSmallestKth(number);
        
        if(isOdd())
        {
            rebalanceHeap(number, minHeap, greater<T>());
            addToHeap(number, maxHeap, less<T>());
        }
        else
        {
            rebalanceHeap(number, maxHeap, less<T>());
            addToHeap(number, minHeap, greater<T>());
        }
        
        stringstream ss;
        ss << "Input: " << n << "\tMedian: " << GetMedian() << "\tElem " << k_index << ": " << GetKthElement() << endl;
        //ss << to_string(minHeap) << "(" << minHeap.size() << ")\t" << to_string(maxHeap) << "(" << maxHeap.size() << ")" << endl;

        return ss.str();
    }
    
    T GetMedian()
    {
        if(size() == 0)
            throw exception();
    
        if(isOdd())
        {
            return minHeap[0];
        }
        else
        {
            return (minHeap[0] + maxHeap[0]) / 2;
        }
    }
    
    T GetKthElement()
    {
        if(size() == 0)
            throw exception();
            
        if(smallestKth.size() < k_index)
            return 0;
        
        return smallestKth[0];
    }
    
    const vector<T>& GetMinHeap()
    {
        return minHeap;
    }
    
    const vector<T>& GetMaxHeap()
    {
        return maxHeap;
    }
    
    const vector<T>& GetSmallestCollection()
    {
        return smallestKth;
    }
    
    int size()
    {
        return minHeap.size() + maxHeap.size();
    }

private:
    void insertSmallestKth(const T& n)
    {
        if(smallestKth.size() >= k_index)
        {
            if(n >= smallestKth[0])
                return;
            
            if(n < smallestKth[0])
            {
                removeFromHeapTop(smallestKth, less<T>());
            }
        }
        
        addToHeap(n, smallestKth, less<T>());
    }

    template <typename F>
    void rebalanceHeap(int& n, vector<T>& heap, F f)
    {
        if(!heap.empty() && f(n, heap[0]))
        {
            addToHeap(n, heap, f);

            n = heap[0];

            removeFromHeapTop(heap, f);
        }
    }

    template <typename F>
    void addToHeap(const int& n, vector<T>& heap, F f)
    {
        heap.push_back(n);
        push_heap(heap.begin(), heap.end(), f);
    }

    template <typename F>
    void removeFromHeapTop(vector<T>& heap, F f)
    {
        pop_heap(heap.begin(), heap.end(), f);
        heap.pop_back();
    }

    bool isOdd()
    {
        return (size() & 1) == 1;
    }

    vector<T> minHeap;
    vector<T> maxHeap;
    vector<T> smallestKth;
    int k_index;
};