//
// Created by Stepan on 23.11.2023.
//

#include "Article.h"
#include <cstring>
#include <iostream>

Article::Article() {
    authors = nullptr;
    authorsCount = 0;
    articleTitle = nullptr;
    citationCoefficient = 0;
    articleVolume = 0;
    language = nullptr;
}

Article::Article(char **authors, size_t authorsCount, char *articleTitle, double citationCoefficient,
                 size_t articleVolume, char *language) {
    this->authors = new char *[authorsCount];
    for (int i = 0; i < authorsCount; ++i) {
        this->authors[i] = new char[strlen(authors[i]) + 1];
        strcpy(this->authors[i], authors[i]);
    }
    this->authorsCount = authorsCount;
    this->articleTitle = new char[strlen(articleTitle) + 1];
    strcpy(this->articleTitle, articleTitle);
    this->citationCoefficient = citationCoefficient;
    this->articleVolume = articleVolume;
    this->language = new char[strlen(language) + 1];
    strcpy(this->language, language);
}

Article::Article(const Article &other) {
    this->authors = new char *[other.authorsCount];
    for (int i = 0; i < other.authorsCount; ++i) {
        this->authors[i] = new char[strlen(other.authors[i]) + 1];
        strcpy(this->authors[i], other.authors[i]);
    }
    this->authorsCount = other.authorsCount;
    this->articleTitle = new char[strlen(other.articleTitle) + 1];
    strcpy(this->articleTitle, other.articleTitle);
    this->citationCoefficient = other.citationCoefficient;
    this->articleVolume = other.articleVolume;
    this->language = new char[strlen(other.language) + 1];
    strcpy(this->language, other.language);
}

Article::~Article() {
    for (int i = 0; i < this->getAuthorsCount(); ++i) {
        if (this->authors[i]) delete[] this->authors[i];
    }

    delete[] this->authors;
    delete[] this->articleTitle;
    delete[] this->language;
}


std::ostream &operator<<(std::ostream &out, const Article &article) {
    if (!article.getAuthors()) {
        out << "Article()";
        return out;
    }

    out << "Article({";
    const char **authors = article.getAuthors();
    for (size_t i = 0; i < article.getAuthorsCount(); ++i) {
        out << '"';
        out << authors[i];
        out << '"';
        if (i != article.getAuthorsCount() - 1) {
            out << ", ";
        }
    }
    out << "}, ";
    out << article.getAuthorsCount() << ", ";
    out << '"';
    out << article.getArticleTitle();
    out << '"';
    out << ", ";
    out << article.getCitationCoefficient() << ", ";
    out << article.getArticleVolume() << ", ";
    out << '"';
    out << article.getLanguage();
    out << '"';
    out << ")";
    return out;
}
