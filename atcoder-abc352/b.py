s = input()
t = input()

s_index = 0
t_index = 0

while True:
  if s[s_index] == t[t_index]:
    print(t_index + 1, end = ' ');
    s_index += 1
  t_index += 1

  if t_index == len(t) or s_index == len(s):
    break
