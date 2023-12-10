#include "BookLink.h"

using namespace std;

/*
void BookLink::readXlsFile(const string fileName) {
    ifstream infile(fileName,ios::binary);
    if (!infile) {
        cerr << "OPEN ERROR!" << endl;
    }
    Book newBook;
    while (infile.read((char*)&newBook,sizeof(newBook))) {
        this->insertBook(newBook);
    }
    infile.close();
}
*/
/*
void BookLink::readCsvFile(const string fileName) {
    ifstream infile(fileName);
    if (!infile) {
        cerr << "OPEN ERROR!" << endl;
        return;
    }

    vector<Book> books;
    string line;
    getline(infile, line); // Skip the header line

    while (getline(infile, line)) {
        Book newBook = Book::createBookFromString(line);
        this->insertBook(newBook);
    }

    infile.close();
}
 */