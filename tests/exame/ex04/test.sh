#!/usr/bin/env bash

gcc -Wall -Wextra -Werror microshell.c utils.c -o microshell

leack="" #set `valgrind` for leack check

declare -a cmds=(
"$leack ./microshell /bin/ls"
"$leack ./microshell /bin/cat microshell.c '|' /bin/grep '//'"
"$leack ./microshell /bin/ls -l microshell.c"
"$leack ./microshell /bin/ls salut"
"$leack ./microshell ';'"
"$leack ./microshell ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';'"
"$leack ./microshell ';' ';' /bin/echo OK"
"$leack ./microshell ';' ';' /bin/echo OK ';'"
"$leack ./microshell ';' ';' /bin/echo OK ';' ';'"
"$leack ./microshell ';' ';' /bin/echo -n OK ';' ';' ';' /bin/echo OK"
"$leack ./microshell /bin/ls '|' /bin/grep microshell"
"$leack ./microshell /bin/ls '|' /bin/grep microshell '|' /bin/grep micro"
"$leack ./microshell /bin/ls '|' /bin/grep microshell '|' /bin/grep micro '|' /bin/grep shell '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro"
"$leack ./microshell /bin/ls '|' /bin/grep microshell '|' /bin/grep micro '|' /bin/grep shell '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep micro '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell '|' /bin/grep shell"
"$leack ./microshell /bin/ls ewqew '|' /bin/grep micro '|' /bin/cat -n ';' /bin/echo dernier ';' /bin/echo"
"$leack ./microshell /bin/ls '|' /bin/grep micro '|' /bin/cat -n ';' /bin/echo dernier ';' /bin/echo ftest ';'"
"$leack ./microshell /bin/echo ftest ';' /bin/echo ftewerwerwerst ';' /bin/echo werwerwer ';' /bin/echo qweqweqweqew ';' /bin/echo qwewqeqrtregrfyukui ';'"
"$leack ./microshell /bin/ls ftest ';' /bin/ls ';' /bin/ls werwer ';' /bin/ls microshell.c ';' /bin/ls subject.fr.txt ';'"
"$leack ./microshell /bin/ls '|' /bin/grep micro ';' /bin/ls '|' /bin/grep micro ';' /bin/ls '|' /bin/grep micro ';' /bin/ls '|' /bin/grep micro ';'"
"$leack ./microshell /bin/cat reserv_microsh.c '|' /bin/grep a '|' /bin/grep b ';' /bin/cat reserv_microsh.c ';'"
"$leack ./microshell /bin/cat reserv_microsh.c '|' /bin/grep a '|' /bin/grep w ';' /bin/cat reserv_microsh.c ';'"
"$leack ./microshell /bin/cat reserv_microsh.c '|' /bin/grep a '|' /bin/grep w ';' /bin/cat reserv_microsh.c"
"$leack ./microshell /bin/cat reserv_microsh.c ';' /bin/cat reserv_microsh.c '|' /bin/grep a '|' /bin/grep b '|' /bin/grep z ';' /bin/cat reserv_microsh.c"
"$leack ./microshell ';' /bin/cat reserv_microsh.c ';' /bin/cat reserv_microsh.c '|' /bin/grep a '|' /bin/grep b '|' /bin/grep z ';' /bin/cat reserv_microsh.c"
"$leack ./microshell blah '|' /bin/echo OK"
"$leack ./microshell blah '|' /bin/echo OK ';'"
"$leack ./microshell ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' blah '|' /bin/echo OK ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';' ';'"\
)

n=6
j=1
for (( i = 0; i < ${#cmds[@]} ; i++ )); do
	printf "\n================| test: $j, test str num: $n ==================\n"
	printf "cmd: ${cmds[$i]}\n\n"
	eval "${cmds[$i]}"
	j=$((j+1))
	n=$((n+1))
done

rm microshell
