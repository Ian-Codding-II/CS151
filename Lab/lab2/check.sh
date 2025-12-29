#!/bin/bash
# This script test if your Lab2 output match the output provided
#Run: 
#   chmod + x ./check.sh
#   ./check.sh
# You should get:
#   [✔] You passed the test
#If you get:
#   [✖] Test failed 
#fix problem and run again:
#   ./check.sh   

# Usage: print_success <message>
print_success() {
    printf "\e[0;32m  [✔] %s\e[0m\n\n" "$1"
}

# Usage: print_error <message>
print_error() {
    printf "\e[0;31m  [✖] %s %s\e[0m\n\n" "$1" "$2"
}
#Compile, treat warning as errors
g++ -Wall -Werror *.cpp -o library
#test exit code of the last command
if [ $? -eq 0 ]; then #if output is not zero
    print_success "You passed the compiler test"
else
    print_error "The compiler test failed"
    exit
fi 

#ignore last two line of output
./library|head -n 93 > output.txt 
output=$(diff output.ANS output.txt | wc -l)
# Adjustment for random numbers on line 17
#The script expect 4 incorect lines in diff output
if [ $output -ne 4 ]; then 
    print_error "The output test failed"
    diff output.ANS output.txt
else
    print_success "You passed the output test"
fi

#clean up
rm output.txt
rm library
