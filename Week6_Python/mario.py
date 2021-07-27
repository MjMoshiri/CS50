
while True:
    height = input("Height: ")
    try:
        val = int(height)
    except ValueError:
        pass
    if val < 9 and val > 0:
        break
for i in range(1, val):
    print((val-i)*" "+i*"#"+"  "+i*"#")
