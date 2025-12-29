/**
 * @file encoding.cpp
 * @author Ian Codding II
 * @brief Implementation of encoding functionality for BMP steganography
 * @version 0.2
 * @date 2025-10-10
 *
 * @copyright Copyright (c) 2025
 */

#include "encoding.h"
#include <iostream>

/**
 * @brief Prompts user to enter a message to encode
 *
 * @return true if message successfully retrieved, false on error
 */
bool Encoding::setMessageToEncode() {
    cout << "Enter message to be encoded: ";
    if (!std::getline(std::cin, message)) {
        cout << "Error reading message.\n";
        return false;
    }
    cout << endl;
    return true;
}

/**
 * @brief Returns the message that was set
 *
 * @return std::string - the message to encode
 */
std::string Encoding::getMessageToEncode() const {
    return message;
}

/**
 * @brief Converts message string to bits using LSB-first order
 *
 * @param message - Message to convert
 * @return std::vector<int> - Vector of bits (0 or 1)
 */
std::vector<int> Encoding::messageToBits(const std::string &message) {
    std::vector<int> bits;
    bits.reserve(message.size() * 8);

    for (unsigned char c : message) {
        for (int i = 0; i < 8; i++) {
            bits.push_back((c >> i) & 1);  // LSB-first
        }
    }
    return bits;
}

/**
 * @brief Checks if BMP image has enough capacity for the message
 *
 * @param file - Input BMP file stream
 * @param messageBytes - Size of message in bytes
 * @param lsbBits - Number of LSBs to use per byte (default: 1)
 * @return true if space available, false otherwise
 */
bool Encoding::hasSpaceToEncodeMessage(std::fstream &file, size_t messageBytes, int lsbBits) {
    file.clear();

    int32_t width = 0, height = 0;
    uint16_t colorPlanes = 0, bitsPerPixel = 0;

    file.seekg(18, std::ios::beg);
    file.read(reinterpret_cast<char *>(&width), sizeof(width));
    file.read(reinterpret_cast<char *>(&height), sizeof(height));
    file.read(reinterpret_cast<char *>(&colorPlanes), sizeof(colorPlanes));
    file.read(reinterpret_cast<char *>(&bitsPerPixel), sizeof(bitsPerPixel));

    if (bitsPerPixel != 24) {
        cout << "Error: unsupported bit depth " << bitsPerPixel
             << ". Only 24-bit BMPs are supported.\n";
        return false;
    }

    if (width <= 0 || height == 0) {
        cout << "Error: invalid width/height in BMP header.\n";
        return false;
    }

    uint32_t absHeight = static_cast<uint32_t>(std::abs(height));
    uint64_t usablePixelBytes = static_cast<uint64_t>(width) * 3 * absHeight;
    uint64_t usableBits = usablePixelBytes * static_cast<uint64_t>(lsbBits);
    uint64_t capacityBytes = usableBits / 8;

    if (messageBytes > capacityBytes) {
        cout << "Error: message too large for image.\n"
             << "  Image capacity: " << capacityBytes << " bytes\n"
             << "  Message size: " << messageBytes << " bytes\n";
        return false;
    }

    return true;
}

/**
 * @brief Encodes message bits into pixel data LSBs
 *
 * @param file - Input BMP file stream
 * @param out - Output file stream to write to
 * @param bits - Vector of bits to encode
 * @return true if successful, false otherwise
 */
bool Encoding::encodeMessage(std::fstream &file, std::ofstream &out, const std::vector<int> &bits) {
    file.clear();
    file.seekg(BMP_HEADER_SIZE, std::ios::beg);

    size_t bitIndex = 0;
    char byte;

    while (file.read(&byte, 1)) {
        if (bitIndex < bits.size()) {
            unsigned char pixelByte = static_cast<unsigned char>(byte);
            pixelByte = (pixelByte & 0xFE) | bits[bitIndex++];
            byte = static_cast<char>(pixelByte);
        }

        if (!out.write(&byte, 1)) {
            cout << "Error: failed to write to output file.\n";
            return false;
        }
    }

    return true;
}

/**
 * @brief Writes encoded message to output BMP file
 *
 * @param file - Input BMP file stream
 * @param outputBmp - Output filename
 * @return true if successful, false otherwise
 */
bool Encoding::writeToFile(std::fstream &file, const std::string &outputBmp) {
    std::ofstream out(outputBmp, std::ios::binary);
    if (!out.is_open()) {
        cout << "Error: cannot open output file '" << outputBmp << "'.\n";
        return false;
    }

    file.clear();
    file.seekg(std::ios::beg);

    // Read and modify header
    std::vector<char> header(BMP_HEADER_SIZE);
    for (size_t i = 0; i < header.size(); i++) {
        file.read(&header[i], 1);
    }

    // Store message length at offset 6
    uint32_t msgLen = static_cast<uint32_t>(message.size());
    std::memcpy(&header[MESSAGE_LENGTH_OFFSET], &msgLen, sizeof(msgLen));

    // Write modified header
    for (size_t i = 0; i < header.size(); i++) {
        out.write(&header[i], 1);
    }

    // Encode and write message
    std::vector<int> bits = messageToBits(message);
    if (!encodeMessage(file, out, bits)) {
        out.close();
        return false;
    }

    out.close();
    return true;
}

/**
 * @brief Runs complete encoding process with all validations
 *
 * @param inputFile - Input BMP file path
 * @param outputFile - Output BMP file path
 * @return true if successful, false otherwise
 */
bool Encoding::runEncoding(const std::string &inputFile, const std::string &outputFile) {
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

    if (!setMessageToEncode()) {
        file.close();
        return false;
    }

    if (!hasSpaceToEncodeMessage(file, message.size())) {
        file.close();
        return false;
    }

    if (!writeToFile(file, outputFile)) {
        file.close();
        return false;
    }

    cout << "Success: message encoded into '" << outputFile << "'.\n";
    file.close();
    return true;
}