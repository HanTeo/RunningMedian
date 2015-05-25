#include <algorithm>
#include <exception>
#include <sstream>
#include <vector>

using namespace std;

template<typename T> class MinMaxHeap
{
public:
    MinMaxHeap(int k)
    {
        k_index = k;
    }

    string Insert(T n)
    {
        insertSmallest(n);
        
        stringstream ss;
        ss << "Input: " << n;
        
        int temp;
        
        if(isOdd())
        {
            if(minHeap.size() > 0 && minHeap[0] < n)
            {
                minHeap.push_back(n);
                push_heap(minHeap.begin(), minHeap.end(), greater<T>());

                n = minHeap[0];

                pop_heap(minHeap.begin(), minHeap.end(), greater<T>());
                minHeap.pop_back();
            }

            maxHeap.push_back(n);
            push_heap(maxHeap.begin(), maxHeap.end(), less<T>());
        }
        else
        {
            if(maxHeap.size() > 0 && n < maxHeap[0])
            {
                maxHeap.push_back(n);
                push_heap(maxHeap.begin(), maxHeap.end(), less<T>());

                n = maxHeap[0];

                pop_heap(maxHeap.begin(), maxHeap.end(), less<T>());
                maxHeap.pop_back();
            }

            minHeap.push_back(n);
            push_heap(minHeap.begin(), minHeap.end(), greater<T>());
        }
        
        ss << "\tSize: " << size() << "\tMedian: " << GetMedian() << "\tElem " << k_index << ": " << GetKthElement();
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
    void insertSmallest(T n)
    {
        if(smallestKth.size() >= k_index)
        {
            if(n >= smallestKth[0])
                return;
            
            if(n < smallestKth[0])
            {
                pop_heap(smallestKth.begin(), smallestKth.end(), less<T>());
                smallestKth.pop_back();
            }
        }
        
        smallestKth.push_back(n);
        push_heap(smallestKth.begin(), smallestKth.end(), less<T>());
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