//
// Created by Stepan on 21.11.2023.
//

#include <vector>
#include <string>
#include <ostream>

#ifndef CPP_LAB_56_ARTICLE_H
#define CPP_LAB_56_ARTICLE_H

class Article {
    char **authors;
    size_t authorsCount;
    char *articleTitle;
    double citationCoefficient;
    size_t articleVolume;
    char *language;

    // Constructors and destructors
public:

    Article();

    Article(char **authors, size_t authorsCount, char *articleTitle, double citationCoefficient, size_t articleVolume,
            char *language);

    Article(const Article &other);

    ~Article();


    // Getters and setters

    const char **getAuthors() const { return (const char **) authors; }

    const size_t getAuthorsCount() const { return authorsCount; }

    const char *getArticleTitle() const { return articleTitle; }

    const double getCitationCoefficient() const { return citationCoefficient; }

    const size_t getArticleVolume() const { return articleVolume; }

    const char *getLanguage() const { return language; }

    void setAuthors(char **newAuthors, size_t newAuthorsCount) {
        this->authors = newAuthors;
        this->authorsCount = newAuthorsCount;
    }

    void setArticleTitle(char *newArticleTitle) { this->articleTitle = newArticleTitle; }

    void setCitationCoefficient(double newCitationCoefficient) { this->citationCoefficient = newCitationCoefficient; }

    void setArticleVolume(size_t newArticleVolume) { this->articleVolume = newArticleVolume; }

    void setLanguage(char *newLanguage) { this->language = newLanguage; }
};


// Output
std::ostream &operator<<(std::ostream &out, const Article &article);

#endif //CPP_LAB_56_ARTICLE_H
