from glob import glob


def make_readme():
    files = [x[4:-4] for x in glob('src/**/*.cpp', recursive=True)]
    info = dict()
    for file in files:
        dep = file.split('/')
        if dep[0] not in info:
            info[dep[0]] = list()
        info[dep[0]].append(dep[1])

    print("# Snippet For VScode\n")
    for key, value in info.items():
        print(f"## {Key}")
        for x in value:
            print(f"- {x}")
        print()


if __name__ == "__main__":
    make_readme()
