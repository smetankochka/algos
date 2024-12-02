s = input()
lat = "qwertyuiopasdfghjklzxcvbnm"
latbig = "QWERTYUIOPASDFGHJKLZXCVBNM"
c = "0123456789"
spec = "!@#$%^&*()_+=[]{}|:;?/.,"
latbool = False
latbigbool = False
cbool = False
specbool = False
for x in s:
    if x in lat:
        latbool = True
    elif x in latbig:
        latbigbool = True
    elif x in c:
        cbool = True
    elif x in spec:
        specbool = True
if len(s) > 16 and latbigbool and latbool and specbool and cbool:
    print("very strong")
elif len(s) > 14 and latbool and latbigbool and cbool:
    print("strong")
elif len(s) > 10 and cbool and (latbigbool or latbool):
    print("medium")
else:
    print("weak")