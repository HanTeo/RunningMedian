class StringBuilder 
{
private:
    std::string main;
    std::string scratch;

    const std::string::size_type ScratchSize = 1024;  // or some other arbitrary number

public:
    StringBuilder & append(const std::string & str) {
        scratch.append(str);
        if (scratch.size() > ScratchSize) {
            main.append(scratch);
            scratch.resize(0);
        }
        return *this;
    }

    const std::string & str() {
        if (scratch.size() > 0) {
            main.append(scratch);
            scratch.resize(0);
        }
        return main;
    }
};

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