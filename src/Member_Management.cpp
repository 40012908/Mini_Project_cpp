#include <vector>
#include <string>
#include "Member_Management.h"
#include "Book_Management.h"
using namespace std;

Member::Member(string id){
    this->id=id;
    this->borrowedBooks=vector<Book *>(); }
Member :: ~Member(){}
string Member :: getFirstname(){ return this->firstname;}
string Member :: getLastname(){ return this->lastName;}
int Member::getEntranceYear(){ return this->entranceYear; }
string Member :: getId(){ return this->id; }
vector <Book *> Member :: getborrowedBooks(){ return this->borrowedBooks;}
int Member::getborrowedBooksCount() { return this->borrowedBooks.size();}
bool Member::hasborrowedbook(Book* book){
    for(auto borrower = this->borrowedBooks.begin(); borrower!=this->borrowedBooks.end(); borrower++)
    {
        if((*borrower)->getISBN() == book->getISBN()) { return true; }
        else {return false;} }}

Member *Member :: SetFirstName(string firstname) {
    this->firstname=firstname;
    return this; }
Member *Member :: SetLastName(string lastName) {
    this->lastName=lastName;
    return this; }
Member *Member :: SetEntranceYear(int entranceYear){
    this->entranceYear=entranceYear;
    return this; }
Member *Member :: SetId(string id){
    this->id=id;
    return this; }
int Member :: addBorrowedBook(Book* book) {
    this->borrowedBooks.push_back(book);
    return this->getborrowedBooksCount(); }
bool Member:: RemoveBorrowedBook(Book* book){
    uint index=0;
    for(auto Remo_book = this->borrowedBooks.begin(); Remo_book != this->borrowedBooks.end(); Remo_book++) {
            if((*Remo_book)->getISBN()==book->getISBN()) {
                this->borrowedBooks.erase(Remo_book);
                return true; } }
    return false; }


