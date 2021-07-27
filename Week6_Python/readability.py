text = input("Text: ")
# this function calculates the words ,letters and sentences in paragraph


def calculator(text):
    letters = sentences = 0
    words = 1
    for char in text:
        if char.isalpha():
            letters += 1
        elif char == " ":
            words += 1
        elif char == "." or char == "?" or char == "!":
            sentences += 1
    return letters, words, sentences

# this function grades the paragraph


def grader(letters, words, sentences):
    return 0.0588 * (letters / words) * 100 - 0.296 * (sentences / words) * 100 - 15.8


def printer(result):
    if (result < 1):
        print("Before Grade 1")
    elif (result >= 16):
        print("Grade 16+")
    else:
        print(f"Grade {round(result)}")


cli = calculator(text)  # cli stands for Coleman-Liau index
printer(grader(cli[0], cli[1], cli[2]))
