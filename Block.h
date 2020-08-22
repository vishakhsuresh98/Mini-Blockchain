#ifndef _BLOCK_H
#define _BLOCK_H

#include <iostream>
#include <sstream>

using namespace std;

class Block {
public:
    string hash;
    string prev_hash;

    Block(int index, const string &data);

    string get_hash();
    void mine_block(int difficulty);

private:
    int index;
    int nonce; // number only used once
    string data;
    time_t timestamp;

    string calculate_hash();
};

#endif
