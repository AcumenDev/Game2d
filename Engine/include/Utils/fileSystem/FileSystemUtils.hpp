#ifndef FILESYSTEMUTILS_H
#define FILESYSTEMUTILS_H

#include <iostream>

using std::string;
namespace FileSystem {

    class Path {
    public:
        static string Combine(string folder, string file) {
            if (folder.back() == '/') {
                return string(folder + file);
            }

            return string(folder + "/" + file);
        }
    };

}

#endif // FILESYSTEMUTILS_H
