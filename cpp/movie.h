#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include "video.h"

using namespace std;

class Movie : public Video
{
private:
    int Count = 0;
    int *chapters = nullptr;

public:
    // constructors
    Movie();
    Movie(string name, string path, int duration);
    Movie(string name, string path, int duration, int Count, int *chapters);

    // copy constructors
    Movie(const Movie &from);
    Movie &operator=(const Movie &from);

    // getter
    const int *getChapters() const;
    // setter
    void setChapters(int *chapters, int Count);

    int getChapterCount() const;

    // display
    virtual void display(ostream &s) const override;

    // destructor
    virtual ~Movie();
};

#endif // MOVIE_H