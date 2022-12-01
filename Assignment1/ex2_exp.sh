#!/bin/bash

echo "Who are you?"
read input

value1="Hello, I am THE WIND"
value2="Hi, I am THE DEER"
value3="Aloha, I am THE RABBIT"

if   [[ $input = $value1 ]]
then
	echo "Oh guy! Come on!"
elif [[ $input = $value2 ]]
then
	echo "Oh, please show your antler?"
elif [[ $input = $value3 ]]
then 
	echo "Ahihi, please show your ear?"
else
	echo "I am sorry, goodbye!"
fi
