#include "rtree.h"

using namespace std;

int main(int argc, char const *argv[])
{
    if(argc < 5)
        return EXIT_FAILURE; // IF Number of Arguments is less than 5 we have a problem
    
    // Process Command Line Arguments
    string query_filename = argv[1]; // First Argument is Query Files
    MAX_CAP = atoi(argv[2]); // Second Argument is maxCap
    DIMENSION = atoi(argv[3]); // Third Argument is Number of Dimension d
    string output_filename = argv[4]; // Fourth Argument is output filename

    fstream query_file, output_file;
    query_file.open(query_filename,ios::in); // Input File to fetch commands
    query_file.open(output_filename,ios::out); // Output File to write output

    string line;
    
    // Query Processing Loop
    while (getline(query_file, line)){
        istringstream iss(line);
        string command_word; 
        iss >> command_word;
        Command command = string_to_command(command_word); // Enum Version of Command Word
        
        // Depending on what command is we process it
        switch (command){
            case Command::Bulkload:
                /* code */
                break;
            case Command::Insert:
                /* code */
                break;
            case Command::Query:
                /* code */
                break;
            
            default: // Error Case
                break;
        }
    }    

    return EXIT_SUCCESS;
}
