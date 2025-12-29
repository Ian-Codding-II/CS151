/**
 * @file steganography.cpp
 * @author Ian Codding II
 * @brief Base class implementation for BMP file handling
 * @version 0.2
 * @date 2025-10-10
 *
 * @copyright Copyright (c) 2025
 */

#include "steganography.h"

/**
 * @brief Checks if file has BMP magic bytes "BM" at the start
 *
 * @param file - Input file stream
 * @return true if valid BMP file, false otherwise
 */
bool Steganography::isBMPFile(std::fstream &file) const {
    file.clear();
    file.seekg(std::ios::beg);
    char magic[2];
    file.read(magic, 2);

    return (strncmp(magic, "BM", 2) == 0);
}

/**
 * @brief Checks if BMP file is compressed
 *
 * @param file - Input file stream
 * @return true if compressed, false if uncompressed
 */
bool Steganography::isCompressed(std::fstream &file) const {
    file.clear();
    file.seekg(30, std::ios::beg);
    uint32_t compression;
    file.read(reinterpret_cast<char *>(&compression), sizeof(compression));
    return (compression != 0);
}

/**
 * @brief Display usage information
 */
void Steganography::printUsage() {
    cout << "Usage:\n"
         << "  Encoding:\n"
         << "    ./stegoBMP -e -f cover.bmp -o secret.bmp\n"
         << "    ./stegoBMP -e -o secret.bmp -f cover.bmp\n"
         << "    ./stegoBMP -o secret.bmp -e -f cover.bmp\n"
         << "    ./stegoBMP -o secret.bmp -f cover.bmp -e\n"
         << "    ./stegoBMP -f cover.bmp -e -o secret.bmp\n"
         << "    ./stegoBMP -f cover.bmp -o secret.bmp -e\n"
         << "  Decoding:\n"
         << "    ./stegoBMP -d -f secret.bmp\n"
         << "    ./stegoBMP -f secret.bmp -d\n";
}

/**
 * @brief Parse command line arguments for encoding/decoding modes and file names
 *
 * @param argc - Argument count
 * @param argv - Argument values
 * @param encodeMode - Set to true if -e flag found
 * @param decodeMode - Set to true if -d flag found
 * @param inputFile - Set to filename following -f flag
 * @param outputFile - Set to filename following -o flag
 * @return true if valid arguments, false otherwise
 */
bool Steganography::parseArgs(int argc, char *argv[],
                              bool &encodeMode, bool &decodeMode,
                              std::string &inputFile, std::string &outputFile) {
    if (argc < 2) {
        cout << "Error: insufficient arguments.\n";
        printUsage();
        return false;
    }

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        if (arg == "-e") {
            encodeMode = true;
        } else if (arg == "-d") {
            decodeMode = true;
        } else if (arg == "-f") {
            if (i + 1 < argc) {
                inputFile = argv[++i];
            } else {
                cout << "Error: -f flag requires a filename.\n";
                printUsage();
                return false;
            }
        } else if (arg == "-o") {
            if (i + 1 < argc) {
                outputFile = argv[++i];
            } else {
                cout << "Error: -o flag requires a filename.\n";
                printUsage();
                return false;
            }
        } else {
            cout << "Error: unknown flag '" << arg << "'.\n";
            printUsage();
            return false;
        }
    }

    // Validate combinations
    if (encodeMode && decodeMode) {
        cout << "Error: cannot use both -e and -d flags simultaneously.\n";
        printUsage();
        return false;
    }

    if (!encodeMode && !decodeMode) {
        cout << "Error: must specify either -e (encode) or -d (decode).\n";
        printUsage();
        return false;
    }

    if (inputFile.empty()) {
        cout << "Error: -f flag with input file is required.\n";
        printUsage();
        return false;
    }

    if (encodeMode && outputFile.empty()) {
        cout << "Error: -o flag with output file is required for encoding.\n";
        printUsage();
        return false;
    }

    return true;
}