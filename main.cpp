#include <iostream>
#include <vector>

using namespace std;


class Book
{
    private :
        string name ;
        string author ;
        int year ;



    public :
        int versions ;
        Book ()
        {
           name ="   " ;
           author = "   " ;
           year=2000;
           versions = 0;
        }
        Book (string n , string a , int y ,int v)
        {
           name =n ;
           author = a ;
           year=y;
           versions = v;
        }

    friend  ostream& operator<< (ostream& out , Book& b) ;
    friend  istream& operator>> (istream& in , Book& b) ;

    friend int SearchByName (vector <Book> v ,string key) ;

    friend int SearchByAuthor (vector <Book> v ,string key) ;

    friend void sortingByName (vector <Book> v);

    friend void sortingByVersions (vector <Book> v) ;


  //  friend void updateVersions ( vector <Book> books);



//1. Add book
//2. Search book by name
//3. Search book by author
//4. List books in alphabetical order (Ascending)
//5. Update available number of versions of a book (user enters book name and the
//new number)
//6. Find the books which have the highest number of versions and print books
//information.



};

    ostream& operator<< (ostream& out , Book& b)
    {

            cout<<"The title of the book :"<< b.name<<endl;
            cout<<"The Author name :"<< b.author<<endl;
            cout<<"The year :"<< b.year<<endl;
            cout<<"The number of versions :"<< b.versions<<endl;

        return out;
    }
     istream& operator>> (istream& in , Book& b)
    {

            cout<<"Enter the title of the book."<<endl ;
            getline(in,b.name) ;
            cout<<endl<<"Enter the name of the Author."<<endl;
            getline(in,b.author) ;
            cout<<endl<<"Enter the publish year."<<endl;

            in>>b.year ;
            cout<<endl<<"Enter the number of versions."<<endl;
            in>>b.versions;

        return in ;
    }
    int SearchByName (vector <Book> v ,string key)
    {   for (int i=0 ; i<v.size();i++)
        {
         if ( v[i].name==key)
        {

            return i ;
        }}
          return -1 ;
    }
    int SearchByAuthor (vector <Book> v ,string key)
    {   for (int i=0 ; i<v.size();i++)
        {
             if ( v[i].author==key)
             {

                  return i ;

             }

        }
        return -1 ;
    }
    void sortingByName (vector <Book> v)
    {   Book mini = v[0]  ;
        int miniIndex;
        for (int i=0 ; i<v.size()-1;i++)
        {   mini = v[i] ;
           for (int j=i+1 ; j<v.size();j++)
           {
                if (v[i].name >v[j].name)
                {
                    mini= v[j] ;
                    miniIndex = j ;

                }
           }
           swap (v[i],v[miniIndex]);
        }
    }
    void sortingByVersions (vector <Book> v)
    {   Book mini = v[0]  ;
        int miniIndex;
        for (int i=0 ; i<v.size()-1;i++)
        {   mini = v[i] ;
           for (int j=i+1 ; j<v.size();j++)
           {
                if (v[i].versions > v[j].versions)
                {
                    mini= v[j] ;
                    miniIndex = j ;

                }
           }
           swap (v[i],v[miniIndex]);
        }
    }

/*void updateVersions ( vector <Book> books)
{
    string key ; int numOfVers ;
    cout<<"Enter the name of the book to update it's number of versions "<<endl;
    cin>> key ;
    int keyIndex = SearchByName ( books, key);
    if (keyIndex==-1)
    {
        cout<<"The Book does not exist " <<endl;

    }
     else
    {
         cout<<endl<<"Enter the new number of versions "<<endl;
         cin>>numOfVers;
         books[keyIndex].versions=numOfVers;
         cout<<"The updated number of versions is : "<<books[keyIndex].versions <<endl;

     }
}
*/
int main()
{
    vector <Book> books ;
    Book h;
    int c;
    cout<<"Enter the first book "<<endl;
    cin>>h;
    books.push_back(h);
    while(true){
    cout<<"Enter what you want . \n\n1)Add a book. \n2)Search by Name. \n3)Search by author. \n4)List books in alphabetical order (Ascending)\n";
    cout<<"5)Update available number of versions of a book (Enter the book name).\n6)Getting books with the highest number of versions\n7)Exit\n";
    cin>>c ;
    if (c==1)
    {
    cout<<"Enter the first Book "<<endl ;
    cin.ignore();
    cin>>h;
    books.push_back(h);

    }
    else if (c==2)
    {
        string key ;
        cout<<"Enter the key you want to search for "<<endl ;
        cin>>key ;
        int s =SearchByName (books , key);
        if (s==-1) cout<<"The book is not found "<<endl ;
        else cout<< books[s] ;
    }
    else if (c==3)
    {
        string key ;
        cout<<"Enter the key you want to search for "<<endl ;
        cin>>key ;
        int s =SearchByAuthor (books , key);
        if (s==-1) cout<<"The book is not found "<<endl ;
        else cout<< books[s] ;
    }
    else if (c==4)
    {
         sortingByName (books);
         for (int i=0 ; i<books.size() ; i++) cout<<books[i]<<endl ;
    }
    else if (c==5)
    {
       string key ; int numOfVers ;
    cout<<"Enter the name of the book to update it's number of versions "<<endl;
    cin>> key ;
    int keyIndex = SearchByName ( books, key);
    if (keyIndex==-1)
    {
        cout<<"The Book does not exist " <<endl;

    }
     else
    {
         cout<<endl<<"Enter the new number of versions "<<endl;
         cin>>numOfVers;
         books[keyIndex].versions=numOfVers;
         cout<<"The updated number of versions is : "<<books[keyIndex].versions <<endl;

     }
    }
    else if (c==6)
    {
        sortingByVersions  ( books);
        for (int i=0 ; i<books.size() ; i++) cout<<books[i]<<endl ;

    }
    else if (c==7) return 0 ;
    else cout<<"What you have entered is not valid . Kindly, Enter the number of the operation"<<endl ;
}
}
