class Node:
  def __init__(self, val, nxt = None, prev = None):
    self.val = val
    self.nxt = nxt
    self.prev = prev

n = int(input())
stacks = [Node(-1) for i in range(1001)]

for i in range(n):
  l = input().split()
  op = l[0]
  stack_number = int(l[1])
  if op == 'PUSH':
    val = int(l[2])
    stacks[stack_number].nxt = Node(val, None, stacks[stack_number])
    stacks[stack_number] = stacks[stack_number].nxt
  else:
    print(stacks[stack_number].val)
    stacks[stack_number] = stacks[stack_number].prev
    stacks[stack_number].nxt = None