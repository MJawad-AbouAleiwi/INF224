#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include "multimedia.h"

using namespace std;


class Video : public Multimedia
{
private:
    int duration{};

public:
    Video() : Multimedia() { duration = 0; };
    Video(string name, string path, int duration) : Multimedia(name, path) { this->duration = duration; };

    int getDuration() const { return duration; };
    void setDuration(int duration) { this->duration = duration; };
    void display(ostream &s) const override
    {
        s << "Multimedia object: Name: " << getName() << " ,Path : " << getPath() << " ,Duration : " << duration << ".";
    };

    void play() const override
    {
        string command = "mpv ";
        command += getPath() + getName();
        command += " &";
        cout << "Playing video " << getName() << " in " << getPath() << endl;
        system(command.data());
    };

    ~Video() override
    {
        cout << "Video object " << getName() << " is destructed." << endl;
    };
};

#endif // VIDEO_H
