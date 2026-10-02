#include "movie.h"

using namespace std;

Movie::Movie() : Video(), Count(0), chapters(nullptr)
{
}

Movie::Movie(string name, string path, int duration) : Video(name, path, duration), Count(0), chapters(nullptr)
{
}

Movie::Movie(string name, string path, int duration, int Count, int *chapters) : Video(name, path, duration)
{
    this->setChapters(chapters, Count);
}

Movie::Movie(const Movie &from) : Video(from), Count(from.Count)
{
    if (from.chapters)
    {
        this->setChapters(from.chapters, from.Count);
    }
    else
    {
        chapters = nullptr;
    }
}

Movie &Movie::operator=(const Movie &from)
{
    if (this != &from)
    {
        Video::operator=(from);
        this->setChapters(from.chapters, from.Count);
    }
    return *this;
}


const int *Movie::getChapters() const
{
    return chapters;
}

void Movie::setChapters(int *newChapters, int newCount)
{
    delete[] chapters;
    if (newChapters)
    {
        chapters = new int[newCount];
        for (int i = 0; i < newCount; i++)
        {
            chapters[i] = newChapters[i];
        }
        Count = newCount;
    }
    else
    {
        chapters = nullptr;
    }
}

int Movie::getChapterCount() const
{
    return Count;
}


void Movie::display(ostream &s) const
{
    s << "Movie: Name: " << getName() << " ,Path: " << getPath() << " ,Duration : " << getDuration() << " ,chapterCount: " << Count << " ,Chapters: ";
    for (int i = 0; i < Count; i++)
    {
        s << chapters[i] << " ";
    }
    s << ".";
}

Movie::~Movie()
{
    delete[] chapters;
    cout << "Movie object " << getName() << " is destructed." << endl;
}
