#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Error too many or too little arguments." << endl << "Correct argument amounts 2";
        exit(1);
    }

    string filename = argv[1];
    string output_filename = argv[2];

    string compile_code = "c++ " + filename + " -o " + output_filename;
    string run_executable = "./" + output_filename;
    string move_to_folder = "mv " + output_filename + " Output_files/" + output_filename;

    system(compile_code.c_str());
    system(run_executable.c_str());
    system(move_to_folder.c_str());
    return 0;
}

