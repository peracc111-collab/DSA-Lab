#include<iostream>
#include<string>
using namespace std;
class Media {
public:
    virtual void display() = 0;
};
class Book : public Media {
public:
    string title, author;
    int pages;
    Book(){}
    Book(string t, string a, int p){ title = t; author = a; pages = p; }
    void display(){ cout<<title<<" by "<<author<<" ("<<pages<<" pages)"<<endl; }
};
class Newspaper : public Media {
public:
    string name, date, edition;
    Newspaper(){}
    Newspaper(string n, string d, string e){ name = n; date = d; edition = e; }
    void display(){ cout<<name<<" - "<<date<<" - "<<edition<<endl; }
};
class Library {
    Book books[50];
    Newspaper papers[50];
    int bCount = 0;
    int pCount = 0;
public:
    void addBook(Book b){ books[bCount++] = b; }
    void addNewspaper(Newspaper n){ papers[pCount++] = n; }
    void displayCollection(){
        for(int i=0; i<bCount; i++) books[i].display();
        for(int i=0; i<pCount; i++) papers[i].display();
    }
    void sortBooksByPages(){
        for(int i=0; i<bCount-1; i++){
            for(int j=i+1; j<bCount; j++){
                if(books[j].pages < books[i].pages){
                    Book temp = books[i]; books[i] = books[j]; books[j] = temp;
                }
            }
        }
    }
    void sortNewspapersByEdition(){
        for(int i=0; i<pCount-1; i++){
            for(int j=i+1; j<pCount; j++){
                if(papers[j].edition < papers[i].edition){
                    Newspaper temp = papers[i]; papers[i] = papers[j]; papers[j] = temp;
                }
            }
        }
    }
    Book* searchBookByTitle(string title){
        for(int i=0; i<bCount; i++) if(books[i].title == title) return &books[i];
        return NULL;
    }
    Newspaper* searchNewspaperByName(string name){
        for(int i=0; i<pCount; i++) if(papers[i].name == name) return &papers[i];
        return NULL;
    }
};
int main(){
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);
    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");
    Library library;
    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);
    cout<<"Before Sorting:\n";
    library.displayCollection();
    library.sortBooksByPages();
    library.sortNewspapersByEdition();
    cout<<"\nAfter Sorting:\n";
    library.displayCollection();
    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) {
        cout<<"\nFound Book:\n";
        foundBook->display();
    } else {
        cout<<"\nBook not found.\n";
    }
    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper) {
        cout<<"\nFound Newspaper:\n";
        foundNewspaper->display();
    } else {
        cout<<"\nNewspaper not found.\n";
    }
    return 0;
}
