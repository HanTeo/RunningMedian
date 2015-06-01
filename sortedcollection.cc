#include <algorithm>
#include <exception>
#include <sstream>
#include <set>
#include <iostream>

using namespace std;

template<typename T> class SortedCollection
{
public:
    SortedCollection(int k)
    {
        k_index = k;
    }
    
    string Insert(const T& input)
    {
        if(isOdd())
        {
            auto bottom = minSet.cbegin();
            int bottom_value;
            if(!minSet.empty() && input > *bottom)
            {
                bottom_value = *bottom;
                minSet.erase(bottom);
                minSet.insert(input);
            }
            else
            {
                bottom_value = input;
            }

            maxSet.insert(bottom_value);
        }
        else
        {
            auto top = maxSet.cbegin();
            int top_value;
            if(!maxSet.empty() && input < *top)
            {
                top_value = *top;
                maxSet.erase(top);
                maxSet.insert(input);
            }
            else
            {
                top_value = input;
            }

            minSet.insert(top_value);
        }
        
        if(k_index <= size())
        {    
            if(maxSet.size() >= k_index)
            {
                auto it = maxSet.rbegin();
                advance(it, k_index-1);
                k_value = *it;
            }
            else
            {
                auto it = minSet.begin();
                advance(it, k_index-maxSet.size()-1);
                k_value = *it;
            }
        }
        else
        {
            k_value = T();
        }

        stringstream ss;
        ss << "Input: " << input << "\tMedian: " << GetMedian() << "\tElem " << k_index << ": " << k_value << endl;
        //ss << to_string(minSet) << "(" << minSet.size() << ")\t" << to_string(maxSet) << "(" << maxSet.size() << ")" <<endl;
        return ss.str();
    }
    
    T GetMedian()
    {
        if(isOdd())
        {
            return *minSet.cbegin();
        }
        else
        {
            return (*minSet.cbegin() + *maxSet.cbegin())/2;
        }
    }

private:
    bool isOdd()
    {
        return (size() & 1) == 1;
    }

    int size()
    {
        return minSet.size() + maxSet.size();
    }

    multiset<T> minSet;
    multiset<T, greater<T>> maxSet;
    int k_index;
    T k_value;
    typename multiset<T>::iterator it_kth = minSet.end();
};