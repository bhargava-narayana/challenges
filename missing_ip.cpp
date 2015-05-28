/* Suppose you were given a file containing roughly one billion Internet Protocol (IP) 
 * addresses, each of which is a 32-bit unsigned integer. How would you 
 * programmatically find an IP address that is not in the file? 
 * Assume you have unlimited drive space but 
 * only two megabytes of RAM at your disposal.
 */ 
#include <iostream>
#include <cstdlib>
#include <cassert>
//#include <cstdbool>
#include <fstream>

int find_missing_element(ifstream *ifs)
{
        vector <size_t> counter(1 <<16, 0);
        unsigned int x;
        
        while(*ifs >> x)
        {
                ++counter[x >> 16];
        }

        for(int i = 0; i <= counter.size(); ++i)
        {
                if(counter[i] < (1 << 16))
                {
                        bitset<(1 << 16)> bit_vec;
                        ifs->clear();
                        ifs->seekg(0, ios:beg);

                        while(*ifs >> x)
                        {
                                if(i == (x >> 16))
                                {
                                        bit_vec.set(((1 << 16) - 1) & x);
                                }
                        }
                

                        ifs.close();

                        for(int j = 0; j < (1<<16); ++j)
                        {
                                if(bit_vec.test(j) == 0)
                                {
                                        return ((1 << 16) | j);
                                }
                        }
                }
        }
}

int main(int argc, char *argv[])
{
        if(argc != 2)
        {
                cerr<<"Usage: %s <file_name>\n"<<argv[0];
                return EXIT_FAILURE;
        }

        else
                find_missing_element(argv[1])
        return EXIT_FAILURE;
}
