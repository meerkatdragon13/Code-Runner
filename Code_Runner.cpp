#include <iostream>
#include <unordered_map>
#include <functional>
using namespace std;

void run_c_code(string filename) {
    string compile_code = "c++ " + filename + " -o temp_file";
    string run_executable = "./temp_file";
    string delete_file = "rm temp_file";

    system(compile_code.c_str());
    system(run_executable.c_str());
    system(delete_file.c_str());
}

void run_javascript_code(string filename) {
    string run_code = "node " + filename;
    system(run_code.c_str());
}

void run_python_code(string filename) {
    string run_code = "python3 " + filename;
    system(run_code.c_str());
}

string get_extension(string filename) {
    int spot = 0;
    string ch;
    string full_word;
    while (true) {
        spot++;
        ch = filename[filename.length() - spot];
        if (ch == ".") {
            break;
        }
        else {
            full_word = ch + full_word;
        }
    }
    return full_word;
}

int main(int argc, char *argv[]) {
    string file_extension = get_extension(argv[1]);
    
    static const unordered_map<string, function<void(const string)>> extension_table = {
        {"cpp", run_c_code},
        {"js", run_javascript_code},
        {"py", run_python_code}
    };

    auto match = extension_table.find(file_extension);

    if (match != extension_table.end()) {
        match->second(argv[1]);
    }
    else {
        cerr << "There was a error: Unsupported file type.\n";
    }
    return 0;
}
