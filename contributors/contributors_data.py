from datetime import date
from enum import Enum
from typing import List
from collections import defaultdict

# https://stackoverflow.com/questions/58608361/string-based-enum-in-python

columns = ["nickname", "github", "branch", "languages", "first_commit"]
langs = ["cpp", "py", "js", "java", "ts", "go"]


class Contributor:
    def __init__(
        self,
        nickname: str,
        github: str,
        branch: str,
        langs: List[str],
        first_commit: date,
    ):
        self.nickname = nickname
        self.github = github
        self.branch = branch
        self.langs = langs
        self.first_commit = first_commit

    def join_by(self, delim: str, l: List[str]):
        if l is None:
            return None
        return ", ".join(l)

    def to_list(self):
        return [
            self.nickname,
            self.github,
            self.branch,
            self.join_by(", ", self.langs),
            self.first_commit,
        ]


contributors = []
contributors.append(
    Contributor(
        "any",
        "dataprob",
        "annieli",
        ["py", "js"],
        date(2023, 5, 26),
    )
)
contributors.append(
    Contributor("youssef", "ysaleh03", "youssef", ["cpp"], date(2023, 5, 27))
)
contributors.append(
    Contributor(
        "blank",
        "Person314159",
        "blank",
        ["cpp"],
        date(2023, 5, 27),
    )
)
contributors.append(
    Contributor(
        "Requiem",
        "PhaseRush",
        "phaserush",
        ["py", "java", "ts"],
        date(2023, 5, 28),
    )
)
contributors.append(
    Contributor(
        "eater",
        "william-swy",
        "feature",
        ["cpp"],
        date(2023, 5, 29),
    )
)
contributors.append(
    Contributor(
        "Haad",
        "hbhutta",
        "haad",
        ["cpp"],
        date(2023, 5, 29),
    )
)
contributors.append(
    Contributor(
        "Gordon",
        "Hgjnnf",
        "gordoncheung",
        ["py"],
        date(2023, 6, 2),
    )
)
contributors.append(
    Contributor(
        "Saif",
        "saifabdelazim",
        "darksword",
        ["py"],
        date(2023, 6, 5),
    )
)
contributors.append(
    Contributor(
        "aaryan",
        "aaryan-rampal",
        "aaryan",
        ["java"],
        date(2023, 6, 6),
    )
)
contributors.append(
    Contributor(
        "yimeng",
        "ymnglli",
        "ymnglli",
        ["py"],
        date(2023, 6, 8),
    )
)
contributors.append(
    Contributor(
        "Nothingyet",
        "hquanvo",
        "nothingyet",
        ["cpp"],
        None,
    )
)
contributors.append(
    Contributor(
        "Jason",
        "argonaut0",
        "argonaut0",
        ["go"],
        None,
    )
)
contributors.append(
    Contributor(
        "eric",
        "eysk-io",
        None,
        None,
        None,
    )
)
contributors.append(
    Contributor(
        "Ryan",
        "ryanmckim",
        None,
        None,
        None,
    )
)
contributors.append(
    Contributor(
        "RasPoutine",
        "nopunindented",
        None,
        ["py", "js", "ts"],
        None,
    )
)
contributors.append(
    Contributor(
        "dinosaur",
        "Ccolina03",
        None,
        ["java", "ts"],
        None,
    )
)
contributors.append(
    Contributor(
        "kiara",
        "kcoton",
        None,
        ["py"],
        None,
    )
)

dict_langs = defaultdict(int)
for lang in langs:
    for c in contributors:
        if c.langs is not None and lang in c.langs:
            dict_langs[lang] += 1

dict_langs = {"lang": dict_langs.keys(), "count": dict_langs.values()}

contributors = [c.to_list() for c in contributors]
