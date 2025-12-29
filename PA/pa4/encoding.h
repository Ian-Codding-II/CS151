
/**
 * @file encoding.h
 * @author Ian Codding II
 * @brief Encoding class for hiding messages in BMP files
 * @version 0.2
 * @date 2025-10-10
 *
 * @copyright Copyright (c) 2025
 */

#ifndef ENCODING_H
#define ENCODING_H

#include "steganography.h"
#include <fstream>
#include <vector>

/**
 * @class Encoding
 * @brief Inherits from Steganography. Handles encoding messages into BMP files.
 */
class Encoding : public Steganography {
  public:
    Encoding() = default;
    ~Encoding() = default;

    // Ask user to enter a message to encode
    bool setMessageToEncode();

    // Get the message that was set
    std::string getMessageToEncode() const;

    // Check if the image has enough space for the message
    bool hasSpaceToEncodeMessage(std::fstream &file, size_t messageBytes, int lsbBits = 1);

    // Write encoded message to output file
    bool writeToFile(std::fstream &file, const std::string &outputBmp);

    // Run full encoding process with validation
    bool runEncoding(const std::string &inputFile, const std::string &outputFile);

  private:
    std::string message;

    // Convert message to bits (LSB-first order)
    std::vector<int> messageToBits(const std::string &message);

    // Encode bits into pixel data and write to output file
    bool encodeMessage(std::fstream &file, std::ofstream &out, const std::vector<int> &bits);
};

#endif