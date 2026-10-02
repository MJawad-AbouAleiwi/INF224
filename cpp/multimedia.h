#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>

using namespace std;

class Multimedia
{
private:
    string name;
    string path;

public:

    // constructors
    Multimedia();

    Multimedia(string name, string path);

    // destructor
    virtual ~Multimedia();

    // getters
    const string &getName() const;
    const string &getPath() const;

    // setters
    void setName(string name);
    void setPath(string path);


    virtual void display(ostream &s) const;

    virtual void play() const = 0;
};

#endif // MEDIA_H