#!/bin/bash

# 定义一个泛型函数，带有类型检查
generic_function() {
    local input="$1"
	local expected_type="$2"
			    
	# 检查参数类型
	if [[ "$expected_type" == "string" && ! -z "$input" ]]; then
	    echo "Generic Function (String): $input"
    elif [[ "$expected_type" == "integer" && "$input" =~ ^[0-9]+$ ]]; then
	    echo "Generic Function (Integer): $input"
	else
	    echo "Invalid Input: $input (Expected: $expected_type)"
	fi
}
