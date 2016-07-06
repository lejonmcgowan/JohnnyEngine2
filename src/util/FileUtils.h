//
// Created by lejonmcgowan on 1/9/16.
//

#ifndef OGLSIMPLEENGINE_FILEUTILS_H
#define OGLSIMPLEENGINE_FILEUTILS_H

#include <iostream>
#include <fstream>
#include <sstream>

namespace FileUtils
{
    //get root path in VS
#ifdef _MSC_VER
    //TODO: figure something out for getting the current root in VS
#else //get root path in a Unix System
    //TODO: find more elegant method to retrieve directory
    //TODO: see if I can turn this into header only interface and remove dummy FileUtils.cpp
#endif

    /**
     * reads in the file given by @filePath and returns the source of it.
     */
    static std::string readProjectRelativeFile(const char *filePath)
    {

        std::string result;
        std::ifstream fileSource;
        std::stringstream stringstream;

        //current way to generate path on UNIX: take __FILE__
        std::string fullPath = __FILE__;
        //take out actual file name to get current directory
        fullPath = fullPath.substr(0, fullPath.rfind("/") + 1);
        //and move up to known project root
        fullPath += "../../";
        fullPath += filePath;
        fileSource.open(fullPath);
        if (fileSource.is_open())
        {
            stringstream << fileSource.rdbuf();
            result = stringstream.str();
        }
        else
        {
            std::cout << "Warning: " << filePath << " Not found" << std::endl;
            std::cout << "calculated full path: " << fullPath << std::endl;
        }
        return result;
    }

    /**
     * overloaded method for a string filePath as opposed to a char* one
     */
    static std::string readProjectRelativeFile(const std::string &filePath)
    {
        std::string result;
        std::ifstream fileSource;
        std::stringstream stringstream;

        //current way to generate path on UNIX: take __FILE__
        std::string fullPath = __FILE__;
        //take out actual file name to get current directory
        fullPath = fullPath.substr(0, fullPath.rfind("/") + 1);
        //and move up to known project root
        fullPath += "../../";
        fullPath += filePath;
        fileSource.open(fullPath);
        if (fileSource.is_open())
        {
            stringstream << fileSource.rdbuf();
            result = stringstream.str();
        }
        else
        {
            std::cout << "Warning: " << filePath << " Not found" << std::endl;
            std::cout << "calculated full path: " << fullPath << std::endl;
        }
        return result;
    }

    static std::string getFullPath(std::string relativePath)
    {

        //current way to generate path on UNIX: take __FILE__
        std::string fullPath = __FILE__;
        if (relativePath.find(fullPath.substr(0, fullPath.rfind("/") + 1)) == std::string::npos)
        {
            //take out actual file name to get current directory
            fullPath = fullPath.substr(0, fullPath.rfind("/") + 1);
            //and move up to known project root
            fullPath += "../../";
            fullPath += relativePath;
        }
            //if it's already a full path, do not change
        else
            fullPath = relativePath;
        return fullPath;
    }

    static std::string getFullPath(const char *relativePath)
    {
        return getFullPath(std::string(relativePath));
    }

}; //namespace FileUtils

#endif //OGLSIMPLEENGINE_FILEUTILS_H
