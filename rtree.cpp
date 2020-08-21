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
    output_file.open(output_filename,ios::out); // Output File to write output

    string line;
    const string newlines = "\n\n\n"; // To be outputteed after every command result
    // Query Processing Loop
    while (getline(query_file, line)){
        istringstream iss(line);
        string command_word; 
        iss >> command_word;
        Command command = string_to_command(command_word); // Enum Version of Command Word
        
        // Depending on what command is we process it
        if(command == Command::Bulkload){
            string sorted_filename;
            int num_points;
            iss >> sorted_filename >> num_points;
            // Do Bulkload 
            output_file << command_word << newlines;
        } else if(command == Command::Insert){
            Point point(DIMENSION);
            for (auto &&coordinate : point){
                iss >> coordinate;
            }
            // Do Insert    
            output_file << command_word << newlines;
        } else if(command == Command::Query){
            Point point(DIMENSION);
            for (auto &&coordinate : point){
                iss >> coordinate;
            }
            // Do Query
            bool success;
            string result = success? "TRUE" : "FALSE";
            output_file << success << newlines;
        } else {
            // Throw Wrong Command Errors
        }
        
    }    

    return EXIT_SUCCESS;
}
