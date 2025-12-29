#!/bin/bash
#This script was improved by Walter Neils

# Usage: print_success <message>
print_success() {
    printf "\e[0;32m  [✔] %s\e[0m\n\n" "$1"
}

# Usage: print_error <message>
print_error() {
    printf "\e[0;31m  [✖] %s %s\e[0m\n\n" "$1" "$2"
}

# Usage: print_info <message>
print_info() {
    printf "\e[0;34m  [i] %s\e[0m\n" "$1" 
}
g++ -Wall *.cpp
./a.out > YourProgramOutput
print_info "CorrectOutputLab14 vs. YourProgramOutput"
if [[ $(diff CorrectOutputLab14 YourProgramOutput) ]]; then #if output of diff command is not zero
    print_error "Test failed"
    diff CorrectOutputLab14 YourProgramOutput
else
    print_success "You passed the test"
fi
