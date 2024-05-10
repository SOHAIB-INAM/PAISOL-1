#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MediaItem;

class Person {
private:
    string name;

public:
    Person(string _name) : name(_name) {}
    string getName() const { return name; }
};

class MediaItem {
protected:
    string title;
    string genre;
    int year;

public:
    MediaItem(string _title, string _genre, int _year)
        : title(_title), genre(_genre), year(_year) {}

    virtual void displayInfo() const {
        cout << "Title: " << title << "\nGenre: " << genre << "\nYear: " << year << endl;
    }
};

class Book : public MediaItem {
private:
    string author;

public:
    Book(string _title, string _genre, int _year, string _author)
        : MediaItem(_title, _genre, _year), author(_author) {}

    void displayInfo() const override {
        MediaItem::displayInfo();
        cout << "Author: " << author << endl;
    }
};

class Movie : public MediaItem {
private:
    vector<Person> actors;

public:
    Movie(string _title, string _genre, int _year, const vector<Person>& _actors)
        : MediaItem(_title, _genre, _year), actors(_actors) {}

    void displayInfo() const override {
        MediaItem::displayInfo();
        cout << "Actors: ";
        for (const auto& actor : actors) {
            cout << actor.getName() << ", ";
        }
        cout << endl;
    }
};

class MusicAlbum : public MediaItem {
private:
    string artist;

public:
    MusicAlbum(string _title, string _genre, int _year, string _artist)
        : MediaItem(_title, _genre, _year), artist(_artist) {}

    void displayInfo() const override {
        MediaItem::displayInfo();
        cout << "Artist: " << artist << endl;
    }
};

int main() {
    vector<Person> actors = {Person("Actor1"), Person("Actor2")};
    Book book("Book Title", "Fiction", 2020, "Author Name");
    Movie movie("Movie Title", "Action", 2019, actors);
    MusicAlbum album("Album Title", "Pop", 2021, "Artist Name");

    book.displayInfo();
    cout << endl;
    movie.displayInfo();
    cout << endl;
    album.displayInfo();

    return 0;
}
