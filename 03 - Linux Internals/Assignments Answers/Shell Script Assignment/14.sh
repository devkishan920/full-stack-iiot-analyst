#!/bin/bash

# 14. pattern based programs

# right angle
<<pattern
*
**
***
****
pattern

for((i=0; i<4; i++))
do
	for((j=0; j<=$i; j++))
	do
		echo -n "*" # Since in bash, evey echo by default, goes to next line. So, (-n) ensures that cursor don't goes to next line by itself
	done
	
	echo "" # so that, cursor shifts to next line
done

echo ""

# pyramid
<<pattern
    *
   ***
  *****
 *******
pattern

for((i=0; i<4; i++))
do
	for((j=0; j<(4-i); j++))
	do
		echo -n " "
	done

	count=$((2*i + 1))
	
	#while [ $count>0 ];
	#while [ $count -gt 0 ];
	while [ $count -gt 0 ]
	do
		echo -n "*"
		count=$((count-1))
	done

	echo ""

done

echo ""

# Diamond
<<pattern
     *
    ***
   *****
  *******
   *****
    ***
     *
pattern


 for((i=0; i<4; i++))
 do
        for((j=0; j<(4-i); j++))
        do
                 echo -n " "
        done
  
        count=$((2*i + 1))
  
        #while [ $count>0 ];
        #while [ $count -gt 0 ];
        while [ $count -gt 0 ]
        do
                echo -n "*"
                count=$((count-1))
        done

        echo ""

done

for((i=4; i>0; i--))
do
         for((j=0; j<=(4-i+1); j++))
         do
                  echo -n " "
         done
    
         count=$((2*i - 3))
    
         #while [ $count>0 ];
         #while [ $count -gt 0 ];
         while [ $count -gt 0 ]
         do
                 echo -n "*"
                 count=$((count-1))
         done
    
         echo ""
    
done












