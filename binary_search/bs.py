def binarySearch(v, value):
  result = { "found": False, "index": 0 }
  i = 0
  f = len(v) - 1

  while (f - i > 1):
    m = int((i + f) / 2)

    if (value == v[m]):
      result["found"] = True
      result["index"] = m
      break

    if (value > v[m]): i = m
    if (value < v[m]): f = m

  if (False == result["found"]):
    if (value == v[i]):
      result["found"] = True
      result["index"] = i

    if (value == v[f]):
      result["found"] = True
      result["index"] = f

  return result

value = int(input())
v = [int(x) for x in input().split()]

result = binarySearch(v, value)
if (True == result["found"]):
  print("Se encontro el valor en la posicion", result["index"], sep=' ')
else: 
  print("No se encontro el valor en la lista")


