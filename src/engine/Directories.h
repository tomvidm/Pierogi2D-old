#ifndef DIRECTORIES_H
#define DIRECTORIES_H

#include <string>

namespace engine { namespace directories {
    const std::string relativePathToResources = "../../resources/";
    const std::string scriptsDirectory = relativePathToResources + "scripts/";
    const std::string imagesDirectory = relativePathToResources + "images/";
    const std::string objectsDirectory = relativePathToResources + "objects/";
    const std::string fontsDirectory = relativePathToResources + "fonts/";
}}

#endif