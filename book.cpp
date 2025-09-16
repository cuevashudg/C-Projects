#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Book {
    int id;
    string title, author;
    bool borrowed = false;
};

struct User {
    int id;
    string name;
};

struct Record {
    int bookId, userId;
    bool returned = false;
};

class Library {
    vector<Book> books;
    vector<User> users;
    vector<Record> records;
    int nextBookId = 1, nextUserId = 1;
public:
    void addBook(const string& t, const string& a) {
        books.push_back({nextBookId++, t, a, false});
        cout << "Book added.\n";
    }
    void addUser(const string& n) {
        users.push_back({nextUserId++, n});
        cout << "User added.\n";
    }
    void listBooks() {
        for (auto& b : books)
            cout << "ID: " << b.id << ", " << b.title << ", " << b.author
                 << ", " << (b.borrowed ? "Borrowed" : "Available") << endl;
    }
    void listUsers() {
        for (auto& u : users)
            cout << "ID: " << u.id << ", " << u.name << endl;
    }
    void borrowBook(int bid, int uid) {
        auto b = find_if(books.begin(), books.end(), [bid](Book& x){return x.id==bid;});
        auto u = find_if(users.begin(), users.end(), [uid](User& x){return x.id==uid;});
        if (b == books.end() || u == users.end()) { cout << "Not found.\n"; return; }
        if (b->borrowed) { cout << "Already borrowed.\n"; return; }
        b->borrowed = true;
        records.push_back({bid, uid, false});
        cout << "Book borrowed.\n";
    }
    void returnBook(int bid, int uid) {
        auto b = find_if(books.begin(), books.end(), [bid](Book& x){return x.id==bid;});
        auto r = find_if(records.begin(), records.end(), [bid,uid](Record& x){return x.bookId==bid&&x.userId==uid&&!x.returned;});
        if (b == books.end() || r == records.end()) { cout << "Not found.\n"; return; }
        b->borrowed = false; r->returned = true;
        cout << "Book returned.\n";
    }
    void listRecords() {
        for (auto& r : records)
            cout << "Book " << r.bookId << ", User " << r.userId
                 << ", " << (r.returned ? "Returned" : "Borrowed") << endl;
    }
};

int main() {
    Library lib; int c;
    do {
        cout << "\n1.Add Book 2.Add User 3.List Books 4.List Users 5.Borrow 6.Return 7.Records 0.Exit\nChoice: ";
        cin >> c; cin.ignore();
        if (c==1) { string t,a; cout<<"Title: ";getline(cin,t);cout<<"Author: ";getline(cin,a);lib.addBook(t,a);}
        else if (c==2) { string n; cout<<"Name: ";getline(cin,n);lib.addUser(n);}
        else if (c==3) lib.listBooks();
        else if (c==4) lib.listUsers();
        else if (c==5) { int b,u; cout<<"Book ID: ";cin>>b;cout<<"User ID: ";cin>>u;lib.borrowBook(b,u);}
        else if (c==6) { int b,u; cout<<"Book ID: ";cin>>b;cout<<"User ID: ";cin>>u;lib.returnBook(b,u);}
        else if (c==7) lib.listRecords();
    } while (c!=0);
    cout << "Goodbye!\n";
}