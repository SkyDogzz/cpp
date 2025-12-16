#!/bin/bash

TEST=(
  "empty_input_text.txt"
  "empty_input_text_2.txt"
  "header_only.txt"
  "header_only2.txt"
  "wrong_header.txt"
  "wrong_header_2.txt"
  "good_header.txt"
  "only_duplicata.txt"
  "wrong_line_format.txt"
  "wrong_line_format_2.txt"
  "wrong_line_format_3.txt"
  "wrong_line_format_4.txt"
  "wrong_line_format_5.txt"
  "wrong_line_format_6.txt"
  "wrong_line_format_7.txt"
  "one_line.txt"
  "wrong_date_format.txt"
  "wrong_date_format_2.txt"
  "wrong_date_format_3.txt"
  "wrong_date_format_4.txt"
  "wrong_date_format_5.txt"
  "wrong_date_format_6.txt"
  "wrong_date_format_7.txt"
  "wrong_date_format_8.txt"
  "big_overflow_float.txt"
  "big_overflow_int.txt"
  "neg_float.txt"
  "neg_int.txt"
  "overflow_float.txt"
  "overflow_int.txt"
  "multiple_errors.txt"
  "many_spaces.txt"
  "many_spaces_2.txt"
  "many_spaces_3.txt"
  "wierd_number.txt"
  "wierd_number_2.txt"
  "wierd_number_3.txt"
  "wierd_date.txt"
)
NB=0
for file in ${TEST[@]}; do
  if [ "$NB" -eq 50 ]; then
    break
  fi
  echo "------------------ Testing with $file ------------------"
  ./bin/bitcoin_exchange inpt/$file
  echo "*"
  ((NB++))
done
