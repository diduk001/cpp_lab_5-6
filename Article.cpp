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

size_t getAuthorsArticleNumber(const Article *articles, size_t articlesLen, const char *authorsName) {
    size_t result = 0;

    for (size_t articleIdx = 0; articleIdx < articlesLen; articleIdx++) {
        const Article curArticle = articles[articleIdx];
        const char **authors = curArticle.getAuthors();
        for (size_t authorIdx = 0; authorIdx < curArticle.getAuthorsCount(); authorIdx++)
            if (strcmp(authors[authorIdx], authorsName) == 0)
                result++;
    }

    return result;
}

size_t averageVolumeWithCoefficientLargerThan(const Article *articles, size_t articlesLen, double pivotCoefficient) {
    size_t volumeSum = 0;
    size_t filteredArticles = 0;

    for (size_t articleIdx = 0; articleIdx < articlesLen; articleIdx++) {
        const Article curArticle = articles[articleIdx];
        if (curArticle.getCitationCoefficient() > pivotCoefficient) {
            volumeSum += curArticle.getArticleVolume();
            filteredArticles++;
        }
    }

    return filteredArticles == 0 ? 0 : volumeSum / filteredArticles;
}

double getAuthorsCitationRate(const Article *articles, size_t articlesLen, const char *author) {
    double citationCoefficientsSum = 0;
    size_t citationCoefficientsLen = 0;
    for (size_t articleIdx = 0; articleIdx < articlesLen; articleIdx++) {
        const Article curArticle = articles[articleIdx];
        const char **curAuthors = curArticle.getAuthors();
        const size_t curAuthorsCount = curArticle.getAuthorsCount();
        for (size_t authorIdx = 0; authorIdx < curAuthorsCount; authorIdx++) {
            if (strcmp(curAuthors[authorIdx], author) == 0) {
                citationCoefficientsSum += curArticle.getCitationCoefficient();
                citationCoefficientsLen++;
            }
        }
    }

    return citationCoefficientsLen == 0 ? 0 : citationCoefficientsSum / (double)citationCoefficientsLen;
}

void sortAuthorsByCitationRate(const Article *articles, size_t articlesLen, char **authors, size_t authorsLen) {
    for (size_t step = 0; step < authorsLen - 1; step++) {
        for (size_t idx = 0; idx < authorsLen - step - 1; idx++) {
            double curAuthorsRate = getAuthorsCitationRate(articles, articlesLen, authors[idx]);
            double nxtAuthorsRate = getAuthorsCitationRate(articles, articlesLen, authors[idx + 1]);
            if (curAuthorsRate > nxtAuthorsRate) std::swap(authors[idx], authors[idx + 1]);
        }
    }
}