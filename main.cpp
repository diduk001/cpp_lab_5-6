#include <iostream>
#include "Article.h"

int main() {
    char **authors = new char *[2]{"Author1", "Author2"};
    Article a = Article(authors, 2, "Title", 1.5, 1, "Language");
    std::cout << a << std::endl;
    return 0;
}
