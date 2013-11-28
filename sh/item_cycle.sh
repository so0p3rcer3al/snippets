#!/bin/zsh

# Cycle between a list of items, for the purpose of creating
# an animated shell prompt.

# The biggest challenge is finding a way to update the global variable when we're
# in a subshell. In this case, calling 'get_item' produces correct results while
# 'echo "$(get_item)"' does not.
export itmidx=0
get_item() {
	local a len
	a=('a' 'b' 'c' 'd')
	len=${#a}
	echo ${a[((++(itmidx%=len)))]}
}

# A possible solution would be to return an item at random each time.
# but the problem with this approach is that $RANDOM is constant within
# a subshell...
_:rsym() {
	local a n
	a=('★' '☆' '♠' '♡' '♦' '♧')
	n=${#a}
	echo ${a[((RANDOM%n+1))]}
}

# So we'll offload that to shuf. Now this works.
_:rsym2() {
	local a
	a=$(shuf -e ★ ☆ ♠ ♡ ♦ ♧ | tr -d "\n")
	echo ${a:0:1}
}

# But suppose we wanted some sort of pattern..
# We can toggle between different character sets each time.
_:rsym3() {
	$1 && echo ${$(shuf -e a b c d):0:1} || echo ${$(shuf -e A B C D):0:1}
}

for n in {1..10}; do
	# get_item
	echo $(_:rsym3)
done
