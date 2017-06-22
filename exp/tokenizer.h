#ifndef TOKENIZER_H
#define TOKENIZER_H

extern "C" {
    void makeToken(const char* str, char* tokhold, bool* done);
}

#endif