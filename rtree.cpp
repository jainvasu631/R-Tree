#include "rtree.h";

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

    
    
    return EXIT_SUCCESS;
}
