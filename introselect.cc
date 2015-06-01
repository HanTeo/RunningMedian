#include <algorithm>
#include <exception>
#include <sstream>
#include <vector>

using namespace std;

template<typename T> class IntroSelect
{
public:
    IntroSelect(int kth)
    {
        k = kth;
    }
    
    string Insert(T input)
    {
        v.push_back(input);
        int mIndex = v.size()/2;
        
        if(v.size() >= k)
        {
            nth_element(v.begin(), v.begin() + k-1, v.end());
            kth = v[k-1];
        }
        else
        {
            kth = T();
        }
        
        if(isOdd())
        {
            nth_element(v.begin(), v.begin() + mIndex, v.end());
            median = v[mIndex];
        }
        else
        {
            nth_element(v.begin(), v.begin() + mIndex, v.end());
            median = v[mIndex];
            nth_element(v.begin(), v.begin() + mIndex-1, v.end());
            median += v[mIndex-1];
            median /= 2;
        }
        
        stringstream ss;    
        ss << "Input: " << input << "\tMedian: " << median << "\tElem " << k << ": " << kth << endl;
        return ss.str();
    }
    
    const vector<T>& GetCollection()
    {
        return v;
    }
    
private:
    bool isOdd()
    {
        return (v.size() & 1) == 1;
    }
    
    vector<T> v;
    int k;
    T median;
    T kth;
};