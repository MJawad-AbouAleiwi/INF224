#include "group.h"

using namespace std;


Group::Group() : list<shared_ptr<Multimedia>>(), groupName("no name") {};

Group::Group(const string groupName) : list<shared_ptr<Multimedia>>(), groupName(groupName) {};


Group::~Group() {
    cout << "Group " << groupName << " is destructed." << endl;
}


string Group::getGroupName() const
{
    return groupName;
}

void Group::setGroupName(const string groupName)
{
    this->groupName = groupName;
}


void Group::display(ostream &s) const
{
    s << "Group name: " << groupName << "; ";
    for (auto & it : *this)
    {  
        it->display(s);
        s << "; ";
    }
}


void Group::addMultimedia(shared_ptr<Multimedia> multimedia)
{
    this->push_back(multimedia);
}

void Group::removeMultimedia(shared_ptr<Multimedia> multimedia)
{
    this->remove(multimedia);
}

void Group::removeMultimedia(const string name)
{
    for (auto it = this->begin(); it != this->end(); ++it)
    {
        if ((*it)->getName() == name)
        {
            this->remove(*it);
            break;
        }
    }
}