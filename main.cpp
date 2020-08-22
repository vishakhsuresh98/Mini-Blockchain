#include "Blockchain.h"

int main()
{
    Blockchain chain = Blockchain();

    int index = 0; 
    bool flag = true;

    do {
        index ++;
        cout << "Block " << index << " : " << endl;
        
        cout << "Data : ";
        string data;
        cin >> data;

        chain.add_block(Block(index, data));
        
        cout << "Want to proceed? [Y/N] : ";
        char choice;
        cin >> choice;

        while(true) {
            if (choice == 'N' || choice == 'n') {
                flag = false;
                break;
            }
            else if (choice == 'Y' || choice == 'y') {
                break;
            }
            else {
                cout << "Wrong choice! Try again [Y/N] : ";
                cin >> choice;
            }
        }
        cout <<endl;
    } while(flag);

    return 0;
}
