#include <iostream>
using namespace std;

void run_c_code(string filename) {
    string compile_code = "c++ " + filename + " -o temp_file";
    string run_executable = "./temp_file";
    string delete_file = "rm temp_file";

    system(compile_code.c_str());
    system(run_executable.c_str());
    system(delete_file.c_str());
}
void run_js_code(string filename) {
    string run_code = "node " + filename;
    system(run_code.c_str());
}

int main(int argc, char *argv[]) {
    string filetype = string(argv[2]);

    if (filetype == "c") {
        run_c_code(argv[1]);
    }
    else if (filetype == "j") {
        run_js_code(argv[1]);
    }
    else {
        cerr << "There was a error.";
        exit(1);
    }
    return 0;
}
