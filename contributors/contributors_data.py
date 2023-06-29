from datetime import date
from typing import List
from collections import defaultdict

columns = ["nickname", "github", "languages", "first_commit"]
langs = ["cpp", "py", "js", "java", "ts", "go"]


class Contributor:
    def __init__(
        self,
        nickname: str,
        github: str,
        langs: List[str],
        first_commit: date,
    ):
        self.nickname = nickname
        self.github = github
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
            self.join_by(", ", self.langs),
            self.first_commit,
        ]


contributors = []
contributors.append(
    Contributor(
        "any",
        "dataprob",
        ["py", "js"],
        date(2023, 5, 26),
    )
)
contributors.append(
    Contributor(
        "youssef",
        "ysaleh03",
        ["cpp"],
        date(2023, 5, 27),
    )
)
contributors.append(
    Contributor(
        "blank",
        "Person314159",
        ["cpp"],
        date(2023, 5, 27),
    )
)
contributors.append(
    Contributor(
        "Requiem",
        "PhaseRush",
        ["py", "java", "ts"],
        date(2023, 5, 28),
    )
)
contributors.append(
    Contributor(
        "eater",
        "william-swy",
        ["cpp"],
        date(2023, 5, 29),
    )
)
contributors.append(
    Contributor(
        "Haad",
        "hbhutta",
        ["cpp"],
        date(2023, 5, 29),
    )
)
contributors.append(
    Contributor(
        "Gordon",
        "Hgjnnf",
        ["py"],
        date(2023, 6, 2),
    )
)
contributors.append(
    Contributor(
        "Saif",
        "saifabdelazim",
        ["py"],
        date(2023, 6, 5),
    )
)
contributors.append(
    Contributor(
        "aaryan",
        "aaryan-rampal",
        ["java"],
        date(2023, 6, 6),
    )
)
contributors.append(
    Contributor(
        "yimeng",
        "ymnglli",
        ["py"],
        date(2023, 6, 8),
    )
)
contributors.append(
    Contributor(
        "Nothingyet",
        "hquanvo",
        ["cpp"],
        None,
    )
)
contributors.append(
    Contributor(
        "Jason",
        "argonaut0",
        ["go"],
        date(2023, 6, 15),
    )
)
contributors.append(
    Contributor(
        "eric",
        "eysk-io",
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
    )
)
contributors.append(
    Contributor(
        "RasPoutine",
        "nopunindented",
        ["py", "js", "ts"],
        None,
    )
)
contributors.append(
    Contributor(
        "dinosaur",
        "Ccolina03",
        ["java", "ts"],
        None,
    )
)
contributors.append(
    Contributor(
        "kiara",
        "kcoton",
        ["py"],
        None,
    )
)
contributors.append(
    Contributor(
        "joel",
        "joelbonnie",
        None,
        None,
    )
)
contributors.append(
    Contributor(
        "alex",
        "azalexzhang",
        None,
        None,
    )
)

dict_langs = defaultdict(int)
for lang in langs:
    for c in contributors:
        if c.langs is not None and lang in c.langs:
            dict_langs[lang] += 1

dict_langs = {"language": dict_langs.keys(), "count": dict_langs.values()}

contributors = [c.to_list() for c in contributors]
