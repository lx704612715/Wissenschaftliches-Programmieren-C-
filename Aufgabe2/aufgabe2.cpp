#include "mycomplex.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "start.h"
#include <dirent.h>
#include <unistd.h>
#include <string>

int find_dat_file(vector<string> &all_data_file){
    char *path=NULL;
    size_t size;
    path=getcwd(path,size);
    DIR *dir;
    struct dirent *ent;
    string dat_type_1 = "start";
    string dat_type_2 = ".dat";
    if ((dir = opendir (path)) != NULL) {
      while ((ent = readdir (dir)) != NULL) {
        string filename = ent->d_name;
        string::size_type index_1 = filename.find(dat_type_1);
        string::size_type index_2 = filename.find(dat_type_2);
        if (index_1 != string::npos && index_2 != string::npos) {
         all_data_file.push_back(ent->d_name);
        }
      }
      closedir (dir);
    } else {
      // could not open directory
      perror ("");
      return EXIT_FAILURE;
    }
    return 0;
}

using namespace std;
int main()
{
    vector<string> all_data_file;
    //load all dat file
    find_dat_file(all_data_file);
    for (auto i:all_data_file) {
        cout << i <<endl;
    }
    //calculate results
    for (int i = 0; i < all_data_file.size(); ++i) {
        start _start(all_data_file[i]);
        _start.calculation();
    }
    return 0;
}
