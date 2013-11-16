from expr import decorator



@decorator
def memo(f):
	"""Decorator that caches the return value for each call to f(args).
	Then when called again with same args, we can just look it up.

	If the result is called with unhashable arguments, a TypeError is raised.
	For these input values, memo cannot make the function faster.
	"""
	C = {}
	def _f(*args):
		try:
			return C[args]
		except KeyError:
			res = C[args] = f(*args)
			return res
	_f.cache = C
	return _f


#@decorator   # can't change attributes of builtin methods.
def fastmemo(f):
	"""Memoization decorator for a function taking a single argument.

	This implementation is about 5x faster than memo. However, it has
	a few shortcomings:
	1. The resulting function does not retain the original's attributes
	   (e.g., name or docstring).
	2. The function cannot be multi-argument. A workaround is to pass
	   in a tuple of arguments and expand it as 'f(*arg)'. Note that
	   this is a _very_ inexpensive operation.
	"""
	class mdict(dict):
		def __missing__(self, arg):
			ret = self[arg] = f(arg)
			return ret
	return mdict().__getitem__