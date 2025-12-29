/**
 * @file steganography.h
 * @author Ian Codding II
 * @brief Steganography base class for common BMP file handling
 * @version 0.2
 * @date 2025-10-10
 *
 * @copyright Copyright (c) 2025
 */

#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using std::cout, std::endl;

/**
 * @class Steganography
 * @brief Base class for encoding and decoding operations on BMP files.
 * Provides common BMP file validation and checks.
 */
class Steganography {
  public:
    Steganography() = default;
    virtual ~Steganography() = default;

    // Check if a given file is a valid BMP file
    bool isBMPFile(std::fstream &file) const;

    // Check if the BMP file is compressed
    bool isCompressed(std::fstream &file) const;

    // Parse command line arguments
    static bool parseArgs(int argc, char *argv[],
                          bool &encodeMode, bool &decodeMode,
                          std::string &inputFile, std::string &outputFile);

  protected:
    // Protected for derived classes to use
    static const uint32_t BMP_HEADER_SIZE = 54;
    static const uint32_t MESSAGE_LENGTH_OFFSET = 6;

    // Helper function to display usage information
    static void printUsage();
};

#endif