def main():
    p, q = map(int, input().split())
    d = abs(p - q)
    ch = '+'
    chh = '-'
    if p - q < 0:
        p = -p
        q = -q
        print("0-", end='')
        ch, chh = chh, ch

    x = 1
    while x < d:
        x *= 10
    x -= 1

    a = []
    while x:
        if x <= d:
            if d // x > 9:
                a.append((x, d // x // 2))
                a.append((x, d // x - (d // x // 2)))
            else:
                a.append((x, d // x))
            d %= x
        x //= 10

    x, y = 0, 0
    for k, v in a:
        x += ((k + 1) * 2 + 1) * v
        y += v

    if d % 2:
        mul = (9 - d) // 2 + 1
        x += 10 - mul
        y += mul - 1
    else:
        mul = d // 2
        x += mul
        y -= mul

    pal = p - x
    reversed_flag = False
    if pal < 0:
        pal = -pal
        reversed_flag = True

    l = 1
    while l < pal:
        l *= 10
    l -= 1

    b = []
    while l:
        if pal >= l:
            if pal // l > 9:
                b.append((l, pal // l // 2))
                b.append((l, pal // l - (pal // l // 2)))
            else:
                b.append((l, pal // l))
            pal %= l
        l //= 10

    if pal > 0:
        b.append((pal, 1))

    for k, v in a:
        print(f"{(k + 1) * 2 + 1}*{v}{ch}", end='')

    if d % 2:
        print(f"21{chh}2*{mul}{ch}{mul}{chh}11{ch}", end='')
    else:
        print(f"{mul}{chh}0{ch}", end='')

    if reversed_flag:
        print("0" + chh, end='')
        ch, chh = chh, ch

    for k, v in b:
        print(f"{k}*{v}{ch}", end='')

    print("0")
    if p - q < 0:
        print("-0")

if __name__ == "__main__":
    main()
