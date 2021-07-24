import sys
#commands = input().split('\n')

toName = {}
toVal  = {}

for line in sys.stdin:
    line = line.split()
    typ = line.pop(0)

    if typ == "def":
        # get variable name and value
        name = line[0]
        val = int(line[1])

        # if there is already a variable with this name, remove it from both maps
        if name in toVal:
            if toVal[name] in toName:
                toName.pop(toVal[name])
            toVal.pop(name)

        # update toVal dictionary
        toVal[name] = val

        # update toName dictionary
        toName[val] = name

    elif typ == "calc":
        # get variable and operator while operator is not '='
        # look up values to compute calculation
        acc = line[0]
        idx = 0
        found = False
        if acc in toVal:
            found = True
            acc = toVal[acc]
            for idx in range(1, len(line) - 2, 2):
                op = line[idx]
                var = line[idx+1]
                if var in toVal:
                    if op == '+':
                        acc += toVal[var]
                    elif op == '-':
                        acc -= toVal[var]
                else:
                    found = False
                    break
        # try to transform int result into a variable name with the toName dictionary
        # If any name is not found, result becomes "unknown"
        if found:
            result = toName.get(acc, "unknown")
        else:
            result = "unknown"

        # print calculation and result
        print(' '.join(line) + " " + str(result))

    elif typ == "clear":
        toName = {}
        toVal = {}
