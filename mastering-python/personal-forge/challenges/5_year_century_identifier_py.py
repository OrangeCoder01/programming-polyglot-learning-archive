def century(year):
    return (year + 99) // 100
# integer division concept
# year = 1780 then 1879 then divide and approximate to nearest 2 digits: 18.79 then 18

year = int(input("Please, enter the year: "))
print(f"It is in the {century(year)}th")

