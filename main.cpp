#include <iostream>
#include "Article.h"

int main() {
    const Article a = Article(new char *[2]{"Author1", "Author2"},
                              2,
                              "Article A",
                              1.5,
                              100,
                              "Language A"
    );

    const Article b = Article(new char *[2]{"Author1", "Author3"},
                              2,
                              "Article B",
                              1.1,
                              200,
                              "Language B");

    const Article c = Article(new char *[2]{"Author2", "Author1"},
                              2,
                              "Article C",
                              1.3,
                              300,
                              "Language C");

    const Article *articles = new Article[]{a, b, c};

    std::cout << "Author1's articles number: " <<
              getAuthorsArticleNumber(articles,
                                      3,
                                      "Author1")
              << std::endl;

    std::cout << "Average volume with coefficient larger than 1.2: " <<
              averageVolumeWithCoefficientLargerThan(articles,
                                                     3,
                                                     1.2)
              << std::endl;

    char** authors = new char *[]{"Author1", "Author2", "Author3"};
    sortAuthorsByCitationRate(articles,
                              3,
                              authors,
                              3);
    std::cout << "Sorted articles:\n";
    for (size_t i = 0; i < 3; i++) {
        std::cout << authors[i] << std::endl;
    }
    return 0;
}
