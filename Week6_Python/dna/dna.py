from sys import argv
import csv

# this function will count the largest sequence of all the given samples in a given dna


def counter(samples, values, sequence):
    for key, i in zip(samples, range(0, len(values))):
        count = sequence.count(key)
        while True:
            if sequence.count(key*count) == 1:
                values[i] = count
                break
            elif count > 0:
                count -= 1
            else:
                break
    return


def main():
    if len(argv) != 3:
        print("Usage : python3 dna.py database_address sequence_address")
        return
    with open(argv[1], "r") as database:
        reader = csv.reader(database)
        samples = [x for x in next(reader)[1:]]  # store samples
        # store the largest sequence I could use an dict as well but this is much easier to iterate over
        values = [0 for x in samples]
        with open(argv[2], "r") as sequence:
            line = sequence.readline()
        counter(samples, values, line)
        found = True
        for rows in reader:
            found = True
            for row, value in zip(rows[1:], values):
                if int(row) != value:
                    found = False
                    break
            if found:
                print(rows[0])
                return
        print("No match")


main()
