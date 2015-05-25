#include <algorithm>
#include <exception>
#include <sstream>

using namespace std;

template<typename T> class SortedCollection
{
public:
    SortedCollection(int k)
    {
        k_index = k;
    }
    
    string Insert(T input)
    {
        m.insert(input);

        int sIndex = m.size()/2;
        auto it = m.begin();
        
        if(isOdd()){
            advance(it, sIndex);
            median = *it;
        }else{
            advance(it, sIndex-1);
            median = (*it + *++it)/2;
        }
        
        if(m.size() >= k_index){
            it = m.begin();
            advance(it, k_index-1);
            k_value = *it;
        }
        else
        {
            k_value = T();
        }
        
        stringstream ss;
        ss << "Input: " << input << "\tMedian: " << median << "\tElem " << k_index << ": " << k_value;
        return ss.str();
    }
    
    const multiset<T>& GetCollection()
    {
        return m;
    }
    
private:
    bool isOdd()
    {
        return (m.size() & 1) == 1;
    }
    
    multiset<T> m;
    int k_index;
    T median;
    T k_value;
};