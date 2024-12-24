#pragma once

#include <iostream>
#include <fstream>
#include <cstring>

const int MAX_SENTENCES = 3;  
const int MAX_BUFFER = 8192; 

class SentenceFilter {
private:
    char sentences[MAX_SENTENCES][MAX_BUFFER]; 
    int sentenceCount;                        

    void split_into_sentences(const char* text);

public:
    SentenceFilter(); 
    SentenceFilter(const char* text); 
    SentenceFilter(const SentenceFilter& other); 
    ~SentenceFilter(); 

    void processFromFile(const char* filename); 
    void processFromInput();                    
    void printReversed() const;                 
};
