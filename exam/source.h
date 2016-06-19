#ifndef Source_H
#define Source_H
#include <vector>
#include <string>

using namespace std;

class Source
{
    string name, status, creator, reviewer;
public:
    Source(const string& name, const string& status, const string& creator,  const string& reviewer);

    string getName() const { return this->name; }

    string getStatus() const { return this->status; }

    string getCreator() const { return this->creator; }

    string getReviewer() const { return this->reviewer; }

    void changeStatus(const string& status) {
        this->status = status;
    }

    void changeReviewer(const string& rev){
        this->reviewer = rev;
    }

};

inline bool operator==(const Source& a, const Source& b){
    return a.getName() == b.getName();
}

#endif // Source_H
