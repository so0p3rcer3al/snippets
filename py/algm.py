


from fractions import Fraction
def conditional_probability(O, event, given):
	"""Returns P(A|B), the probability of event A given event B."""
	a = b = 0
	for k in filter(given, O):
		if event(k): a += 1
		else: b += 1
	return Fraction(a, b+a)


from collections import Counter
def difference(A, B, res_fmt=''.join):
	"""Given two iterables A,B, returns a tuple (added,removed)
	where both elements are sequences of items that must be
	added/removed from A to obtain B.
	Note that res_fmt can be overriden with 'list', 'set' .etc.
	"""
	Da, Db = Counter(A), Counter(B)
	add = res_fmt((Db - Da).elements())
	rem = res_fmt((Da - Db).elements())
	return (add, rem)


def transpose(A):
	"""Transposes the 2D matrix A."""
	return list(zip(*A))
