while read line; do
		result=$(./push_swap $line | ./checker $line)
		lines=$(./push_swap $line | wc -l)
		ops=$(./push_swap $line | tr '\n' ' ')
		echo "result = $result  | lines = $lines  | ops = $ops | line = $line"
done < push_swap_4_numbers.txt
