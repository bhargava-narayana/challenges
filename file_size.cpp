#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
        if(argc != 2)
        {
                cout<<"usage:"<<argv[0]<<" <filename>"<<endl;
                return EXIT_FAILURE;
        }
        else 
        {
               ifstream input_file(argv[1]);
               if(!input_file.is_open())
               {
                        cout<<"file"<<argv[1]<<" could not be opended"<<endl;
                        return EXIT_FAILURE;
               }

               long begin;
               long end;
               
               begin = input_file.tellg();
               input_file.seekg (0,ios::end);
               end = input_file.tellg();
               input_file.close();

               cout<<"size of the "<<argv[1]<<" is "<< end - begin<<" Bytes"<<endl;

        }
        return EXIT_SUCCESS;
}
