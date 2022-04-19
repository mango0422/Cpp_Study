#include <iostream>
#include <cstring>
using namespace std;

class Book{
    private:
        char * title;
        char * isbn;
        int price;
    public:
        Book(const char * t1, const char * i1, int p1) : price(p1){
            this->title = new char[strlen(t1) + 1];
            strcpy(this->title, t1);
            this->isbn = new char[strlen(i1) + 1];
            strcpy(this->isbn, i1);
        }
        Book(const Book& ref){
            title = new char[strlen(ref.title) + 1];
            isbn = new char[strlen(ref.title) + 1];
            strcpy(title, ref.title);
            strcpy(isbn, ref.isbn);
        }
        Book& operator=(const Book& ref){   // ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
            delete []title;
            delete []isbn;

            cout<<"Book operator=()"<<endl;
            title = new char[strlen(ref.title) + 1];
            isbn = new char[strlen(ref.isbn) + 1];
            strcpy(title, ref.title);
            strcpy(isbn, ref.isbn);
            return *this;
        }
        void ShowBookInfo() const {
            cout<<"ï¿½ï¿½ï¿½ï¿½: "<<title<<endl;
            cout<<"ISBN: "<<isbn<<endl;
            cout<<"ï¿½ï¿½ï¿½ï¿½: "<<price<<"ï¿½ï¿½"<<endl;
        }
        ~Book(){
            delete []title;
            delete []isbn;
        }
};

class EBook : public Book{
    private:
        char* DRMKey;
    public:
        EBook(const char * t1, const char * i1, int p1, const char * d1) : Book(t1, i1, p1){
            DRMKey = new char[strlen(d1) + 1];
            strcpy(DRMKey, d1);
        }
        EBook(const EBook& ref) : Book(ref){
            DRMKey = new char[strlen(ref.DRMKey) + 1];
            strcpy(DRMKey, ref.DRMKey);
        }
        EBook& operator=(const EBook& ref){ // ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
            Book::operator=(ref);
            delete []DRMKey;
            cout<<"EBook operator=()"<<endl;
            DRMKey = new char[strlen(ref.DRMKey) + 1];
            strcpy(DRMKey, ref.DRMKey);
            return *this;
        }
        void ShowBookInfo() const{
            Book::ShowBookInfo();
            cout<<"ï¿½ï¿½ï¿½ï¿½Å°: "<<DRMKey<<endl<<endl;
        }
        ~EBook(){
            delete []DRMKey;
        }
};

int main(){
    EBook book1("ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ C++ ï¿½ï¿½ï¿½Î±×·ï¿½ï¿½ï¿½", "978-89-960940-4-3",27000, "2QW6-EDYD-SQB7-MZLZ");
    book1.ShowBookInfo();
    
    EBook book2 = book1;
    book2.ShowBookInfo();
    
    EBook book3("","",0,"");
    book3 = book1;
    book3.ShowBookInfo();

    return (0);
}

/*
 * quiz11-2ï¿½ï¿½ ï¿½Ù½ï¿½
 * 1. ï¿½Ç»ï¿½ï¿? Å¬ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿? ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Ú¸ï¿½ ï¿½ï¿½ï¿½ï¿½Ú°ï¿? ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Ï¿ï¿½ ï¿½ï¿½ï¿½ï¿½Ñ´ï¿?.
 * 2. ï¿½ï¿½ï¿? Å¬ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Ç»ï¿½ï¿? Å¬ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿? ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ú¸ï¿? ï¿½Ò·ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½Ñ´ï¿?.
 */