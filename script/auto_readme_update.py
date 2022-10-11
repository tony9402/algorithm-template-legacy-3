from glob import glob


def convert(text):
    text = [
        word.lower().replace(word[0], word[0].upper(), 1)
        for word in text.split('_')
    ]
    return " ".join(text)


def make_readme():
    files = [(x[4:-4], x) for x in glob('src/**/*.cpp', recursive=True)]
    info = dict()
    for file in files:
        dep = file[0].split('/')
        if dep[0] not in info:
            info[dep[0]] = list()
        info[dep[0]].append((dep[1], file[1]))

    print("# Snippet For VScode\n")
    for key, value in info.items():
        print(f"## {convert(key)}")
        for x, y in value:
            print(f"- [{convert(x)}]({y})")
        print()


if __name__ == "__main__":
    make_readme()
