# Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/2702
# Tags: Implementation
# Statuts: Accepted

aa, ab, ap = input().split(" ")
ra, rb, rp = input().split(" ")
aa = int(aa)
ab = int(ab)
ap = int(ap)
ra = int(ra)
rb = int(rb)
rp = int(rp)

count = 0

if (aa < ra):
    count += ra - aa
if (ab < rb):
    count += rb - ab
if (ap < rp):
    count += rp - ap
print(count)
