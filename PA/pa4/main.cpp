/**
 * @file main.cpp
 * @author Ian Codding II
 * @brief Steganography, the practice of concealing a file, message,
 *       image, or video within another file, message, image, or video.
 * @version 0.2
 * @date 2025-10-10
 *
 * @copyright Copyright (c) 2025
 */

#include "encoding.h"
#include "decoding.h"
#include <string>

int main(int argc, char *argv[]) {
    bool encodeMode = false, decodeMode = false;
    std::string inputFile, outputFile;

    // Parse command line arguments
    if (!Steganography::parseArgs(argc, argv, encodeMode, decodeMode, inputFile, outputFile)) {
        return 1;
    }

    // Create appropriate handler based on mode
    if (encodeMode) {
        Encoding encoder;
        return encoder.runEncoding(inputFile, outputFile) ? 0 : 1;
    } else {
        Decoding decoder;
        return decoder.runDecoding(inputFile) ? 0 : 1;
    }
}