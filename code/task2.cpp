#include<iostream>
using namespace std;
class Librarian;
class Book{
    string title;
    float price;
    public:
        Book(string title,float price){
            this->title=title;
            this->price=price;
        }
        friend class Librarian;
};
class Librarian{
    public:
        void display_book_details(Book b){
            cout<<"Title: "<<b.title<<endl;
            cout<<"Price: "<<b.price<<endl;
        }
        void apply_discount(Book *b){
            b->price=(b->price*90)/100;
            cout<<"10% discount is applied"<<endl;
        }
};
int main(){
    Book book("The Prisoner",200);
    Librarian lib;
    cout<<"Displaying book details"<<endl;
    lib.display_book_details(book);
    cout<<endl<<"Applying discount on book"<<endl;
    lib.apply_discount(&book);
    cout<<endl<<"Displaying updated book details"<<endl;
    lib.display_book_details(book);
    return 0;
}