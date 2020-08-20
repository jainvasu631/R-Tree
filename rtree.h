#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "file_manager.h"
#include "errors.h"

using namespace std;

// Type Aliases 
using ID = int;
using Point = vector<int>;
using MaximumBoundingRegion = pair<Point,Point>;
using NodeInfo = pair<ID,MaximumBoundingRegion>;
using Children = vector<NodeInfo>;

// Global Constants (CAPITALIZED)
int INT_SIZE = sizeof(int);
int MAX_CAP;
int DIMENSION;


class Node {
    private:
        ID id;
        ID parent_id;
        MaximumBoundingRegion mbr;
        Children children;
        bool is_leaf;


    public:
        // Node Specific Constants
        static const int ROOT_PARENT_ID = -1;
        static const int LEAF_CHILD_ID = -1;

        
        Node(ID id_, vector<MaximumBoundingRegion> child_mbrs, bool is_leaf_=false): id(id_), parent_id(ROOT_PARENT_ID), is_leaf(is_leaf_) {

        }
};

enum Command {Bulkload, Insert, Query, Error}; // 3 Commands which will be in Query File and one Error Command

Command string_to_command(string command){
    if (command == "BULKLOAD")
        return Command::Bulkload;
    else if (command == "INSERT")
        return Command::Insert;
    else if (command == "QUERY")
        return Command::Query;
    else
        return Command::Error;
}
