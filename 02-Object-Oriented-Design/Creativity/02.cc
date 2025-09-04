/*
# C-2.2
Suppose you are on the design team for a new e-book reader. What are the
primary classes and functions that the C++ software for your reader will
need? You should include an inheritance diagram for this code, but you
don’t need to write any actual code. Your software architecture should
at least include ways for customers to buy new books, view their list of
purchased book, and read their purchased books.

Book
- author
- price
- pages
- publication
+ allGetters&Setters

Library
- books: vector<pair<Book, int>>
+ isBookAvailable()
+ purchaseBook()
+ returnBook()

Person
- name
- id
- mobile
- email
- getters&setters
^
Customer
- books: vector<pair<Book, int>>
+ purchaseBook()
+ listBooks()
+ returnBook()
*/

