#include <algorithm>
#include <string>

using namespace std;

class StringBuilder 
{
private:
    string main;
    string scratch;

    const string::size_type ScratchSize = 1024;  // or some other arbitrary number

public:
    StringBuilder & append(const std::string & str) {
        scratch.append(str);
        if (scratch.size() > ScratchSize) {
            main.append(scratch);
            scratch.resize(0);
        }
        return *this;
    }

    const string & str() {
        if (scratch.size() > 0) {
            main.append(scratch);
            scratch.resize(0);
        }
        return main;
    }
};