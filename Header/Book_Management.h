#ifndef BOOK_MANAGEMENT_H_INCLUDED
#define BOOK_MANAGEMENT_H_INCLUDED
#pragma once
#include <string>
#include <vector>
using namespace std;

class Member;

class Book {
private:
    string name;
    int publishYear;
    string author;
    string isbn;
    int total;
    vector <Member *> borrowers;
public:
    Book();
    ~Book();
    string getName();
    int getPublishYear();
    string getAuthor();
    string getISBN();
    int getTotal();
    vector <Member *> getborrowers();
    int getBorrowedCount();
    int getRemainingCount();
    bool canbeBorrowed();
    bool canbeBorrowedTo(Member *member);

    Book *setName(string name);
    Book *setPublishYear(int publishYear);
    Book *setAuthor(string author);
    Book *setISBN(string ISBN);
    Book *setTotal(int total);
    void borrowTo(Member *member);
    void takeBackfrom(Member *member);
};
#endif // BOOK_MANAGEMENT_H_INCLUDED
