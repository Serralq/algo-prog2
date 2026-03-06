# Compilation
echo "Compiling..."
bear -- g++ -std=c++17 -Wall -Wextra -O2 src/main.cpp -o binary/main > /dev/null 2>&1
bear --append -- g++ -std=c++17 -Wall -Wextra -O2 src/test-generator.cpp -o binary/test-generator > /dev/null 2>&1

# Per folder in tests/
for test_dir in tests/*/; do

    test_name=$(basename "$test_dir")
    input_file="${test_dir}input.txt"
    test_case_file="${test_dir}test-case.txt"

    echo "Running $test_name..."

    ./binary/test-generator < "$input_file" > "$test_case_file"
    ./binary/main < "$test_case_file"
done
