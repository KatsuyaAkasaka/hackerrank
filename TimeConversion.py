import sys

def TimeConversion(time_s):
    time =""
    if time_s[-2] == "A":
        if time_s[0:2] =="12":
            time_s = "00" + time_s[2:]
        return time_s.strip("AM")
    else:
        time_s = time_s.strip("PM")
        if time_s[0:2] =="12":
            return time_s    
        i = 0
        while time_s[i] != ":":
            time += time_s[i]
            i += 1
        return time_s.replace(time, str(int(time) + 12))

#s = sys.argv[1]
s = input().strip()
result = TimeConversion(s)
print (result)
