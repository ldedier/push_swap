# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    analyser.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroulin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/26 18:08:32 by aroulin           #+#    #+#              #
#    Updated: 2019/02/01 20:24:04 by ldedier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

##
##		Need to have ./checker and ./push_swap
##
##		first request is the range of number with the smallest and biggest
##
##		second request is total loops that the program will perfom
##
##		third request is for know how many loops are above and below

if [ -z "$1" ]
then
	./correc.sh "small"
	./correc.sh "medium"
	./correc.sh "big"
	./correc.sh "huge"
	exit 1
elif [ $1 == "small" ]
then
	NBR=3
	TRY=5
	MED=3
elif [ $1 == "medium" ]
then
	NBR=5
	TRY=5
	MED=12
elif [ $1 == "big" ]
then
	NBR=100
	TRY=5
	MED=700
elif [ $1 == "huge" ]
then
	NBR=500
	TRY=5
	MED=5300
else
	echo "$1 is not a supported test"
	exit 1;
fi

echo "\x1B[36m";
echo "\n--- [ ANALYSING PUSH_SWAP] ---";
echo "\x1B[0m";

#read -p "How many values : " NBR
#read -p "How many loop : " TRY
##read -p "Mediane for test : " MED
((NBR++))
MOY=0;
MAX=-1;
MIN=-1;
ACTMAX="";
ACTMIN="";
MORE=0;
LESS=0;
IND=$TRY;
WELL=0;
TEST="";

printf "[ NBR == $NBR && TRY == $TRY && MED == $MED ]\n"

echo "Analyse in progress ...\n\n";
while [ $IND -gt 0 ];
do
	ARG=`ruby -e "puts (0..$NBR).to_a.shuffle.join(' ')"`
	NBRCOUP=$(./push_swap $ARG | wc -l);
	TEST=$(./push_swap $ARG | ./checker $ARG);
	if [ "$TEST" = "OK" ]
	then
		printf "\033[0;32m▓\033[0;0m"
		WELL=$(( $WELL + 1 ));
	elif [ "$TEST" = "Error" ]
	then
		printf "\033[0;31m▓\033[0;0m"
	fi;

	if [ $MAX -lt $NBRCOUP ]
	then 
		MAX=$NBRCOUP; 
		ACTMAX=$ARG; 
	fi;
	if [ $MIN -eq "-1" ];
	then 
		MIN=$NBRCOUP; 
		ACTMIN=$ARG; 
	fi;
	if [ $NBRCOUP -lt $MIN ]
	then MIN=$NBRCOUP; 
		ACTMIN=$ARG; 
	fi;
	MOY=$(( $MOY + $NBRCOUP ));
	IND=$(( $IND - 1 ));
	if [ $NBRCOUP -gt $MED ]
	then 
		((MORE++))
	else
		((LESS++))
	fi;
done;
MOY=$(( $MOY / $TRY ));
echo "\nThere is \x1b[33m$WELL/$TRY\x1b[0m correct answer"
echo "There is \x1B[31m$MORE\x1b[0m more than $MED"
echo "There is \x1B[32m$LESS\x1b[0m less than $MED"
echo "The biggest  is :\x1B[31m$MAX\x1b[0m"
echo "The average is :\t\x1b[33m$MOY\x1b[0m"
echo "The smallest is :\x1B[32m$MIN\x1b[0m"
#echo "The worst list :\t$ACTMAX"
#echo "The best list :\t\t$ACTMIN"
