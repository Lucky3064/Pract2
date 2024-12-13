
/*Imagine a publishing company which does marketing for book and audio 
cassette versions. Create a class publication that stores the title (a string) and 
price (type float) of publications. From this class derive two classes: book which 
adds a page count (type int) and tape which adds a playing time in minutes (type 
float). Write a program that instantiates the book and tape class, allows user to 
enter data and displays the data members. If an exception is caught, replace all 
the data member values with zero values.*/

#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}

    void input() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        if (cin.fail()) throw invalid_argument("Invalid price input");
        cin.ignore(); // Clear the input buffer
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    Book() : pageCount(0) {}

    void input() {
        Publication::input();
        cout << "Enter page count: ";
        cin >> pageCount;
        if (cin.fail()) throw invalid_argument("Invalid page count input");
        cin.ignore(); // Clear the input buffer
    }

    void display()  {
        Publication::display();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;

public:
    Tape() : playingTime(0.0) {}

    void input() {
        Publication::input();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
        if (cin.fail()) throw invalid_argument("Invalid playing time input");
        cin.ignore(); // Clear the input buffer
    }

    void display() {
        Publication::display();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book book;
    Tape tape;

    try {
        cout << "Enter details for book:\n";
        book.input();

        cout << "\nEnter details for tape:\n";
        tape.input();

        cout << "\nBook Details:\n";
        book.display();

        cout << "\nTape Details:\n";
        tape.display();
    } catch (const exception &e) {
        cout << "\nAn error occurred: " << e.what() << endl;
        cout << "Resetting all values to default.\n";

        // Reset book and tape
        book = Book();
        tape = Tape();

        cout << "\nReset Book Details:\n";
        book.display();

        cout << "\nReset Tape Details:\n";
        tape.display();
    }

    return 0;
}
