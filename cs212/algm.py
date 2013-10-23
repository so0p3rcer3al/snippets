


from fractions import Fraction
def conditional_probability(O, event, given):
	"""Returns P(A|B), the probability of event A given event B."""
	a = b = 0
	for k in filter(given, O):
		if event(k): a += 1
		else: b += 1
	return Fraction(a, b+a)