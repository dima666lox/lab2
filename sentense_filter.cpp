#include "sentense_filter.h"

SentenceFilter::SentenceFilter() : sentenceCount(0) {
    for (int i = 0; i < MAX_SENTENCES; ++i) {
        sentences[i][0] = '\0';
    }
}

SentenceFilter::SentenceFilter(const char* text) : sentenceCount(0) {
    split_into_sentences(text);
}

SentenceFilter::SentenceFilter(const SentenceFilter& other) : sentenceCount(other.sentenceCount) {
    for (int i = 0; i < MAX_SENTENCES; ++i) {
        std::strncpy(sentences[i], other.sentences[i], MAX_BUFFER);
    }
}

SentenceFilter::~SentenceFilter() {}

void SentenceFilter::split_into_sentences(const char* text) {
    const char* delimiters = ".!?";
    char buffer[MAX_BUFFER];
    std::strncpy(buffer, text, MAX_BUFFER);

    char* token = std::strtok(buffer, delimiters);
    sentenceCount = 0;

    while (token != nullptr && sentenceCount < MAX_SENTENCES) {
        std::strncpy(sentences[sentenceCount], token, MAX_BUFFER);
        std::strncat(sentences[sentenceCount], ".", MAX_BUFFER - std::strlen(sentences[sentenceCount]));
        ++sentenceCount;
        token = std::strtok(nullptr, delimiters);
    }
}

void SentenceFilter::processFromFile(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::ios_base::failure("Не удалось открыть файл.");
    }

    char buffer[MAX_BUFFER] = {0};
    file.read(buffer, MAX_BUFFER - 1);
    file.close();

    split_into_sentences(buffer);
}

void SentenceFilter::processFromInput() {
    char buffer[MAX_BUFFER] = {0};
    char line[MAX_BUFFER];
    while (std::cin.getline(line, MAX_BUFFER) && std::strlen(line) > 0) {
        if (std::strlen(buffer) + std::strlen(line) + 1 >= MAX_BUFFER) {
            throw std::overflow_error("Превышен допустимый объем текста.");
        }
        std::strcat(buffer, line);
        std::strcat(buffer, " ");
    }

    split_into_sentences(buffer);
}

void SentenceFilter::printReversed() const {
    for (int i = sentenceCount - 1; i >= 0; --i) {
        std::cout << sentences[i] << "\n";
    }
}
