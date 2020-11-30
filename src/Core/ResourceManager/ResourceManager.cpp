/*============================================================================*/
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "ResourceManager.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

ResourceManager::ResourceMap& ResourceManager::Resources() {
    static ResourceMap MAP;
    return MAP;
}

/*----------------------------------------------------------------------------*/

void ResourceManager::load(const std::string_view& filename) {

    if (Resources().count(filename)) {
        return;
    }

    printf("RESOURCE LOADING!!!!\n");

    struct stat fstat = {};
    if (-1 == lstat(filename.data(), &fstat)) {
        perror("lstat");
        exit(1);
    }

    int fd = open(filename.data(), O_RDWR);

    auto* data = new uint8_t[fstat.st_size];

    ssize_t n_read = 0,
            delta = 0;
    while ((delta = read(fd, data + n_read, fstat.st_size - n_read))) {

        if (-1 == delta) {
            perror("read");
            delete[] data;
            close(fd);
            return;
        }

        n_read += delta;
    }

    close(fd);

    Resources()[filename] = Resource{filename, static_cast<size_t>(fstat.st_size), data};
}

/*----------------------------------------------------------------------------*/

const ResourceManager::Resource&
ResourceManager::get(const std::string_view& filename) {

    if (!Resources().count(filename)) {
        load(filename);
    }

    return Resources()[filename];
}

/*----------------------------------------------------------------------------*/

void ResourceManager::forget(const std::string_view& filename) {
    delete[] Resources()[filename].data;
    Resources().erase(filename);
}

/*----------------------------------------------------------------------------*/

void ResourceManager::clear() {
    for (auto& res : Resources()) {
        delete[] res.second.data;
    }
}

/*============================================================================*/