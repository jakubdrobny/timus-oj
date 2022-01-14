class Matrix:
  def __init__(self, mod, o = 0):
    self.mod = mod
    self.mat = [[0 for j in range(2)] for i in range(2)]
    if o:
      self.mat[0][0] = self.mat[1][1] = 1
  def mul(self, other):
    res = Matrix(self.mod)
    for i in range(2):
      for j in range(2):
        res.mat[i][j] = 0
        for k in range(2):
          res.mat[i][j] += (self.mat[i][k] * other.mat[k][j]) % self.mod
          res.mat[i][j] %= self.mod
    return res

def binpow(mat, pw, mod):
  res = Matrix(mod, 1)
  while pw:
    if pw & 1:
      res = res.mul(mat)
    pw >>= 1
    mat = mat.mul(mat)
  return res


n = int(input())
k = int(input())
m = int(input())

a = Matrix(m)
a.mat = [[k - 1, k - 1], [1, 0]]
b = Matrix(m)
b.mat = [[k - 1, 0], [0, 0]]

a = binpow(a, n - 1, m)
a = a.mul(b)
print((a.mat[0][0] + a.mat[1][0]) % m)