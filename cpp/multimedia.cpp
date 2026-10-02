
#include <string>
#include <iostream>
#include "multimedia.h"

using namespace std;


Multimedia::Multimedia() = default;

Multimedia::Multimedia(string name, string path) : name(name), path(path) {}


Multimedia::~Multimedia()
{
    cout << "Multimedia object " << name << " is destructed." << endl;
}


const string &Multimedia::getName() const
{
    return name;
}

const string &Multimedia::getPath() const
{
    return path;
}

void Multimedia::setName(string name)
{
    this->name = name;
}

void Multimedia::setPath(string path)
{
    this->path = path;
}


void Multimedia::display(ostream &s) const
{
    s << "Multimedia object:Name : " << name << " ,Path : " << path << ".";
}
