


from functools import update_wrapper
def decorator(d):
	"""Make function d a decorator: d wraps a function fn."""
	def _d(fn):
		return update_wrapper(d(fn), fn)
	update_wrapper(_d, d)
	return _d

@decorator
def n_ary(f):
	"""Given binary function f(x, y), return an n_ary function f' such
	that f'(x, y, z) = f(x, f(y,z)), etc.
	"""
	def _f(x, y, *rem):
		if rem:
			return f(x, _f(y, *rem))
		return f(x, y)
	return _f



import itertools
def strproduct(*itrs):
	"""Joins each yielded tuple of itertools.product into a string.
	Returns the result as an iterator.
	"""
	return map(''.join, itertools.product(*itrs))

