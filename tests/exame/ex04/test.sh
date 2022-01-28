gcc microshell.c utils.c -o microshell -Wall -Wextra -Werror
i=7
j=1
leack="" #set valgrind for leack check

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell /bin/ls

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell /bin/cat microshell.c "|" /bin/grep "//"

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell /bin/ls microshell.c

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell /bin/ls salut

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell ";"

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";"

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell ";" ";" /bin/echo OK

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell ";" ";" /bin/echo OK ";"

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell ";" ";" /bin/echo OK ";" ";"

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell ";" ";" /bin/echo -n OK ";" ";" ";" /bin/echo ", OK"

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell /bin/ls "|" /bin/grep microshell

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell /bin/ls "|" /bin/grep microshell "|" /bin/grep micro

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell /bin/ls "|" /bin/grep microshell "|" /bin/grep micro "|" /bin/grep shell "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell /bin/ls "|" /bin/grep microshell "|" /bin/grep micro "|" /bin/grep shell "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep micro "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell "|" /bin/grep shell

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell /bin/ls ewqew "|" /bin/grep micro "|" /bin/cat -n ";" /bin/echo dernier ";" /bin/echo

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell /bin/ls "|" /bin/grep micro "|" /bin/cat -n ";" /bin/echo dernier ";" /bin/echo ftest ";"

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell /bin/echo ftest ";" /bin/echo ftewerwerwerst ";" /bin/echo werwerwer ";" /bin/echo qweqweqweqew ";" /bin/echo qwewqeqrtregrfyukui ";"

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell /bin/ls ftest ";" /bin/ls ";" /bin/ls werwer ";" /bin/ls microshell.c ";" /bin/ls subject.fr.txt ";"

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell /bin/ls "|" /bin/grep micro ";" /bin/ls "|" /bin/grep micro ";" /bin/ls "|" /bin/grep micro ";" /bin/ls "|" /bin/grep micro ";"

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell /bin/cat reserv_microsh.c "|" /bin/grep a "|" /bin/grep b ";" /bin/cat reserv_microsh.c ";"

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell /bin/cat reserv_microsh.c "|" /bin/grep a "|" /bin/grep w ";" /bin/cat reserv_microsh.c ";"

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell /bin/cat reserv_microsh.c "|" /bin/grep a "|" /bin/grep w ";" /bin/cat reserv_microsh.c

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell /bin/cat reserv_microsh.c ";" /bin/cat reserv_microsh.c "|" /bin/grep a "|" /bin/grep b "|" /bin/grep z ";" /bin/cat reserv_microsh.c

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell ";" /bin/cat reserv_microsh.c ";" /bin/cat reserv_microsh.c "|" /bin/grep a "|" /bin/grep b "|" /bin/grep z ";" /bin/cat reserv_microsh.c

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell blah "|" /bin/echo OK

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell blah "|" /bin/echo OK ";"

echo "\n=================| test: $j, test str num: $i ===================\n"; j=$((j+1)) i=$((i+3))
$leack ./microshell ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" blah "|" /bin/echo OK ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";"

rm microshell
