# Some good standards, which are not used if the user
# creates his/her own .bashrc/.bash_profile

# --show-control-chars: help showing Korean or accented characters
alias ls='ls -F --color=auto --show-control-chars'
alias ll='ls -l'

case "$TERM" in
xterm*)
	# The following programs are known to require a Win32 Console
	# for interactive usage, therefore let's launch them through winpty
	# when run inside `mintty`.
	for name in node ipython php php5 psql python2.7 winget
	do
		case "$(type -p "$name".exe 2>/dev/null)" in
		''|/usr/bin/*) continue;;
		esac
		alias $name="winpty $name.exe"
	done
	;;
esac
function run() {
    filename=$1
    g++ -g -O2 -std=gnu++20 -static -o $filename $filename.cpp && ./$filename
}

function gen() {
    filename="gen_test"
    g++ -g -O2 -std=gnu++20 -static -o $filename $filename.cpp && ./$filename
}