from expr import decorator



@decorator
def disabled(f):
	"""Replaces f with an empty function."""
	def _f(*args, **kargs):
		pass
	return _f


@decorator
def counted(f):
	"""Counts the number of times f is called."""
	def _f(*args):
		_f.callcount += 1
		f(*args)
	_f.callcount = 0
	return _f

