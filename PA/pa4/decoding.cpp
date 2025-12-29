/**
 * @file decoding.cpp
 * @author Ian Codding II
 * @brief Implementation of decoding functionality for BMP steganography
 * @version 0.2
 * @date 2025-10-10
 *
 * @copyright Copyright (c) 2025
 */

#include "decoding.h"
#include <iostream>

/**
 * @brief Reads message length from BMP header at offset 6
 *
 * @param file - Input BMP file stream
 * @return uint32_t - Length of hidden message (0 if none)
 */
uint32_t Decoding::getMessageLength(std::fstream &file) {
    file.clear();
    file.seekg(MESSAGE_LENGTH_OFFSET, std::ios::beg);
    uint32_t msgLen = 0;
    file.read(reinterpret_cast<char *>(&msgLen), sizeof(msgLen));
    return msgLen;
}

/**
 * @brief Extracts hidden message from pixel data
 *
 * @param file - Input BMP file stream
 * @param msgLen - Length of message to extract
 * @return std::string - Decoded message
 */
std::string Decoding::decodeMessage(std::fstream &file, uint32_t msgLen) {
    file.clear();
    file.seekg(BMP_HEADER_SIZE, std::ios::beg);

    std::vector<int> bits;
    bits.reserve(msgLen * 8);

    char byte;
    while (file.read(&byte, 1) && bits.size() < msgLen * 8) {
        unsigned char pixelByte = static_cast<unsigned char>(byte);
        bits.push_back(pixelByte & 1);  // Extract LSB
    }

    // Reconstruct message from bits (LSB-first order)
    std::string message;
    for (size_t i = 0; i < bits.size(); i += 8) {
        unsigned char c = 0;
        for (int bit = 0; bit < 8; bit++) {
            c |= (bits[i + bit] << bit);
        }
        message.push_back(static_cast<char>(c));
    }

    return message;
}

/**
 * @brief Reveals hidden message if one exists in the file
 *
 * @param file - Input BMP file stream
 * @return true if message found and displayed, false otherwise
 */
bool Decoding::revealMessage(std::fstream &file) {
    uint32_t msgLen = getMessageLength(file);

    if (msgLen == 0) {
        cout << "No hidden message found in this file.\n";
        return false;
    }

    std::string secret = decodeMessage(file, msgLen);
    cout << "Decoded message: " << secret << endl;
    return true;
}

/**
 * @brief Runs complete decoding process with all validations
 *
 * @param inputFile - Input BMP file path
 * @return true if successful, false otherwise
 */
bool Decoding::runDecoding(const std::string &inputFile) {
    std::fstream file(inputFile, std::ios::in | std::ios::binary);
    if (!file.is_open()) {
        cout << "Error: cannot open input file '" << inputFile << "'.\n";
        return false;
    }

    if (!isBMPFile(file)) {
        cout << "Error: input file is not a valid BMP file.\n";
        file.close();
        return false;
    }

    if (isCompressed(file)) {
        cout << "Error: compressed BMP files are not supported.\n";
        file.close();
        return false;
    }

    bool result = revealMessage(file);
    file.close();
    return result;
}