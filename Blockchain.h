#ifndef _BLOCKCHAIN_H
#define _BLOCKCHAIN_H

#include <vector>
#include "Block.h"

using namespace std;

class Blockchain {
public:
    Blockchain();

    void add_block(Block b);

private:
    int difficulty;
    vector<Block> chain;

    Block get_last_block() const;
};

#endif
