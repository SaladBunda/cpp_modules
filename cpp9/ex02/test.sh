make 
clear

#FOR MAC
# ./PmergeMe $(jot -r 8000 1 10000000) 

#FOR LINUX
# $(shuf -i 1-3276800 -n 3000)

# rm -rf *.txt

# Define test sizes
TEST_SIZES=(3) #
 # NUMBERS=$(shuf -i 0-32768000 -n "$size" | tr "\n" " ")

CLEAN_OUTPUT=true
# Run tests
for size in "${TEST_SIZES[@]}"; do
    echo "================================= Test $size ========================================="
    OUTPUT_FILE="test$size.txt"
    > "$OUTPUT_FILE"  # Clear previous output
    IS_SUCCESS=1
    for ((i=1; i<=50; i++)); do
        NUMBERS=$(jot -r "$size" 1 10000000 | tr "\n" " ")
        ./PmergeMe $NUMBERS #  > /dev/null 2>&1
        if [ $? -eq 0 ]; then
            echo "Test $i: OK" >> "$OUTPUT_FILE"
        else
            echo "Test $i: KO" >> "$OUTPUT_FILE"
            IS_SUCCESS=0
        fi
    done
    if [ $IS_SUCCESS -eq 0 ]; then
        echo "Result: ❌"
    else
        echo "Result: ✅"
    fi
done

if [ $CLEAN_OUTPUT == true ]; then
    echo "Cleanning.."
    # make fclean 1>/dev/null
    # rm -rf *.txt
fi