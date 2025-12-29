/**
 * @file decoding.h
 * @author Ian Codding II
 * @brief Decoding class for extracting messages from BMP files
 * @version 0.2
 * @date 2025-10-10
 *
 * @copyright Copyright (c) 2025
 */

#ifndef DECODING_H
#define DECODING_H

#include "steganography.h"
#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

using std::cout, std::endl;

/**
 * @class Decoding
 * @brief Inherits from Steganography. Handles decoding messages from BMP files.
 */
class Decoding : public Steganography {
  public:
    Decoding() = default;
    ~Decoding() = default;

    // Reveal hidden message from file
    bool revealMessage(std::fstream &file);

    // Run full decoding process with validation
    bool runDecoding(const std::string &inputFile);

  private:
    // Read message length from BMP header (bytes 6-9)
    uint32_t getMessageLength(std::fstream &file);

    // Extract hidden bits from pixel data and reconstruct message
    std::string decodeMessage(std::fstream &file, uint32_t msgLen);
};

#endif