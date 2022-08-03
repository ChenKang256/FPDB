import datetime

split_cnt = 3
days_gap = 2406.0
increment = days_gap / split_cnt

f = open('zoneMap.txt', 'a')

begin_date = datetime.date(1992, 1, 1)
start_date = begin_date
for i in range(0, split_cnt):
    delta = datetime.timedelta(days=int(increment * i))
    end_date = begin_date + delta
    if not i:
        continue
    f.write("{\"min\": " + str((start_date.strftime("%Y%m%d")) + ",\"max\": " + str(end_date.strftime("%Y%m%d")))  + "},\n" )
    start_date = end_date
f.write("{\"min\": " + str((start_date.strftime("%Y%m%d")) + ",\"max\": " + str(datetime.date(1998, 8, 2).strftime("%Y%m%d")))  + "}" )
f.close()