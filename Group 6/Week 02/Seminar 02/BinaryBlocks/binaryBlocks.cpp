#include <iostream>
#include <fstream>
#include <sstream>
#pragma warning(disable: 4996)

struct Block {
    int16_t next;
    uint16_t textLength;
    char text[28]{0};
};

// get count of relevant blocks only, no need to allocate memory for the others
unsigned getNecessaryBlocksCount(std::ifstream& ifs) {
    int initialPos = ifs.tellg();
    ifs.seekg(0, std::ios::beg);

    int16_t next;
    unsigned count = 0;
    while (true) {
        ifs.read((char*)&next, sizeof(next));
        count++;
        if (next == -1) {
            break;
        }
        ifs.seekg(next * sizeof(Block), std::ios::beg);
    }

    ifs.seekg(initialPos, std::ios::beg);
    return count;
}

// here we don't need to pass it as Block*&, because we don't do blocks = ... inside the method
// if we had to initialize blocks = new Block[...]; then we would have to use Block*&
void readBlocks(std::ifstream& ifs, Block* blocks) { 
    int i = 0;
    while (true) {
        ifs.read((char*)&blocks[i], sizeof(Block));
        if (blocks[i].next == -1) {
            return;
        }
        ifs.seekg(blocks[i].next * sizeof(Block), std::ios::beg);
        i++;
    }
}

char* extractMessageFromBlocks(const Block* blocks, unsigned blocksCount) {
    std::stringstream ss("");
    for (unsigned i = 0; i < blocksCount; i++) {
        ss << blocks[i].text;
    }

    // if you need to modify the message additionally, you can play around with the stringstream, before returning the char*

    char* message = new char[strlen(ss.str().c_str()) + 1]; // we need to return a new char array,
                                                            // because c_str() returns a pointer to a temporary string
    strcpy(message, ss.str().c_str());
    return message;
}

int main() {
    std::ifstream ifs("blocks.dat", std::ios::binary);
    if (!ifs.is_open()) {
        std::cerr << "Failed to open file!";
        return -1;
    }

    unsigned blocksCount = getNecessaryBlocksCount(ifs);
    Block* blocks = new Block[blocksCount];
    readBlocks(ifs, blocks);

    char* message = extractMessageFromBlocks(blocks, blocksCount);
    std::cout << message;

    delete[] message; // free up dynamically allocated memory from heap!!!
    delete[] blocks; // free up dynamically allocated memory from heap!!!
}
