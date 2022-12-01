#!/bin/bash

createFile=`touch final_ex3_exp.txt`

a=`cat pre_a_ex3_exp.txt`
b=`cat pre_b_ex3_exp.txt`
c=`cat pre_c_ex3_exp.txt`

aFAIL=${a:6:2}
aPASS=${a:15:2}
aNOTCHECK=${a:28:1}

bFAIL=${b:6:2}
bPASS=${b:15:1}
bNOTCHECK=${b:27:1}

cFAIL=${c:6:1}
cPASS=${c:14:2}
cNOTCHECK=${c:27:2}

sumFAIL=$(($aFAIL+$bFAIL+$cFAIL))
sumPASS=$(($aPASS+$bPASS+$cPASS))
sumNOTCHECK=$(($aNOTCHECK+$bNOTCHECK+$cNOTCHECK))

sum1=$(($aFAIL+$aPASS+$aNOTCHECK))
sum2=$(($bFAIL+$bPASS+$bNOTCHECK))
sum3=$(($cFAIL+$cPASS+$cNOTCHECK))

echo "FAIL: $sumFAIL" > final_ex3_exp.txt
echo "PASS: $sumPASS" >> final_ex3_exp.txt
echo "NOTCHECK: $sumNOTCHECK" >> final_ex3_exp.txt
echo "**********" >> final_ex3_exp.txt
echo "SUM1: $sum1" >> final_ex3_exp.txt
echo "SUM2: $sum2" >> final_ex3_exp.txt
echo "SUM3: $sum3" >> final_ex3_exp.txt

