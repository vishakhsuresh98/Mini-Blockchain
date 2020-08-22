#include "Blockchain.h"

Blockchain::Blockchain()
{
    chain.emplace_back(Block(0, "Genesis block")); // frist block in the chain
    difficulty = 2; // measure of how hard we want to make the PoW process
}

void Blockchain::add_block(Block block)
{
    Block last_block = get_last_block();
    block.prev_hash = last_block.get_hash();
    block.mine_block(difficulty);
    chain.push_back(block);
}

Block Blockchain::get_last_block() const
{
    return chain.back();
}
