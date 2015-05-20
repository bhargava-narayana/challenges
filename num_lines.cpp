#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
        if(argc != 2)
        {
                cout<<"Invalid syntax.\n usuage: num_lines <file_name>";
                return 1;

        }
        else
        {
                ifstream input_file(argv[1]);
                if(!input_file)
                {
                        cout<<"File "<<argv[1]<<"not found"<<endl;
                        return 0;
                }
                
                char c;
                int line_count = 0;
                while(input_file.get(c))
                {
                        if(c == '\n')
                                line_count++;
                }
                cout<<"total number of lines = "<<line_count<<endl;

                
        }
        return EXIT_SUCCESS;
}
