#include <vector>
#include <set>
#include "stringbuilder.cc"

using namespace std;

template<class T>
string to_string(const vector<T>& v)
{
    StringBuilder sb;

    for (typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
    {
        sb.append(to_string(*it));
        sb.append(" ");
    }
    
    return sb.str();
}

template<class T>
string to_string(const multiset<T>& s)
{
    StringBuilder sb;

    for (typename multiset<T>::const_iterator it=s.begin(); it!=s.end(); ++it)
    {
        sb.append(to_string(*it));
        sb.append(" ");
    }
    
    return sb.str();
}

template<class T>
string to_string(const multiset<T, greater<T>>& s)
{
    StringBuilder sb;

    for (typename multiset<T>::const_iterator it=s.begin(); it!=s.end(); ++it)
    {
        sb.append(to_string(*it));
        sb.append(" ");
    }

    return sb.str();
}