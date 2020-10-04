#ifndef MEMBER_MANAGEMENT_H_INCLUDED
#define MEMBER_MANAGEMENT_H_INCLUDED
#pragma once
#include <vector>
#include <string>
using namespace std;

class Book;
class Member
{
private:
    string firstname;
    string lastName;
    int entranceYear;
    string id;
    vector<Book *> borrowedBooks;

public:
    Member(string id);
    ~Member();
    string getFirstname();
    string getLastname();
    int getEntranceYear();
    string getId();
    vector <Book *> getborrowedBooks();
    int getborrowedBooksCount();
    bool hasborrowedbook(Book* book);

    Member *SetFirstName(string firstname);
    Member *SetLastName(string lastName);
    Member *SetEntranceYear(int entranceYear);
    Member *SetId(string id);
    int addBorrowedBook(Book* book);
    bool RemoveBorrowedBook(Book* book);
};
#endif // MEMBER_MANAGEMENT_H_INCLUDED
