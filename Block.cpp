#include "Block.h"
#include "sha256.h"

Block::Block(int index, const string &data) : index(index), data(data)
{
    nonce = 0; 
    timestamp = time(nullptr);

    hash = calculate_hash();
}

void Block::mine_block(int difficulty)
{
    /*
     * To successfully create a valid block, and therefore be rewarded, 
     * a miner must create a cryptographic hash of the block they want 
     * to add to the blockchain that matches the requirements for a valid 
     * hash at that time; this is achieved by counting the number of zeros 
     * at the beginning of the hash, if the number of zeros is equal to or 
     * greater than the difficulty level set by the network that block is valid. 
     * If the hash is not valid a variable called a nonce is incremented and the 
     * hash created again; this process, called Proof of Work (PoW), is repeated 
     * until a hash is produced that is valid.
    **/

    char zeros[difficulty + 1];
    for (int i = 0; i < difficulty; ++i) {
        zeros[i] = '0';
    }
    zeros[difficulty] = '\0';
    string str(zeros);

    do {
        nonce++;
        hash = calculate_hash();
    } while (hash.substr(0, difficulty) != str);

    cout << "Block mined : " << hash << endl;
}

string Block::calculate_hash()
{
    stringstream ss;
    ss << index << prev_hash << timestamp << data << nonce;

    return sha256(ss.str());
}

string Block::get_hash() 
{
    return hash;
}


