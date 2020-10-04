#include<string>
#include "Book_Management.h"
#include "Member_Management.h"
#include <vector>
using namespace std;

Book::Book() {
    this->total=0;
    this->borrowers = vector <Member *>();
}

Book::~Book() {}

string Book :: getName(){
    return this-> name;
}

int Book :: getPublishYear(){
    return this->publishYear;
}

string Book :: getAuthor(){
    return this->author;
}

string Book:: getISBN(){
    return this->isbn;
}

int Book :: getTotal(){
    return this->total;
}

vector <Member *> Book :: getborrowers(){
    return this->borrowers;
}

int Book::getBorrowedCount(){
    return this->borrowers.size();
}

int Book::getRemainingCount(){
    int remaining_count = total-this->getBorrowedCount();
}

bool Book::canbeBorrowed(){
    return this->getRemainingCount() + 1 >= 0;
}

bool Book::canbeBorrowedTo(Member *member){
    if(!this->canbeBorrowed())
    {
        return false;
    }
    if(member->hasborrowedbook(this))
    {
        return false;
    }
    return true;
}

Book *Book::setName(string name){
    this->name=name;
    return this;
}

Book *Book::setPublishYear(int publishYear){
    this->publishYear=publishYear;
    return this;
}

Book *Book :: setAuthor(string author){
    this->author=author;
    return this;
}

Book *Book :: setISBN(string ISBN){
    this->isbn=ISBN;
    return this;
}
Book *Book :: setTotal(int total){
    this->total=total;
    return this;
}

void Book :: borrowTo(Member *member){
    this->borrowers.push_back(member);
    member->addBorrowedBook(this);
}
void Book :: takeBackfrom(Member *member){
    for(auto mem=this->borrowers.begin(); mem !=borrowers.end(); mem++)
    {
        if((*mem)->getId()==member->getId())
        {
            this->borrowers.erase(mem);
            break;
        }
    }
    member->RemoveBorrowedBook(this);
}
