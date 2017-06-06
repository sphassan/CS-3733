def make_generator():
   a = 0
   b = 1
   def fun ():
      nonlocal a , b
      next = a + b
      a = b
      b = next
      return a
   return fun

generator = make_generator()

for i in range(5): print(generator())
