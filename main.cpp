#include <iostream>
#include "Article.h"

int main() {
    Article a = Article(new char *[2]{"Author1", "Author2"},
                        2, ""
                           "Title",
                        1.5,
                        1,
                        "Language"
    );
    std::cout << a << std::endl;
    return 0;
}
